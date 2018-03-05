#include "../include/Data.h"
#include "../include/Logic.h"


typedef struct Vector {
	double a;
	double b;
	double c;
	double alpha;
	double beta;
	double x0;
	double y0;
} Vector;

typedef struct Interval {
	int quantity_of_points;
	double h;
} Interval;


double get_a(Vector *vector) {
	return vector->a;
}

double get_b(Vector *vector) {
	return vector->b;
}

double get_c(Vector *vector) {
	return vector->c;
}

double get_alpha(Vector *vector) {
	return vector->alpha;
}

double get_beta(Vector *vector) {
	return vector->beta;
}

double get_x0(Vector *vector) {
	return vector->x0;
}

double get_y0(Vector *vector) {
	return vector->y0;
}

int get_quantity_of_points(const Interval *interval){
	return interval->quantity_of_points;
}

double get_h(const Interval *interval){
	return interval->h;
}