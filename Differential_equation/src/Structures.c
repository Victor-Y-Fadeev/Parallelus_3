#include "../include/Structures.h"
#include <stdlib.h>


typedef struct Vector
{
	float a;
	float b;
	float c;
	float alpha;
	float beta;
	float x0;
	float y0;
} Vector;

typedef struct Interval
{
	int steps;
	float distance;
	int points;
	float h;
} Interval;


Vector *create_vector(const float a
					, const float b
					, const float c
					, const float alpha
					, const float beta
					, const float x0
					, const float y0)
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
						, const float distance
						, const int points
						, const float h)
{
	Interval *interval = malloc(sizeof(Interval));

	interval->steps = steps;
	interval->distance = distance;
	interval->points = points;
	interval->h = h;

	return interval;
}


const float get_a(const Vector *vector)
{
	return vector->a;
}

const float get_b(const Vector *vector)
{
	return vector->b;
}

const float get_c(const Vector *vector)
{
	return vector->c;
}

const float get_alpha(const Vector *vector)
{
	return vector->alpha;
}

const float get_beta(const Vector *vector)
{
	return vector->beta;
}

const float get_x0(const Vector *vector)
{
	return vector->x0;
}

const float get_y0(const Vector *vector)
{
	return vector->y0;
}


const int get_steps(const Interval *interval)
{
	return interval->steps;
}

const float get_distance(const Interval *interval)
{
	return interval->distance;
}

const int get_points(const Interval *interval)
{
	return interval->points;
}

const float get_h(const Interval *interval)
{
	return interval->h;
}


void set_a(Vector *vector, const float a)
{
	vector->a = a;
}

void set_b(Vector *vector, const float b)
{
	vector->b = b;
}

void set_c(Vector *vector, const float c)
{
	vector->c = c;
}

void set_alpha(Vector *vector, const float alpha)
{
	vector->alpha = alpha;
}

void set_beta(Vector *vector, const float beta)
{
	vector->beta = beta;
}

void set_x0(Vector *vector, const float x0)
{
	vector->x0 = x0;
}

void set_y0(Vector *vector, const float y0)
{
	vector->y0 = y0;
}


void set_steps(Interval *interval, const int steps)
{
	interval->steps = steps;
}

void set_distance(Interval *interval, const float distance)
{
	interval->distance = distance;
}

void set_points(Interval *interval, const int points)
{
	interval->points = points;
}

void set_h(Interval *interval, const float h)
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
