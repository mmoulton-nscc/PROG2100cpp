using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AsteroidField
{
    public partial class AsteroidField : Form
    {

        /*
         * ASTEROID FIELD
         * An arcade game where you play as a spaceship flying around an asteroid field.
         * Press left and right to rotate, and Up to thrust forwards. You will continue to move in that direction until you thrust in the opposite direction or brake with down.
         * Shoot with spacebar to destroy asteroids and increase your score!
         */

        /*
         * DOUBLE BUFFERING
         * Uses a second buffer so that reading and writing of data can be done separately instead of by a single buffer.
         * What this means for our game is that one buffer can render a new frame while another buffer is displaying the previously completed frame to the screen.
         * This increases the smoothness of the animation because with a single buffer, when the buffer begins to render a new frame it starts from scratch.
         * Meaning the screen will appear to flicker while the new frame is rendered.
         */

        /*
         * GDI+ (or Graphics Device Interface +)
         * The subsystem of Windows XP responsible for displaying info on screens and printers.
         * The successor to GDI, it optimizes the capabilities of GDI and provides additional features.
         * GDI+ allows programmers to display information to a screen or printer without knowing what the end device specs are. 
         */


        //properties
        Player player;
        private int asteroidMax = 15;

        private int score = 0;

        private bool gameOver = false;
        private bool continueable = false;

        private MciPlayer shoot = new MciPlayer("sounds/laserShoot.wav", "1");
        private MciPlayer explode = new MciPlayer("sounds/explosion.wav", "2");

        //declare field of asteroids
        HashSet<Asteroid> astfield = new HashSet<Asteroid>();

        //declare pool of bullets
        HashSet<Bullet> bulletPool = new HashSet<Bullet>();


        public AsteroidField()
        {
            InitializeComponent();
        }

        private void AsteroidField_Load(object sender, EventArgs e)
        {
            //this.WindowState = FormWindowState.Maximized;
         
            //instantiate Player
            player = new Player(this.DisplayRectangle);

        }

        private void AsteroidField_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            { 
                case Keys.Space:
                    {
                        if (!gameOver)
                        {
                            SpawnBullet();
                            shoot.PlayFromStart();
                        }
                        break;
                    }
                case Keys.Left:
                    {
                        player.Rotate(Player.Rotation.Counterclockwise);
                        break;
                    }
                case Keys.Right:
                    {
                        player.Rotate(Player.Rotation.Clockwise);
                        break;
                    }
                case Keys.Up:
                    {
                        player.ApplyThrust();
                        break;
                    }
                case Keys.Down:
                    {
                        player.Brakes();
                        break;
                    }
                case Keys.Escape:
                    {
                        Application.Exit();
                        break;
                    }
                case Keys.R:
                    {
                        Application.Restart();
                        break;
                    }
                case Keys.Enter:
                    {
                        if (gameOver && continueable)
                        {
                            txtScore.Text = "Score: " + (score);
                            gameOver = false;
                        }
                        break;
                    }

            }
        }

        private void AsteroidField_KeyUp(object sender, KeyEventArgs e)
        {

        }

        private void AsteroidField_Paint(object sender, PaintEventArgs e)
        {
            Graphics graphics = e.Graphics;
            if (!gameOver)
            {
                player.Draw(graphics);
            }
            foreach (var asteroid in astfield)
            {
                asteroid.Draw(graphics);
                
            }
            foreach (var bullet in bulletPool)
            {
                bullet.Draw(graphics);
            }
        }

        private void SpawnBullet()
        {
            bulletPool.Add(new Bullet(this.DisplayRectangle, player.getRect(), player.getXvel(), player.getYvel(), player.getRot()));
        }



        private void MainGameTimerEvent(object sender, EventArgs e)
        {
            foreach (var ast in astfield)
            {
                CheckCollision(ast);
                ast.Move();
            }

            foreach (var bullet in bulletPool)
            {
                bullet.Move();
            }

            player.Move();

            astfield.RemoveWhere(DestroyAsteroids);
            bulletPool.RemoveWhere(DestroyBullets);

            Invalidate();
        }

        private void AsteroidSpawnTimer_Tick(object sender, EventArgs e)
        {
            if (astfield.Count < asteroidMax && !gameOver)
            {
                astfield.Add(new Asteroid(this.DisplayRectangle, astfield.Count));
            }
        }

        private void CheckCollision(Asteroid asteroid)
        {
            if (asteroid.displayRect.IntersectsWith(player.getRect()))
            {
                explode.PlayFromStart();
                GameOver();
            }

            foreach (var bullet in bulletPool)
            {
                if (asteroid.displayRect.IntersectsWith(bullet.getRect()))
                {
                    asteroid.destroyObject();
                    bullet.destroyObject();
                    explode.PlayFromStart();
                    score += 5;
                    txtScore.Text = "Score: " + (score);
                }
            }

            if (score == 100 && !continueable)
            {
                GameWin();
            }
        }

        private bool DestroyAsteroids(Asteroid ast)
        {
            return ast.destroy;
        }

        private bool DestroyBullets(Bullet bullet)
        {
            return bullet.destroy;
        }

        private void GameOver()
        {
            gameOver = true;
            continueable = false;
            foreach (var bullet in bulletPool)
            {
                bullet.destroyObject();
            }

            foreach (var asteroid in astfield)
            {
                asteroid.destroyObject();
            }

            txtScore.Text = "Final Score: " + (score) + "\nPress R to replay!";
        }

        private void GameWin()
        {
            gameOver = true;
            continueable = true;
            foreach (var bullet in bulletPool)
            {
                bullet.destroyObject();
            }

            foreach (var asteroid in astfield)
            {
                asteroid.destroyObject();
            }

            txtScore.Text = "YOU WIN!\nScore: " + (score) + "\nPress ENTER to continue or R to replay!";
        }
    }
}
