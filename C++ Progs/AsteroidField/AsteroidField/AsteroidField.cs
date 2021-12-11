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

        //declare field of asteroids
        HashSet<Asteroid> astfield = new HashSet<Asteroid>();

        //declare pool of reusable bullet objects (avoids unnecessary garbage collection and new instantiation)
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

            //populate astfield
            astfield.Add(new Asteroid(this.DisplayRectangle));
        }

        private void AsteroidField_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Space:
                    {
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
            }
        }

        private void AsteroidField_KeyUp(object sender, KeyEventArgs e)
        {

        }

        private void AsteroidField_Paint(object sender, PaintEventArgs e)
        {
            Graphics graphics = e.Graphics;
            player.Draw(graphics);
        }

        private void MainGameTimerEvent(object sender, EventArgs e)
        {
            foreach (var ast in astfield)
            {
                ast.Move();
            }

            foreach (var bullet in bulletPool)
            {
                bullet.Move();
            }

            player.Move();

            Invalidate();
        }
    }
}
