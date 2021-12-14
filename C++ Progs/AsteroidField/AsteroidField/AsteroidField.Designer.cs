using System;

namespace AsteroidField
{
    partial class AsteroidField
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.txtScore = new System.Windows.Forms.Label();
            this.GameTimer = new System.Windows.Forms.Timer(this.components);
            this.AsteroidSpawnTimer = new System.Windows.Forms.Timer(this.components);
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.markMoultonToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.w0440932ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtScore
            // 
            this.txtScore.AutoSize = true;
            this.txtScore.Font = new System.Drawing.Font("Roboto Mono", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtScore.ForeColor = System.Drawing.Color.AliceBlue;
            this.txtScore.Location = new System.Drawing.Point(486, 0);
            this.txtScore.Name = "txtScore";
            this.txtScore.Size = new System.Drawing.Size(116, 28);
            this.txtScore.TabIndex = 0;
            this.txtScore.Text = "Score: 0";
            // 
            // GameTimer
            // 
            this.GameTimer.Enabled = true;
            this.GameTimer.Interval = 40;
            this.GameTimer.Tick += new System.EventHandler(this.MainGameTimerEvent);
            // 
            // AsteroidSpawnTimer
            // 
            this.AsteroidSpawnTimer.Enabled = true;
            this.AsteroidSpawnTimer.Interval = 1000;
            this.AsteroidSpawnTimer.Tick += new System.EventHandler(this.AsteroidSpawnTimer_Tick);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1117, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.markMoultonToolStripMenuItem,
            this.w0440932ToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // markMoultonToolStripMenuItem
            // 
            this.markMoultonToolStripMenuItem.Name = "markMoultonToolStripMenuItem";
            this.markMoultonToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.markMoultonToolStripMenuItem.Text = "Mark Moulton";
            // 
            // w0440932ToolStripMenuItem
            // 
            this.w0440932ToolStripMenuItem.Name = "w0440932ToolStripMenuItem";
            this.w0440932ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.w0440932ToolStripMenuItem.Text = "W0440932";
            // 
            // AsteroidField
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(1117, 817);
            this.Controls.Add(this.txtScore);
            this.Controls.Add(this.menuStrip1);
            this.DoubleBuffered = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "AsteroidField";
            this.Text = "Asteroid Field";
            this.Load += new System.EventHandler(this.AsteroidField_Load);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.AsteroidField_Paint);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.AsteroidField_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.AsteroidField_KeyUp);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }



        #endregion

        private System.Windows.Forms.Label txtScore;
        private System.Windows.Forms.Timer GameTimer;
        private System.Windows.Forms.Timer AsteroidSpawnTimer;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem markMoultonToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem w0440932ToolStripMenuItem;
    }
}

