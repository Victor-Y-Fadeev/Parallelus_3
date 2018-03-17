#pragma once


typedef struct Analyser Analyser;

Analyser *create_analyser();

void send_points(Analyser *analyser, const float x, const float y);
int receive_course(Analyser *analyser);

void set_point0(Analyser *analyser, float x0, float y0);
void set_point(Analyser *analyser, const float x, const float y);
float distanse(const float x0, const float y0, const float x, const float y);
void chec_firstmax(Analyser *analyser);
void chec_max(Analyser *analyser);
void chec_period (Analyser *analyser);
void max_distanse (Analyser *analyser, const float x, const float y);
int receive_arrow (Analyser*analyser);

void delete_analyser(Analyser *analyser);

