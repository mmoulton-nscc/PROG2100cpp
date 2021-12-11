using System;
using System.Collections.Generic;
using System.Drawing;

using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AsteroidField
{
    internal class Player
    {
        //properties
        private Rectangle Canvas;
        private readonly int width = 15;
        private readonly int height = 20;

        private readonly int speed = 10;
        private readonly int rotationSpeed = 15; //15 degrees per tick

        private int xVelocity = 0;
        private int yVelocity = 0;
        private int rotation = 0;

        private Rectangle displayRect;
        private Image image;
        public enum Rotation {Clockwise, Counterclockwise }

        

        //constructor
        public Player(Rectangle canvas)
        {
            this.Canvas = canvas;
            image = Image.FromFile("images/player.bmp");
            int posX = canvas.Width/2 - width/2;
            int posY = canvas.Height/2 - height/2;


            displayRect = new Rectangle(posX, posY, width, height);
        }

        internal void Draw(Graphics graphics)
        {
            graphics.DrawImage(image, displayRect);
        }

        internal void Rotate(Rotation rotate)
        {
            switch (rotate)
            {
                 case Rotation.Clockwise:
                    {
                        rotation += rotationSpeed;
                        image = RotateImage(image, rotationSpeed);
                        if (rotation >= 360)
                        {
                            rotation = 0;
                            image = Image.FromFile("images/player.bmp"); //continued rotation shrinks and darkens image, so refresh to original image after rotating so much
                        }
                        break;
                    }
                 case Rotation.Counterclockwise:
                    {
                        rotation -= rotationSpeed;

                        image = RotateImage(image, -rotationSpeed);
                        if (rotation <= 0)
                        {
                            rotation = 360;
                            image = Image.FromFile("images/player.bmp"); //continued rotation shrinks and darkens image, so refresh to original image after rotating so much
                        }
                        break;
                    }
            }
        }

        internal void ApplyThrust()
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
                        yVelocity -= (int) (speed * 0.8);
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

        internal void Brakes()
        {
            xVelocity = 0;
            yVelocity = 0;
        }

        internal void Shoot()
        {
        }

        internal void Move()
        {
            //horizontal movement
            this.displayRect.X += xVelocity;

            //wraps player around screen to other side if they go off screen
            if (this.displayRect.X > 5 + this.Canvas.Width)
            {
                this.displayRect.X = -4;
            }
            if (this.displayRect.X < -5)
            {
                this.displayRect.X = 4 + this.Canvas.Width;
            }

            //vertical movement
            this.displayRect.Y += yVelocity;

            //wraps player around screen to other side if they go off screen
            if (this.displayRect.Y > 5 + this.Canvas.Height)
            {
                this.displayRect.Y = -4;
            }
            if (this.displayRect.Y < -5)
            {
                this.displayRect.Y = 4 + this.Canvas.Height;
            }
        }



        //https://stackoverflow.com/questions/2163829/how-do-i-rotate-a-picture-in-winforms
        internal static Image RotateImage(Image img, float rotationAngle)
        {
            //create an empty Bitmap image
            Bitmap bmp = new Bitmap(img.Width, img.Height);
            //bmp.SetResolution(img.HorizontalResolution, img.VerticalResolution);

            //turn the Bitmap into a Graphics object
            Graphics gfx = Graphics.FromImage(bmp);

            //now we set the rotation point to the center of our image
            gfx.TranslateTransform((float)bmp.Width / 2, (float)bmp.Height / 2);

            //now rotate the image
            gfx.RotateTransform(rotationAngle);

            gfx.TranslateTransform(-(float)bmp.Width / 2, -(float)bmp.Height / 2);

            //set the InterpolationMode to HighQualityBicubic so to ensure a high
            //quality image once it is transformed to the specified size
            gfx.InterpolationMode = InterpolationMode.HighQualityBicubic;

            //now draw our new image onto the graphics object
            gfx.DrawImage(img, new Point(0, 0));

            //dispose of our Graphics object
            gfx.Dispose();

            //return the image
            return bmp;
        }
    }
}
