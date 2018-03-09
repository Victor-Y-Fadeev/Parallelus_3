#include "../include/Logic.h"
#include <stdlib.h>


void auto_computation(Loader *loader, Saver *saver)
{
	Vector *vector = load_vector(loader);
	Interval *interval = load_interval(loader);

	if ((vector == NULL) || (interval == NULL))
	{
		return;
	}

	while (1)
	{
		if (solve_equation(vector, interval) == 0)
		{
			save_vector(saver, vector);
			save_interval(saver, interval);
		}

		if ((reload_vector(loader, vector) != 0) || (reload_interval(loader, interval) != 0))
		{
			delete_vector(vector);
			delete_interval(interval);

			return;
		}
	}
}

int solve_equation(Vector *vector, Interval *interval)
{
	const int steps = get_steps(interval);
	const float distance = get_distance(interval);
	const float y = get_y(vector);

	float x = get_x(vector);

	for (int i = 0; i < steps; ++i)
	{
		attractor_course(vector, interval);

		// To do something with +1, -1

		x += distance;

		set_y(vector, y);
		set_x(vector, x);
	}

	return 0;
}

int attractor_course(Vector *vector, Interval *interval)
{
	const int points = get_points(interval);
	const float h = get_h(interval);

	float t = 0;

	for (int i = 0; i < points; ++i)
	{
		solution(vector, t, h);

		// To do something with x0, y0, x1, y1

		t += h;
	}

	return 0;
}

const float fi(const float x, const float y)
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

void solution(Vector *vector, const float t, const float h)
{
	const float x = get_x(vector);
	const float y = get_y(vector);

	const float k11 = h * fi(x, y);
	const float k21 = h * psi(vector, x, y);

	const float k12 = h * fi(x + k11 / 2, y + k21 / 2);
	const float k22 = h * psi(vector, x + k11 / 2, y + k21 / 2);

	const float k13 = h * fi(x + k12 / 2, y + k22 / 2);
	const float k23 = h * psi(vector, x + k12 / 2, y + k22 / 2);

	const float k14 = h * fi(x + k13, y + k23);
	const float k24 = h * psi(vector, x + k13, y + k23);

	const float x_next = x + (k11 + k12 + k13 + k14) / 6;
	const float y_next = y + (k21 + k22 + k23 + k24) / 6;

	set_x(vector, x_next);
	set_y(vector, y_next);
}
