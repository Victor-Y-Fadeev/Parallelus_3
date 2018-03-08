#include "../include/Structures.h"
#include <stdlib.h>


typedef struct Vector
{
	double a;
	double b;
	double c;
	double alpha;
	double beta;
	double x0;
	double y0;
} Vector;

typedef struct Interval
{
	int steps;
	double distance;
	int points;
	double h;
} Interval;


Vector *create_vector(const double a
					, const double b
					, const double c
					, const double alpha
					, const double beta
					, const double x0
					, const double y0)
{
	Vector *vector = malloc(sizeof(Vector));

	vector->a = a;
	vector->b = b;
	vector->c = c;
	vector->alpha = alpha;
	vector->beta = beta;
	vector->x0 = x0;
	vector->y0 = y0;

	return vector;
}

Interval *create_interval(const int steps
						, const double distance
						, const int points
						, const double h)
{
	Interval *interval = malloc(sizeof(Interval));

	interval->steps = steps;
	interval->distance = distance;
	interval->points = points;
	interval->h = h;

	return interval;
}


const double get_a(const Vector *vector)
{
	return vector->a;
}

const double get_b(const Vector *vector)
{
	return vector->b;
}

const double get_c(const Vector *vector)
{
	return vector->c;
}

const double get_alpha(const Vector *vector)
{
	return vector->alpha;
}

const double get_beta(const Vector *vector)
{
	return vector->beta;
}

const double get_x0(const Vector *vector)
{
	return vector->x0;
}

const double get_y0(const Vector *vector)
{
	return vector->y0;
}


const int get_steps(const Interval *interval)
{
	return interval->steps;
}

const double get_distance(const Interval *interval)
{
	return interval->distance;
}

const int get_points(const Interval *interval)
{
	return interval->points;
}

const double get_h(const Interval *interval)
{
	return interval->h;
}


void set_a(Vector *vector, const double a)
{
	vector->a = a;
}

void set_b(Vector *vector, const double b)
{
	vector->b = b;
}

void set_c(Vector *vector, const double c)
{
	vector->c = c;
}

void set_alpha(Vector *vector, const double alpha)
{
	vector->alpha = alpha;
}

void set_beta(Vector *vector, const double beta)
{
	vector->beta = beta;
}

void set_x0(Vector *vector, const double x0)
{
	vector->x0 = x0;
}

void set_y0(Vector *vector, const double y0)
{
	vector->y0 = y0;
}


void set_steps(Interval *interval, const int steps)
{
	interval->steps = steps;
}

void set_distance(Interval *interval, const double distance)
{
	interval->distance = distance;
}

void set_points(Interval *interval, const int points)
{
	interval->points = points;
}

void set_h(Interval *interval, const double h)
{
	interval->h = h;
}


void delete_vector(Vector *vector)
{
	free(vector);
}

void delete_interval(Interval *interval)
{
	free(interval);
}
