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
        private Rectangle canvas;

        public Bullet(Rectangle canvas)
        {
            this.canvas = canvas;
        }

        internal void Move()
        {
            //throw new NotImplementedException();
        }
    }
}
