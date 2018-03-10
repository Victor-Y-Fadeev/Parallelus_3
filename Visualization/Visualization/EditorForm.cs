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
			StartDrawing();
		}

		private void StartDrawing()
		{
			var drawer = new Drawer(zedGraph);
			
			PointPairList list = new PointPairList ();
			
			double xmin = -50;
			double xmax = 50;

			// Заполняем список точек
			for (double x = xmin; x <= xmax; x += 0.01)
			{
				// добавим в список точку
				list.Add (x, f(x));
			}
			drawer.DrawGraph(list, "pisya");
		}
		
		private double f (double x)
		{
			if (x == 0)
			{
				return 1;
			}

			return Math.Sin (x) / x;
		}

	}
}