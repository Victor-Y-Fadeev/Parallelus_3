#include "../include/Logic.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "../include/Analysis.h"

#define QUANTITY_OF_HALF_TURN 30
#define EPS 0.000001
#define MAX_QUANTITY_OF_STEPS 1000000


const double fi(double x, double y);
const double psi(Vector *vector, double x, double y);
void set_next_point(Vector *vector, double last_x, double last_y, double *next_x, double *next_y, double h);
int pass_few_semicircle(double start_x, double start_y, Vector *vector, int quantity, double *rez_x, double *rez_y);

//???
void swap(double *a, double *b)
{
	double c = *a;
	*a = *b;
	*b = c;
}

int get_direction(double from, double to)
{
	if (from < to)
	{
		return 1;
	}

	return from > to ? -1 : 0;
}



//(x0, y0) -- singular point
int find_cycles_in_sp_environs(Vector*vector, double x0, double y0, double to, unsigned int quantity_steps)
{
	assert(quantity_steps);
	double step = fabs((to - x0)) / quantity_steps;
	double coshi_x = x0;
	double coshi_y = y0;
	double last_x, last_y = coshi_y;
	double next_x, next_y;
	int last_direction = 1, new_direction;
	int quantity = 0;

	for (int i = 0; i < quantity_steps; ++i) {
		coshi_x += step;
		last_x = coshi_x;
		if (pass_few_semicircle(last_x, last_y, vector, QUANTITY_OF_HALF_TURN, &next_x, &next_y)) {
			return -1; // ...
		}
		new_direction = get_direction(last_x, next_x);
		if (last_direction != new_direction) {
			if (step < EPS) {
				++quantity;
			}
			else {
				double last_coshi = coshi_x - step; // * 1.1;
				quantity += find_cycles_in_sp_environs(vector, last_coshi, coshi_y, next_x, 10); // testing
			}
			last_direction = new_direction;
		}
	}
}

int FindCentre(double start_x, double start_y, Vector *vector, double *rez_x, double *rez_y)
{
	const double error = 0.01;
	double last_x = start_x;
	double last_y = start_y;
	double next_x;
	double next_y;

	do {
		if (pass_few_semicircle(last_x, last_y, vector, 1, &next_x, &next_y)) {
			return 1;
		}

		if (last_x < next_x) {
			next_x -= (next_x - last_x) / 2;
		}
		else if (last_x > next_x) {
			swap(&last_x, &next_x);
			swap(&last_y, &next_y);
		}

	}
	while (next_x - start_x > error);
	*rez_x = next_x;
	*rez_y = next_y;
	return 0;
}

// return -- max point (ordinate)
int pass_few_semicircle(double start_x, double start_y, Vector *vector, int quantity, double *rez_x, double *rez_y)
{
	const double step = 0.00001;
	double y0 = start_y;
	double last_x = start_x;
	double last_y = start_y;
	double next_x = 0;
	double next_y = 0;

	int counter = -1;
	double h = step;
	int i;

	int quantitySteps = 0;
	const int max = MAX_QUANTITY_OF_STEPS;
	while (counter < quantity && quantitySteps < max) {
		quantitySteps++;
		set_next_point(vector, last_x, last_y, &next_x, &next_y, h);
		if (last_y - y0 >= 0 && next_y - y0 < 0 || last_y - y0 <= 0 && next_y - y0 > 0) {
			counter++;
		}
		last_x = next_x;
		last_y = next_y;
		if (quantitySteps == max) {
			return 1;
		}
	}
	counter = 1;

	*rez_x = next_x;
	*rez_y = next_y;
	return 0;
}


const double fi(const double x, const double y)
{
	return x * x + x * y + y;
}

const double psi(Vector *vector, const double x, const double y)
{
	const double a = get_a(vector);
	const double b = get_b(vector);
	const double c = get_c(vector);
	const double alpha = get_alpha(vector);
	const double beta = get_beta(vector);

	return a * x * x + b * x * y + c * y * y + alpha * x + beta * y;
}

void set_next_point(Vector *vector, double last_x, double last_y, double *next_x, double *next_y, const double h)
{
	const double x = last_x;
	const double y = last_y;

	const double k11 = h * fi(x, y);
	const double k21 = h * psi(vector, x, y);

	const double k12 = h * fi(x + k11 / 2, y + k21 / 2);
	const double k22 = h * psi(vector, x + k11 / 2, y + k21 / 2);

	const double k13 = h * fi(x + k12 / 2, y + k22 / 2);
	const double k23 = h * psi(vector, x + k12 / 2, y + k22 / 2);

	const double k14 = h * fi(x + k13, y + k23);
	const double k24 = h * psi(vector, x + k13, y + k23);

	*next_x = x + (k11 + k12 + k13 + k14) / 6;
	*next_y = y + (k21 + k22 + k23 + k24) / 6;
}

void next_point(Vector *vector, Point *last_point, Point *next_point, const double h)
{
	const double x = get_x(last_point);
	const double y = get_y(last_point);

	const double k11 = h * fi(x, y);
	const double k21 = h * psi(vector, x, y);

	const double k12 = h * fi(x + k11 / 2, y + k21 / 2);
	const double k22 = h * psi(vector, x + k11 / 2, y + k21 / 2);

	const double k13 = h * fi(x + k12 / 2, y + k22 / 2);
	const double k23 = h * psi(vector, x + k12 / 2, y + k22 / 2);

	const double k14 = h * fi(x + k13, y + k23);
	const double k24 = h * psi(vector, x + k13, y + k23);

	const double next_x = x + (k11 + k12 + k13 + k14) / 6;
	const double next_y = y + (k21 + k22 + k23 + k24) / 6;

	set_x(next_point, next_x);
	set_y(next_point, next_y);
}
