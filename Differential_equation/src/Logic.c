#include "../include/Logic.h"
#include <stdlib.h>
#include "../include/Analysis.h"

#define STRANGE_ATTRACTORS 3
#define Cperiod 5


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
		if (solve_equation(vector, interval) >= STRANGE_ATTRACTORS)
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
	int attractors = 0;
	int prev = 0;

	for (int i = 0; i < steps; ++i)
	{
		const int next = attractor_course(vector, interval);

		x += distance;

		set_y(vector, y);
		set_x(vector, x);

		if ((prev == 1) && (next == -1))
		{
			attractors++;
		}

		prev = next;
	}

	return attractors;
}

int attractor_course(Vector *vector, Interval *interval)
{

	const int points = get_points(interval);
	const float h = get_h(interval);

	//Analyser *analyser = create_analyser(get_x(vector), get_y(vector));
	const float x0 = get_x(vector);
	const float y0 = get_y(vector);
	float last_x = x0;
	float last_y = y0;
	float x;
	float y;
	int flag = 0;
	float first_max = -1.0;
	float max = -1.0;
	int arrow = 0;

	for (int i = 0; i < points; ++i)
	{
 		solution(vector, h);

		x = get_x(vector);
	 	y = get_y(vector);

 		//send_points(analyser, get_x(vector), get_y(vector));

		if (last_y*y<= 0) 
		{
			if (flag == 0 )
			{
				flag++;
			}
			else
			{
				flag =0;
				period ++;
			}
		}

		if (period == 0 && L(x0,y0,x,y) > first_max ) 
		{
			first_max = L(x0,y0,x,y);
		}
 
		if (period == Cperiod && L(x0,y0,x,y) > max ) 
		{
			max = L(x0,y0,x,y);
		} 

		last_x = x;
		last_y = y;
	}

	if (max > first_max)
	{
		arrow = 1; 
	}
	else
	{
	arrow = -1;
	}

 //const int course = receive_course(analyser);

 //delete_analyser(analyser);

 return arrow;
}

float L(const float x0, const float y0, float x,float y)
{
	return (x0-x)*(x0-x)+(y0-y)(y0-y);
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

void solution(Vector *vector, const float h)
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

	const float next_x = x + (k11 + k12 + k13 + k14) / 6;
	const float next_y = y + (k21 + k22 + k23 + k24) / 6;

	set_x(vector, next_x);
	set_y(vector, next_y);
}
