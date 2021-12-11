using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AsteroidField
{
    internal class Asteroid
    {
        //properties
        private Rectangle Canvas;
        private readonly int width = 60;
        private readonly int height = 60;

        private readonly int maxSpeed = 5;

        private int xVelocity = 0;
        private int yVelocity = 0;
        private int rotation = 0;

        private bool mini = false;


        private Rectangle displayRect;
        private Image image;

        public Asteroid(Rectangle canvas, int num)
        {
            this.Canvas = canvas;
            image = Image.FromFile("images/asteroid.bmp");

            Random random = new Random();

            int posX = 0;
            int posY = 0;
            //alternate between spawning 
            if (num % 2 == 0)
            {
                posX = random.Next(-59, canvas.Width + 60);
                posY = -59;
            }
            else
            {
                posX = -59;
                posY = random.Next(-59, canvas.Height + 60);
            }

            while (xVelocity == 0)
            {
                xVelocity = random.Next(-maxSpeed, maxSpeed);
            }
            while (yVelocity == 0)
            {
                yVelocity = random.Next(-maxSpeed, maxSpeed);
            }
            rotation = random.Next(1, 360);
            image = RotateImage(image, rotation);
            
            displayRect = new Rectangle(posX, posY, width, height);
        }

        internal void Draw(Graphics graphics)
        {
            graphics.DrawImage(image, displayRect);
        }

        internal void Move()
        {
            this.displayRect.X += xVelocity;
            if (this.displayRect.X > 60 + this.Canvas.Width)
            {
                this.displayRect.X = -59;
            }
            if (this.displayRect.X < -60)
            {
                this.displayRect.X = 59 + this.Canvas.Width;
            }

            this.displayRect.Y += yVelocity;
            if (this.displayRect.Y > 60 + this.Canvas.Height)
            {
                this.displayRect.Y = -59;
            }
            if (this.displayRect.Y < -60)
            {
                this.displayRect.Y = 59 + this.Canvas.Height;
            }

        }

        //https://stackoverflow.com/questions/2163829/how-do-i-rotate-a-picture-in-winforms
        internal static Image RotateImage(Image img, float rotationAngle)
        {
            //create an empty Bitmap image
            Bitmap bmp = new Bitmap(img.Width, img.Height);
            bmp.SetResolution(img.HorizontalResolution, img.VerticalResolution);

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
