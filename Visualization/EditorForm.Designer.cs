using System.Drawing;
using System.Windows.Forms;

namespace Visualization
{
	internal partial class EditorForm
	{   
		public const int HeightOfPanel = 1000;
		public const int WightOfPanel = 1600;
		
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Освободить все используемые ресурсы.
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
		
		private void InitializeComponent()
		{
			this.panel = new System.Windows.Forms.Panel();
			this.SuspendLayout();
			// 
			// panel
			// 
			this.panel.BackColor = System.Drawing.Color.LavenderBlush;
			this.panel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.panel.Location = new System.Drawing.Point(12, 48);
			this.panel.Name = "panel";
			this.panel.Size = new System.Drawing.Size(WightOfPanel, HeightOfPanel);
			this.panel.TabIndex = 0;
			// 
			// EditorForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.DarkRed;
			this.ClientSize = new System.Drawing.Size(WightOfPanel + 30, HeightOfPanel + 60);
			this.Controls.Add(this.panel);
			this.DoubleBuffered = true;
			this.Name = "EditorForm";
			this.Text = "?????";
			this.ResumeLayout(false);
		}

		private Panel panel;
		public BufferedGraphics buffGraph;
		private BufferedGraphicsContext gContext = BufferedGraphicsManager.Current;
	}
}