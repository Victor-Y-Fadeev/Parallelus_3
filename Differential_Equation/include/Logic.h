#pragma once

#include "Data.h"


double phi(const double x, const double y);

double psi(const double x, const double y, Vector *vector);

int solve_equation(Vector *vector, const Interval *interval);