#pragma once

#include "Files.h"
typedef struct SpecialPoint SpecialPoint;

SpecialPoint *create_SpecialPoint(Vector *vector);

const double get_x0(SpecialPoint *sPoint);
const double get_x1(SpecialPoint *sPoint);
const double get_x2(SpecialPoint *sPoint);
const double get_x3(SpecialPoint *sPoint);
const double get_y0(SpecialPoint *sPoint);
const double get_y1(SpecialPoint *sPoint);
const double get_y2(SpecialPoint *sPoint);
const double get_y3(SpecialPoint *sPoint);
const int get_numbers(SpecialPoint *sPoint);

