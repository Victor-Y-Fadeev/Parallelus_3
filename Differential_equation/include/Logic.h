#pragma once

#include "Files.h"


typedef struct Logic Logic;

Logic *create_logic(const Loader *loader, const Saver *saver);

void auto_computation(Logic *logic);

void delete_logic(Logic *logic);
