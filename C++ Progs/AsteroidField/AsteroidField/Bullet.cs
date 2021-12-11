using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AsteroidField
{
    internal class Bullet
    {
        //properties
        private Rectangle Canvas;
        private readonly int width = 3;
        private readonly int height = 3;
        private readonly int speed = 10;
        private int xVelocity = 0;
        private int yVelocity = 0;
        private int rotation = 0;
        private int lifetime = 0;
        public bool destroy = false;

        private Rectangle displayRect;

        public Bullet(Rectangle canvas, Rectangle spawnLocation, int xvel, int yvel, int rot)
        {
            this.Canvas = canvas;
            xVelocity = xvel;
            yVelocity = yvel;
            rotation = rot;
            displayRect = new Rectangle(spawnLocation.X+7, spawnLocation.Y+10, width, height);
            AddThrust();
        }

        internal void Move()
        {
            //horizontal movement
            this.displayRect.X += xVelocity;

            //wraps player around screen to other side if they go off screen
            if (this.displayRect.X > 3 + this.Canvas.Width)
            {
                this.displayRect.X = -2;
            }
            if (this.displayRect.X < -3)
            {
                this.displayRect.X = 2 + this.Canvas.Width;
            }

            //vertical movement
            this.displayRect.Y += yVelocity;

            //wraps player around screen to other side if they go off screen
            if (this.displayRect.Y > 3 + this.Canvas.Height)
            {
                this.displayRect.Y = -2;
            }
            if (this.displayRect.Y < -3)
            {
                this.displayRect.Y = 2 + this.Canvas.Height;
            }
        }
        internal void AddThrust()
        {
            switch (rotation)
            {
                case int n when (n <= 15):
                    {
                        yVelocity -= speed;
                        break;
                    }
                case int n when (n <= 30 && n > 15):
                    {
                        yVelocity -= (int)(speed * 0.8);
                        xVelocity += (int)(speed * 0.2);
                        break;
                    }
                case int n when (n <= 45 && n > 30):
                    {
                        yVelocity -= (int)(speed * 0.6);
                        xVelocity += (int)(speed * 0.4);
                        break;
                    }
                case int n when (n <= 60 && n > 45):
                    {
                        yVelocity -= (int)(speed * 0.4);
                        xVelocity += (int)(speed * 0.6);

                        break;
                    }
                case int n when (n <= 75 && n > 60):
                    {
                        yVelocity -= (int)(speed * 0.2);
                        xVelocity += (int)(speed * 0.8);

                        break;
                    }
                case int n when (n <= 90 && n > 75):
                    {
                        xVelocity += speed;
                        break;
                    }
                case int n when (n <= 105 && n > 90):
                    {
                        xVelocity += speed;

                        break;
                    }
                case int n when (n <= 120 && n > 105):
                    {
                        yVelocity += (int)(speed * 0.2);
                        xVelocity += (int)(speed * 0.8);

                        break;
                    }
                case int n when (n <= 135 && n > 120):
                    {
                        yVelocity += (int)(speed * 0.4);
                        xVelocity += (int)(speed * 0.6);

                        break;
                    }
                case int n when (n <= 150 && n > 135):
                    {
                        yVelocity += (int)(speed * 0.6);
                        xVelocity += (int)(speed * 0.4);

                        break;
                    }
                case int n when (n <= 165 && n > 150):
                    {
                        yVelocity += (int)(speed * 0.8);
                        xVelocity += (int)(speed * 0.2);

                        break;
                    }
                case int n when (n <= 180 && n > 165):
                    {
                        yVelocity += speed;
                        break;
                    }
                case int n when (n <= 195 && n > 180):
                    {
                        yVelocity += speed;
                        break;
                    }
                case int n when (n <= 210 && n > 195):
                    {
                        yVelocity += (int)(speed * 0.8);
                        xVelocity -= (int)(speed * 0.2);

                        break;
                    }
                case int n when (n <= 225 && n > 210):
                    {
                        yVelocity += (int)(speed * 0.6);
                        xVelocity -= (int)(speed * 0.4);

                        break;
                    }
                case int n when (n <= 240 && n > 225):
                    {
                        yVelocity += (int)(speed * 0.4);
                        xVelocity -= (int)(speed * 0.6);

                        break;
                    }
                case int n when (n <= 255 && n > 240):
                    {
                        yVelocity += (int)(speed * 0.2);
                        xVelocity -= (int)(speed * 0.8);

                        break;
                    }
                case int n when (n <= 270 && n > 255):
                    {
                        xVelocity -= speed;
                        break;
                    }
                case int n when (n <= 285 && n > 270):
                    {
                        xVelocity -= speed;
                        break;
                    }
                case int n when (n <= 300 && n > 285):
                    {
                        yVelocity -= (int)(speed * 0.2);
                        xVelocity -= (int)(speed * 0.8);

                        break;
                    }
                case int n when (n <= 315 && n > 300):
                    {
                        yVelocity -= (int)(speed * 0.4);
                        xVelocity -= (int)(speed * 0.6);

                        break;
                    }
                case int n when (n <= 330 && n > 315):
                    {
                        yVelocity -= (int)(speed * 0.6);
                        xVelocity -= (int)(speed * 0.4);

                        break;
                    }
                case int n when (n <= 345 && n > 330):
                    {
                        yVelocity -= (int)(speed * 0.8);
                        xVelocity -= (int)(speed * 0.2);

                        break;
                    }
                case int n when (n <= 360 && n > 345):
                    {
                        yVelocity -= speed;

                        break;
                    }

            }

        }

        internal void destroyObject()
        {
            this.destroy = true;
        }

        public Rectangle getRect()
        {
            return this.displayRect;
        }
        internal void Draw(Graphics graphics)
        {
            graphics.FillRectangle(Brushes.White, displayRect);
        }
    }
}
