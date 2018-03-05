#pragma once

#include "Logic.h"


typedef struct Vector Vector;
typedef struct Loader Loader;
typedef struct Saver Saver;


Vector create_vector(double a, double b, double c, double alpha, double beta, double x0, double y0);
Loader create_loader(char *input);
Saver create_saver(char *output);


Vector get_vector(Loader *loader);
void save(Saver *saver, Result *result);


double get_a(Vector *vector);
double get_b(Vector *vector);
double get_c(Vector *vector);
double get_alpha(Vector *vector);
double get_beta(Vector *vector);
double get_x0(Vector *vector);
double get_y0(Vector *vector);


void set_a(Vector *vector, double a);
void set_b(Vector *vector, double b);
void set_c(Vector *vector, double c);
void set_alpha(Vector *vector, double alpha);
void set_beta(Vector *vector, double beta);
void set_x0(Vector *vector, double x0);
void set_y0(Vector *vector, double y0);
