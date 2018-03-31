#include "../include/Structures.h"
#include <stdlib.h>


typedef struct Vector
{
	double a;
	double b;
	double c;
	double alpha;
	double beta;

	Point *point;
} Vector;

typedef struct Region
{
} Region;

typedef struct Point
{
	double x;
	double y;
} Point;


Vector *create_vector(const double a
					, const double b
					, const double c
					, const double alpha
					, const double beta
					, const double x
					, const double y)
{
	Vector *vector = malloc(sizeof(Vector));

	vector->a = a;
	vector->b = b;
	vector->c = c;
	vector->alpha = alpha;
	vector->beta = beta;
	vector->point = create_point(x, y);

	return vector;
}

Point *create_point(double x, double y)
{
	Point *point = malloc(sizeof(Point));
	point->x = x;
	point->y = y;
	return point;
}

Point *get_point(Vector *vector)
{
	return vector->point;
}

const double get_x(const Point * point)
{
	return point->x;
}

const double get_y(const Point * point)
{
	return point->y;
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

void set_point(Vector *vector, Point *point)
{
	vector->point = point;
}

void set_x(Point *point, const double x)
{
	point->x = x;
}

void set_y(Point *point, const double y)
{
	point->y = y;
}

void delete_vector(Vector *vector)
{
	free(vector->point);
	free(vector);
}

void delete_point(Point *point)
{
	free(point);
}
