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
        //properties
        Player player;
        private int asteroidMax = 15;

        private int score = 0;

        private bool gameOver = false;
        private bool continueable = false;

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
                GameOver();
            }

            foreach (var bullet in bulletPool)
            {
                if (asteroid.displayRect.IntersectsWith(bullet.getRect()))
                {
                    asteroid.destroyObject();
                    bullet.destroyObject();

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
