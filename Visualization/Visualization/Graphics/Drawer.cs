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

		private void DrawGraph(PointPairList points, ArrowObj arrow, string graphName, string title)
		{
			var pane = GraphicInit();
			pane.Title.Text = title;
			Random rand = new Random();
			LineItem myCurve = pane.AddCurve(graphName, points,
				Color.FromArgb(10 + rand.Next(245), 10 + rand.Next(245), 10 + rand.Next(245), 10 + rand.Next(245)),
				SymbolType.None);
			pane.GraphObjList.Add(arrow);
			_zedGraph.AxisChange();
			_zedGraph.Invalidate();
		}
		
		private void DrawGraph(PointPairList points, string graphName, string title)
		{
			var pane = GraphicInit();
			pane.Title.Text = title;
			Random rand = new Random();
			LineItem myCurve = pane.AddCurve(graphName, points,
				Color.FromArgb(10 + rand.Next(245), 10 + rand.Next(245), 10 + rand.Next(245), 10 + rand.Next(245)),
				SymbolType.None);
			_zedGraph.AxisChange();
			_zedGraph.Invalidate();
		}

		public void DrawEquation(DiffEqSystem diff, double x0, double y0)
		{
			DrawGraph(diff.GetResult(0.0001, 9000).GraphicPounts, new ArrowObj(), "(" + x0 + "," + y0 + ")", "");
		}

		public void DrawExample()
		{
			
			var diff = new DiffEqSystem(-10.0, 2.7, 0.4, -437.5, 0.003);
			const string title = "a = -10.0, b = 2.7, c = 0.4, alpha = -437.5, beta = 0.003";
			var x0 = -1.4;
			var y0 = 0;
			for (var i = 3; i < 20; i++)
			{
				var x1 = -1.4 + i * 0.6;
				const int y1 = 0;
				diff.SetNewInitialData(x1, y1);
				var x = -1.4 + i * 0.6;
				var result = diff.GetResult(0.00001, 900000);
				var arrow = result.IsToRight ? new ArrowObj(x0, y0, x1, y1) : new ArrowObj(x1, y1, x0, y0);
				DrawGraph(result.GraphicPounts, arrow, "(" + x + ",0)", title);
				x0 = x1;
				y0 = y1;
			}
			/*
			var diff = new DiffEqSystem(-10.0, 2.7, 0.4, -437.5, 0.003);
			const string title = "a = -10.0, b = 2.7, c = 0.4, alpha = -437.5, beta = 0.003";
			diff.SetNewInitialData(0,0);
			var result = diff.GetResult(0.00001, 90000);
			DrawGraph(result.GraphicPounts, new ArrowObj(), "(" + 0 + ",0)", title);
			*/
		}

		public void DrawExampleStabilityCycles()
		{
			var diff = new DiffEqSystem(-10.0, 2.7, 0.4, -437.5, 0.003);
			var cycles = diff.FindStabilityCycles(new PointPair(0.1, 0), 10);
			DrawGraph(cycles.UnStable[0], "111", "lol");
		}
	}
}