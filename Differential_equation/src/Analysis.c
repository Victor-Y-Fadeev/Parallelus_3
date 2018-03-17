#include "../include/Analysis.h"
#include <stdlib.h>

#define Cperiod 5

typedef struct Analyser
{
	float x0;
	float y0;

	float x;
	float y;
	float last_y;

	int period;
	int halfperiod;

	float first_max ;
	float max ;
} Analyser;


Analyser *create_analyser()
{
	Analyser *analyser = malloc(sizeof(Analyser));

	analyser->x = 0;
	analyser->y = 0;
	analyser->last_y=0;

	analyser->x0 = 0;
	analyser->y0 = 0;

	analyser->period = 0;
	analyser->halfperiod = 0;

	analyser->first_max = 0;
	analyser->max = 0;

	return analyser;
}

void set_point0(Analyser *analyser, const float x0, const float y0)
{
	analyser->x0 = x0;
	analyser->y0 = y0;

	return;
}

void set_point(Analyser *analyser, const float x, const float y)
{
	analyser->last_y = analyser ->y;

	analyser->x0 = x;
	analyser->y0 = y;

	return;
}

void chec_period (Analyser *analyser)
{
	if (analyser->last_y * analyser->y <= 0)
	{
		if (analyser->halfperiod  == 0 )
		{
			analyser->halfperiod = 1;
		}
		else
		{
			analyser->halfperiod =0;
			analyser->period++;
		}
	}

	return;
}

float distanse(const float x0, const float y0, const float x, const float y)
{
	return (x0-x)*(x0-x)+(y0-y)*(y0-y);
}

void chec_firstmax(Analyser *analyser)
{
	if(distanse(analyser->x0, analyser->y0, analyser->x, analyser->y) > analyser->first_max)
	{
		analyser->first_max = distanse(analyser->x0, analyser->y0, analyser->x, analyser->y);
	}

	return;
}

void chec_max(Analyser *analyser)
{
	if(distanse(analyser->x0, analyser->y0, analyser->x, analyser->y) > analyser->max)
	{
		analyser->max = distanse(analyser->x0, analyser->y0, analyser->x, analyser->y);
	}

	return;
}

void max_distanse(Analyser *analyser, const float x, const float y)
{
	set_point(analyser, x, y);

	chec_period (analyser);

	if (analyser->period == 0)
	{
		chec_max(analyser);
	}
	if (analyser->period == Cperiod)
	{
		chec_firstmax(analyser);
	}

    return;
}

int receive_arrow (Analyser*analyser)
{
    if (analyser->max > analyser->first_max)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void delete_analyser(Analyser *analyser)
{
    free(analyser);
}

