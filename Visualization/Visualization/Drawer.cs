using System;
using System.Drawing;
using ZedGraph;

namespace Visualization
{
	internal class Drawer
	{
		private readonly ZedGraphControl _zedGraph;

		public Drawer(ZedGraphControl zedGraph)
		{
			_zedGraph = zedGraph;
		}

		private GraphPane GraphicInit()
		{
			GraphPane pane = _zedGraph.GraphPane;
			pane.XAxis.MajorGrid.IsVisible = true;
			pane.YAxis.MajorGrid.IsVisible = true;
			return pane;
		}

		private void DrawGraph(PointPairList list, string graphName, string title)
		{
			var pane = GraphicInit();
			pane.Title.Text = title;
			Random rand = new Random();
			LineItem myCurve = pane.AddCurve(graphName, list,
				Color.FromArgb(10 + rand.Next(245), 10 + rand.Next(245), 10 + rand.Next(245), 10 + rand.Next(245)),
				SymbolType.None);
			_zedGraph.AxisChange();
			_zedGraph.Invalidate();
		}

		public void DrawEquation(DiffEqSystem diff, double x0, double y0)
		{
			DrawGraph(diff.GetPointPairList(0.0001, 9000), "(" + x0 + "," + y0 + ")", "");
		}

		public void DrawExample()
		{
			var diff = new DiffEqSystem(-10.0, 2.7, 0.4, -437.5, 0.003);
			var vector = "a = -10.0, b = 2.7, c = 0.4, alpha = -437.5, beta = 0.003";
			for (var i = 1; i < 20; i++)
			{
				diff.SetNewInitialData(-1.4 + i * 0.6, 0);
				var x = -1.4 + i * 0.6;
				DrawGraph(diff.GetPointPairList(0.0001, 90000), "(" + x + ",0)", vector);
			}
		}
	}
}