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
			Start();
		}

		private void Start()
		{
			var diff = new DifferentialEquationSystem(-10.0, 2.7, 0.4, -437.5, 0.003);
			var drawer = new Drawer(zedGraph);
			drawer.DrawEquation(diff);
		}
	}
}