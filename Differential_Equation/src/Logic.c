#include "../include/Logic.h"
#include "../include/Data.h"


typedef struct Result
{
	Vector *vector;
	double points_x[];
	double points_y[];

} Result;


Result create_result(double x[], double y[], Vector *vector)
{
	Result result;
	result.points_x = x;
	result.points_y = y;
	result.vector = vector;
}

double phi(const double x, const double y)
{
	return x * x + x * y + x;
}

double psi(const double x, const double y, Vector *vector)
{
	double a = get_a(vector);
	double b = get_b(vector);
	double c = get_c(vector);
	double alpha = get_alpha(vector);
	double beta = get_beta(vector);
	return a * x * x + b * x * y + c * y * y + alpha * x + beta * y;
}

Result solve_equation(Vector *vector, const Interval *interval)
{
	double x0 = get_x0(vector);
	double y0 = get_y0(vector);
	double h = get_h(interval);
	int quantity_of_points = get_quantity_of_points(interval);
	double k11, k21, k12, k22, k13, k23, k14, k24; // coefficients
	double result_x[quantity_of_points];
	double result_y[quantity_of_points];

	result_x[0] = x0;
	result_y[0] = y0;

	for (int i = 1; i < quantity_of_points; ++i) {
		k11 = h * phi(x0, y0);
		k21 = h * psi(x0, y0, vector);

		k12 = h * phi(x0 + k11 / 2, y0 + k21 / 2);
		k22 = h * psi(x0 + k11 / 2, y0 + k21 / 2, vector);

		k13 = h * phi(x0 + k12 / 2, y0 + k22 / 2);
		k23 = h * psi(x0 + k12 / 2, y0 + k22 / 2, vector);

		k14 = h * phi(x0 + k13, y0 + k23);
		k24 = h * psi(x0 + k13, y0 + k23, vector);

		x0 = x0 + (k11 + k12 + k13 + k14) / 6;
		y0 = y0 + (k21 + k22 + k23 + k24) / 6;

		result_x[i] = x0;
		result_y[i] = y0;
	}

	return create_result(result_x, result_y, vector);
}
