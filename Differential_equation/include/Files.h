#pragma once

#include "Structures.h"


typedef struct Loader Loader;
typedef struct Saver Saver;

Loader *create_loader();
Saver *create_saver();

Vector *load_vector(Loader *loader);
Interval *load_interval(Loader *loader);

void delete_loader(Loader *loader);
void delete_saver(Saver *saver);