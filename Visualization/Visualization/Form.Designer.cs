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
			this.zedGraph.TabIndex = 0;
			
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
			this.Controls.Add (this.zedGraph);
			this.WindowState = FormWindowState.Maximized;
			this.ResumeLayout(false);
		}

		private ZedGraph.ZedGraphControl zedGraph;
	}
}