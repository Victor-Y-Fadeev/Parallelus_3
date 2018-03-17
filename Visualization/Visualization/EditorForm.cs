using System;
using ZedGraph;
using System.Drawing;
using System.Windows.Forms;

namespace Visualization
{
	internal partial class EditorForm : Form
	{
		public EditorForm()
		{
			InitializeComponent();
		}

		private void FileNewItem_Click(object sender, EventArgs e)
		{
		}

		private void FileExitItem_Click(object sender, EventArgs e)
		{
			Application.Exit();
		}

		private void RunRunItem_Click(object sender, EventArgs e)
		{
		}

		private void HelpRunExampleItem_Click(object sender, EventArgs e)
		{
			var drawer = new Drawer(zedGraph);
			drawer.DrawExample();
		}

		private void HelpAboutItem_Click(object sender, EventArgs e)
		{
		}
	}
}