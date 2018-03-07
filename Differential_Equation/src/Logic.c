#include "../include/Data.h"
#include "../include/Logic.h"


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

// return: quantity of strange attractors, -1 if error appear, 1 if cycle was found
int solve_equation(Vector *vector, const Interval *interval)
{
	double x0 = get_x0(vector);
	double y0 = get_y0(vector);
	double h = get_h(interval); //0.001

	int quantity_of_points = get_quantity_of_points(interval); //9000
	double k11, k21, k12, k22, k13, k23, k14, k24; // coefficients

	int quantity = 0; // counter of strange attractors
	int isIncrement = 0;
	int last_direction = 0; //-1 == left, 1 == right, 0 == start value
	double x0_last = x0;

	for (int i = 0; i < quantity_of_points; ++i) {
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

		if (y0 == 0) {
			if (x0_last > x0){
				if(last_direction != -1){
					if(last_direction == 0){
						last_direction = -1;
					}
					else{
						return -1; //WTF
					}
				}
			}
			else if (x0_last < x0){
				if(last_direction != 1){
					if(last_direction == 0){
						last_direction = 1;
					}
					else{
						return -1; //WTF
					}
				}
			}
			else{
				return 1; // cycle
			}

		}
	}
	return quantity;
}
