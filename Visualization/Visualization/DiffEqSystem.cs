using ZedGraph;

namespace Visualization
{
	internal class DiffEqSystem
	{
		private Vector _vector;
		private InitialData _initialData;
		private CurrentPoints _currentPoints;

		public DiffEqSystem(double a, double b, double c, double alpha, double beta)
		{
			_vector = new Vector(a, b, c, alpha, beta);
		}

		public Result GetResult(double h, int quantityOfPoints)
		{
			var x = _initialData.X;
			var y = _initialData.Y;
			var list = new PointPairList {new PointPair(x, y)};
			var needCheck = true;
			var yLast = y;
			var counter = 0;
			var isToRight = true;
			
			if (yLast == 0)
			{
				counter = -1;
			}
			for (var i = 0; i < quantityOfPoints; i++)
			{
				list.Add(NextPoint(x, y, h));
				x = _currentPoints.X;
				y = _currentPoints.Y;
				if (needCheck)
				{
					if (y < 0 && yLast >= 0)
					{
						yLast = y;
						counter++;
					}
					else if (y > 0 && yLast <= 0)
					{
						yLast = y;
						counter++;
					}

					if (counter == 2)
					{
						needCheck = false;
						isToRight = x > _initialData.X;
					}
				}
			}

			var result = new Result(list, isToRight);
			return result;
		}

		private PointPair NextPoint(double x, double y, double h)
		{
			var k11 = h * Fi(x, y);
			var k21 = h * Psi(x, y);

			var k12 = h * Fi(x + k11 / 2, y + k21 / 2);
			var k22 = h * Psi(x + k11 / 2, y + k21 / 2);

			var k13 = h * Fi(x + k12 / 2, y + k22 / 2);
			var k23 = h * Psi(x + k12 / 2, y + k22 / 2);

			var k14 = h * Fi(x + k13, y + k23);
			var k24 = h * Psi(x + k13, y + k23);

			var nextX = x + (k11 + 2 * k12 + 2 * k13 + k14) / 6;
			var nextY = y + (k21 + 2 * k22 + 2 * k23 + k24) / 6;

			SetNewCurrentPoint(nextX, nextY);

			return new PointPair(nextX, nextY);
		}

		public void SetNewInitialData(double x, double y)
		{
			_initialData.X = x;
			_initialData.Y = y;
		}

		private void SetNewCurrentPoint(double x, double y)
		{
			_currentPoints.X = x;
			_currentPoints.Y = y;
		}

		private static double Fi(double x, double y) => x * x + x * y + y;

		private double Psi(double x, double y)
		{
			var a = _vector.A;
			var b = _vector.B;
			var c = _vector.C;
			var alpha = _vector.Alpha;
			var beta = _vector.Beta;

			return a * x * x + b * x * y + c * y * y + alpha * x + beta * y;
		}

		private struct Vector
		{
			public double A { get; }
			public double B { get; }
			public double C { get; }
			public double Alpha { get; }
			public double Beta { get; }

			public Vector(double a, double b, double c, double alpha, double beta)
			{
				A = a;
				B = b;
				C = c;
				Alpha = alpha;
				Beta = beta;
			}
		}

		private struct InitialData
		{
			public InitialData(double a, double b)
			{
				X = a;
				Y = b;
			}

			public double X { get; set; }
			public double Y { get; set; }
		}

		private struct CurrentPoints
		{
			public CurrentPoints(double a, double b)
			{
				X = a;
				Y = b;
			}
			public double X { get; set; }
			public double Y { get; set; }
		}
	}
}