#pragma once


typedef struct Vector Vector;
typedef struct Region Region;
typedef struct Point Point;

Vector *create_vector(const double a
					, const double b
					, const double c
					, const double alpha
					, const double beta
					, const double x
					, const double y);

Point *create_point(double x, double y);
Point *get_point(Vector *vector);
const double get_x(const Point *point);
const double get_y(const Point *point);

const double get_a(const Vector *vector);
const double get_b(const Vector *vector);
const double get_c(const Vector *vector);
const double get_alpha(const Vector *vector);
const double get_beta(const Vector *vector);

void set_a(Vector *vector, const double a);
void set_b(Vector *vector, const double b);
void set_c(Vector *vector, const double c);
void set_alpha(Vector *vector, const double alpha);
void set_beta(Vector *vector, const double beta);
void set_x(Point *point, const double x);
void set_y(Point *point, const double y);

void delete_vector(Vector *vector);
void delete_point(Point *point);