using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AsteroidField
{
    internal class Asteroid
    {
        private Rectangle displayRect;

        public Asteroid(Rectangle canvas)
        {
            this.displayRect = canvas;
        }

        internal void Move()
        {
            //throw new NotImplementedException();
        }
    }
}
