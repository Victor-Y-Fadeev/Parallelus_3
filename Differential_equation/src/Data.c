#include "../include/Data.h"
#include <stdlib.h>


typedef struct tVector
{
	double a;
	double b;
	double c;
	double alpha;
	double beta;
	double x0;
	double y0;
} Vector;

typedef struct tInterval
{
	int quantity_of_points;
	double h;
	int quantity_of_jumps;
	double distance_jump;
} Interval;

Vector* create_vector(double a, double b, double c, double alpha, double beta, double x0, double y0)
{
	Vector *vector = malloc(sizeof(Vector));
	set_a(vector,a);
	set_b(vector,b);
	set_c(vector,c);
	set_alpha(vector,alpha);
	set_beta(vector,beta);
	set_x0(vector,x0);
	set_y0(vector,y0);
	return vector;
}


Interval *create_interval(int quantity_of_points, double h, int quantity_of_jumps, double distance_jump)
{
	Interval *interval = malloc(sizeof(Interval));
	set_quantity_of_points(interval, quantity_of_points);
	set_h(interval, h);
	set_quantity_of_jumps(interval, quantity_of_jumps);
	set_distance_jump(interval, distance_jump);
	return interval;
}

void delete_vector(Vector *vector)
{
	free(vector);
}

void delete_interval(Interval *interval)
{
	free(interval);
}

double get_a(const Vector *vector)
{
	return vector->a;
}

double get_b(const Vector *vector)
{
	return vector->b;
}

double get_c(const Vector *vector)
{
	return vector->c;
}

double get_alpha(const Vector *vector)
{
	return vector->alpha;
}

double get_beta(const Vector *vector)
{
	return vector->beta;
}

double get_x0(const Vector *vector)
{
	return vector->x0;
}

double get_y0(const Vector *vector)
{
	return vector->y0;
}

int get_quantity_of_points(const Interval *interval)
{
	return interval->quantity_of_points;
}

double get_h(const Interval *interval)
{
	return interval->h;
}

int get_quantity_of_jumps(const Interval *interval)
{
	return interval->quantity_of_jumps;
}

double get_distance_jump(const Interval *interval)
{
	return interval->distance_jump;
}

void set_a(Vector *vector, double a)
{
	vector->a = a;
}

void set_b(Vector *vector, double b)
{
	vector->b = b;
}

void set_c(Vector *vector, double c)
{
	vector->c = c;
}

void set_alpha(Vector *vector, double alpha)
{
	vector->alpha = alpha;
}

void set_beta(Vector *vector, double beta)
{
	vector->beta = beta;
}

void set_x0(Vector *vector, double x0)
{
	vector->x0 = x0;
}

void set_y0(Vector *vector, double y0)
{
	vector->y0 = y0;
}

int set_quantity_of_points(Interval *interval, int quantity)
{
	interval->quantity_of_points = quantity;
}

void set_h(Interval *interval, double h)
{
	interval->h = h;
}

void set_quantity_of_jumps(Interval *interval, int quantity_of_jumps)
{
	interval->quantity_of_jumps = quantity_of_jumps;
}

void set_distance_jump(Interval *interval, double distance_jump)
{
	interval->distance_jump = distance_jump;
}