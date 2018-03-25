#include "../include/SpecialPoints.h"
#include "../include/Structures.h"
#include <stdlib.h>
#include <math.h>

#define eps 0.000005

typedef struct SpecialPoint
{
    float x0;
    float y0;

    float x1;
    float y1;

    float x2;
    float y2;

    float x3;
    float y3;

    int numbers;
} SpecialPoint;





int two_solution(float x1, float x2, SpecialPoint *sPoint)
{
    int i = 1;
    if(fabsf(x1 + 1)> eps && fabsf(x1)> eps )
    {
        sPoint->x1 = x1;
        sPoint->y1 = -(x1 * x1) / (x1 + 1);
        i++;

        if(fabsf(x2 + 1)> eps && fabsf(x2)> eps )
        {
            sPoint->x2 = x2;
            sPoint->y2 = -(x2 * x2) / (x2 + 1);
            i++;
        }
    }
    else if (fabsf(x2 + 1)> eps && fabsf(x2)> eps )
    {
        sPoint->x1 = x2;
        sPoint->y1 = -(x2 * x2) / (x2 + 1);
        i++;
    }

    return i;
}

int three_solution(float x1, float x2, float x3, SpecialPoint *sPoint)
{
    int i = 1;
    if(fabsf(x1 + 1)> eps && fabsf(x1)> eps )
    {
        sPoint->x1 = x1;
        sPoint->y1 = -(x1 * x1) / (x1 + 1);
        i++;

        if(fabsf(x2 + 1)> eps && fabsf(x2)> eps )
        {
            sPoint->x2 = x2;
            sPoint->y2 = -(x2 * x2) / (x2 + 1);
            i++;

            if(fabsf(x3 + 1)> eps && fabsf(x3)> eps )
            {
                sPoint->x3 = x2;
                sPoint->y3 = -(x3 * x3) / (x3 + 1);
                i++;
            }

        }
        else if (fabsf(x3 + 1)> eps && fabsf(x3)> eps )
        {
            sPoint->x2 = x3;
            sPoint->y2 = -(x3 * x3) / (x3 + 1);
            i++;
        }
    }
    else if (fabsf(x2 + 1)> eps && fabsf(x2)> eps )
    {
        sPoint->x1 = x2;
        sPoint->y1 = -(x2 * x2) / (x2 + 1);
        i++;

        if(fabsf(x3 + 1)> eps && fabsf(x3)> eps )
        {
            sPoint->x2 = x3;
            sPoint->y2 = -(x3 * x3) / (x3 + 1);
            i++;
        }
    }
    else if (fabsf(x3 + 1)> eps && fabsf(x3)> eps )
    {
        sPoint->x1 = x3;
        sPoint->y1 = -(x3 * x3) / (x3 + 1);
        i++;
    }

    return i;
}

int  solve_cubic_eqation(const float A, const float B, const float C, const float D, SpecialPoint *sPoint)
{
    const float p = C / A - (B * B) / (3 * A * A);
    const float q = 2 * B * B * B / (27 * A * A * A) -  (B * C) / (3 * A * A) + D / A;
    const float Q1 = (p * p * p/ 27) + (q * q / 4);

    if (fabsf(Q1)<eps)
    {
        const float alpha = cbrtf(- q / 2);
        const float x1 = 2 * alpha - B / (3 * A);
        const float x2 = - alpha - B / (3 * A);

        return two_solution( x1, x2, sPoint);
    }
    else if (Q1 > 0)
    {
        const float alpha = cbrtf(- q / 2 + sqrtf(Q1));
        const float beta = cbrtf(- q / 2 - sqrtf(Q1));
        const float x = alpha + beta - B / (3 * A);

        if (fabsf(x + 1) > eps && fabsf(x)> eps)
        {
            sPoint->x1 = x;
            sPoint->y1 = -(x * x) / (x + 1);
            return 2;
        }
        else
        {

            return 1;
        }
    }
    else
    {

        const float ImQ = sqrtf(-Q1);
        const float Ralpha =  sqrtf(q * q / 4 + Q1);
        const float Falpha =  atanf (ImQ /( q * q / 4)) / 3;
        const float ReAlpha = cbrtf(Ralpha) * cosf(Falpha);
        const float ImAlpha = cbrtf(Ralpha) * sinf(Falpha);

        const float Rbeta =  Ralpha;
        const float Fbeta =  atanf (-ImQ /( q * q / 4)) / 3;
        const float ReBeta = cbrtf(Rbeta) * cosf(Fbeta);
        const float ImBeta = cbrtf(Rbeta) * sinf(Fbeta);

        const float x1 = ReAlpha + ReBeta - B / (3 * A);
        const float x2 = - (ReAlpha + ReBeta) / 2 - ((ImAlpha - ImBeta)*sqrtf(3)/2)- B / (3 * A);
        const float x3 = - (ReAlpha + ReBeta) / 2 + ((ImAlpha - ImBeta)*sqrtf(3)/2)- B / (3 * A);

        return three_solution(x1, x2, x3, sPoint);

    }
}



int solve_square_eqation( const float A, const float B, const float C, SpecialPoint *sPoint)
{
    const float Dis = B * B - 4 * A * C;
    if (fabsf(Dis)<eps)
    {
        const float  x = - B/(2*A);
        if (fabsf(x + 1) > eps && fabsf(x)> eps)
        {
            sPoint->x1 = x;
            sPoint->y1 = -(x * x) / (x + 1);
            return 2;
        }
        else
        {

            return 1;
        }
    }
    if (Dis >0)
    {
        const float  x1 = ( - B + sqrtf(Dis))/ (2*A);
        const float  x2 = ( - B - sqrtf(Dis))/ (2*A);

        return two_solution( x1, x2, sPoint);
    }
    else
    {
        return 1;
    }
}

int solve_linear_eqation( const float A, const float B, SpecialPoint *sPoint)
{
    const float  x = - B / A;
    if (fabsf(x - 1) > eps && fabsf(x)> eps)
    {
        sPoint->x1 = x;
        sPoint->y1 = -(x * x) / (x + 1);
        return 2;
    }
    else
    {
        return 1;
    }
}


int num ( Vector *vector, SpecialPoint *sPoint)
{
    const float a = get_a(vector);
    const float b = get_b(vector);
    const float c = get_c(vector);
    const float alpha = get_alpha(vector);
    const float beta = get_beta(vector);

    const float A1 = a - b + c;
    const float B1 = 2*a - b + alpha - beta;
    const float C1 = a - beta + 2*alpha;
    const float D1 = alpha;

    if (A1 != 0)
    {
        return  solve_cubic_eqation(A1, B1, C1, D1, sPoint);
    }

    if (B1 != 0)
    {
        return  solve_square_eqation( B1, C1, D1, sPoint);
    }

    if (C1 != 0)
    {
        return  solve_linear_eqation(C1, D1, sPoint);
    }
    if (D1 != 0)
    {
        return  1;
    }
    else
    {
        return -1;
    }
}

SpecialPoint *create_SpecialPoint(Vector *vector)
{
    SpecialPoint *sPoint = malloc(sizeof(SpecialPoint));

    sPoint->x0 = 0;
    sPoint->y0 = 0;

    sPoint->numbers = num(vector, sPoint);
    return sPoint;
}


const float get_x0(SpecialPoint *sPoint)
{
    return sPoint->x0 ;
}

const float get_x1(SpecialPoint *sPoint)
{
    return sPoint->x1 ;
}

const float get_x2(SpecialPoint *sPoint)
{
    return sPoint->x2 ;
}

const float get_x3(SpecialPoint *sPoint)
{
    return sPoint->x3 ;
}

const float get_y0(SpecialPoint *sPoint)
{
    return sPoint->y0 ;
}

const float get_y1(SpecialPoint *sPoint)
{
    return sPoint->y1 ;
}

const float get_y2(SpecialPoint *sPoint)
{
    return sPoint->y2 ;
}

const float get_y3(SpecialPoint *sPoint)
{
    return sPoint->y3 ;
}

const int  get_numbers(SpecialPoint *sPoint)
{
    return sPoint->numbers ;
}