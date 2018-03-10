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

		public void DrawGraph(PointPairList list, string graphName)
		{
			var pane = GraphicInit();
			LineItem myCurve = pane.AddCurve (graphName, list, Color.Blue, SymbolType.None);
			_zedGraph.AxisChange ();
			_zedGraph.Invalidate ();
		}
	}
}