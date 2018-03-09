#include "../include/Logic.h"
#include <stdlib.h>
#include "../include/Structures.h"
#include "../include/Files.h"


void auto_computation(Loader *loader, Saver *saver)
{
	Vector *vector = NULL;
	Interval *interval = NULL;

	while (1)
	{
		vector = load_vector(loader);
		interval = load_interval(loader);

		if ((vector == NULL) || (interval == NULL))
		{
			return;
		}

		if (solve_equation(vector, interval) != 0)
		{
			save_vector(saver, vector);
			save_interval(saver, interval);
		}

		delete_vector(vector);
		delete_interval(interval);
	}
}

int solve_equation(Vector *vector, Interval *interval)
{
	const int steps = get_steps(interval);
	const float distance = get_distance(interval);

	for (int i = 0; i < steps; i++)
	{
		attractor_course(vector, interval);
		set_x(vector, get_x(vector) + distance);
	}

	return 0;
}

int attractor_course(Vector *vector, Interval *interval)
{


}



const float phi(const float x, const float y)
{
	return x * x + x * y + x;
}

const float psi(Vector *vector, const float x, const float y)
{
	const float a = get_a(vector);
	const float b = get_b(vector);
	const float c = get_c(vector);
	const float alpha = get_alpha(vector);
	const float beta = get_beta(vector);

	return a * x * x + b * x * y + c * y * y + alpha * x + beta * y;
}

// return: quantity of strange attractors, -1 attractor error, 1 if cycle was found
int solve_equation_old(Vector *vector, Interval *interval)
{
	double x0 = get_x(vector);
	double y0 = get_y(vector);
	double h = get_h(interval);

	int quantity_of_points = get_points(interval); // >= 9000
	double k11, k21, k12, k22, k13, k23, k14, k24; // coefficients
	int last_attractor = 0; //-1 == left, 1 == right, 0 == start value
	int new_attractor = 0; //-1 == left, 1 == right, 0 == start value
	int quantity = 0; // counter of strange attractors
	int quantity_of_jumps = get_steps(interval);
	double distance = get_distance(interval);

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
