using System.Drawing;
using System.Windows.Forms;

namespace Visualization
{
	internal partial class EditorForm : Form
	{
		private const int Indenting = 100;
		
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.Draw = new System.Windows.Forms.Button();
			this.zedGraph = new ZedGraph.ZedGraphControl ();
			this.SuspendLayout();
			//
			// zedGraph
			//
			this.zedGraph.Dock = System.Windows.Forms.DockStyle.Fill;
			this.zedGraph.Location = new System.Drawing.Point (Indenting, Indenting);
			this.zedGraph.Name = "zedGraph";
			this.zedGraph.ScrollGrace = 0;
			this.zedGraph.ScrollMaxX = 0;
			this.zedGraph.ScrollMaxY = 0;
			this.zedGraph.ScrollMaxY2 = 0;
			this.zedGraph.ScrollMinX = 0;
			this.zedGraph.ScrollMinY = 0;
			this.zedGraph.ScrollMinY2 = 0;
			/*
			this.zedGraph.Size = new System.Drawing.Size(SystemInformation.PrimaryMonitorSize.Width - 2 * Indenting,
				SystemInformation.PrimaryMonitorSize.Height - 2 * Indenting);
			*/
			this.zedGraph.TabIndex = 0;
			
			// 
			// Draw
			// 
			this.Draw.BackColor = System.Drawing.Color.LightBlue;
			//this.Draw.ForeColor = System.Drawing.Color.Black;
			this.Draw.Location = new System.Drawing.Point(10, 10);
			this.Draw.Name = "Draw";
			this.Draw.Size = new System.Drawing.Size(75, 23);
			this.Draw.TabIndex = 4;
			this.Draw.Text = "Draw";
			this.Draw.UseVisualStyleBackColor = false;
			this.Draw.Click += new System.EventHandler(this.Draw_Click);
			// 
			// EditorForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.White;
			//this.ClientSize = new System.Drawing.Size(500, 500);
			this.DoubleBuffered = true;
			this.Name = "EditorForm";
			this.Text = "Visualization";
			this.Controls.Add(Draw);
			this.Controls.Add (this.zedGraph);
			this.WindowState = FormWindowState.Maximized;
			this.ResumeLayout(false);
		}

		private System.Windows.Forms.Button Draw;
		private ZedGraph.ZedGraphControl zedGraph;
	}
}