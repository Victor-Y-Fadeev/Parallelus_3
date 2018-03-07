#include <stdio.h>
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

// return: quantity of strange attractors, -1 attractor error, 1 if cycle was found
int solve_equation(Vector *vector, const Interval *interval)
{
	double x0 = get_x0(vector);
	double y0 = get_y0(vector);
	double h = get_h(interval);

	int quantity_of_points = get_quantity_of_points(interval); // >= 9000
	double k11, k21, k12, k22, k13, k23, k14, k24; // coefficients
	int last_attractor = 0; //-1 == left, 1 == right, 0 == start value
	int new_attractor = 0; //-1 == left, 1 == right, 0 == start value
	int quantity = 0; // counter of strange attractors
	int quantity_of_jumps = get_quantity_of_jumps(interval);
	double distance = get_distance_jump(interval);

	for (int i = 0; i < quantity_of_jumps; ++i) {
		double x = x0;
		double y = y0;
		double x0_last = x0;
		int isIncrement = 0;

		for (int j = 0; j < quantity_of_points; ++j) {
			k11 = h * phi(x, y);
			k21 = h * psi(x, y, vector);

			k12 = h * phi(x + k11 / 2, y + k21 / 2);
			k22 = h * psi(x + k11 / 2, y + k21 / 2, vector);

			k13 = h * phi(x + k12 / 2, y + k22 / 2);
			k23 = h * psi(x + k12 / 2, y + k22 / 2, vector);

			k14 = h * phi(x + k13, y + k23);
			k24 = h * psi(x + k13, y + k23, vector);

			x = x + (k11 + k12 + k13 + k14) / 6;
			y = y + (k21 + k22 + k23 + k24) / 6;
			if (y == 0) {
				if (x0_last > x) {
					if (new_attractor != -1) {
						if (new_attractor == 0) {
							new_attractor = -1;
						}
						else {
							return -1; //WTF
						}
					}
				}
				else if (x0_last < x) {
					if (new_attractor != 1) {
						if (new_attractor == 0) {
							new_attractor = 1;
						}
						else {
							return -1; //WTF
						}
					}
				}
				else {
					return 1; // cycle
				}
				if(last_attractor == 1 && new_attractor == -1){
					if(!isIncrement){
						++isIncrement;
						++quantity;
					}
				}
			}
		}
		x0 += distance;
		last_attractor = new_attractor;
		new_attractor = 0;
	}
	return quantity;
}
