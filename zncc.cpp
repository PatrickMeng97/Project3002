#include"zncc.h"
#include <cmath>
#include <iostream>
using namespace std;

Zncc::Zncc()
{
    data1 = data2 = NULL;
    I = J = 0;
}

Zncc::Zncc(int** d1, int** d2, int I, int J)
    : data1(d1), data2(d2), I(I), J(J)
{
}

double Zncc::calZncc(int** d1, int** d2, int I, int J)
{
    double sum2_x = 0.;
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++) sum2_x += d1[i][j] * d1[i][j];

    double sum_x = 0.;
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++)  sum_x += d1[i][j];

    sigma_x = sqrt(I * J * sum2_x - sum_x * sum_x);


    double sum2_y = 0.;
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++) sum2_y += d2[i][j] * d2[i][j];

    double sum_y = 0.;
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++) sum_y += d2[i][j];

    sigma_y = sqrt(I * J * sum2_y - sum_y * sum_y);

    double dotp = 0.;
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++) dotp += d1[i][j] * d2[i][j];


    double zncc = (I * J * dotp - sum_x * sum_y) / (sigma_x * sigma_y);

    return -zncc;
}