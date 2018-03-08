#pragma once


typedef struct Vector Vector;
typedef struct Interval Interval;

Vector *create_vector(const double a
					, const double b
					, const double c
					, const double alpha
					, const double beta
					, const double x0
					, const double y0);

Interval *create_interval(const int steps
						, const double distance
						, const int points
						, const double h);

const double get_a(const Vector *vector);
const double get_b(const Vector *vector);
const double get_c(const Vector *vector);
const double get_alpha(const Vector *vector);
const double get_beta(const Vector *vector);
const double get_x0(const Vector *vector);
const double get_y0(const Vector *vector);

const int get_steps(const Interval *interval);
const double get_distance(const Interval *interval);
const int get_points(const Interval *interval);
const double get_h(const  Interval *interval);

void set_a(Vector *vector, const double a);
void set_b(Vector *vector, const double b);
void set_c(Vector *vector, const double c);
void set_alpha(Vector *vector, const double alpha);
void set_beta(Vector *vector, const double beta);
void set_x0(Vector *vector, const double x0);
void set_y0(Vector *vector, const double y0);

void set_steps(Interval *interval, int steps);
void set_distance(Interval *interval, double distance);
void set_points(Interval *interval, int points);
void set_h(Interval *interval, double h);

void delete_vector(Vector *vector);
void delete_interval(Interval *interval);
