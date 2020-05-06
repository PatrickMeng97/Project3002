#ifndef DISTANCE_H
#define DISTANCE_H
#include<iostream>                                                                                                       
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Distance {
private:
	double* data1, * data2;
	int d_len;
public:
	Distance(double* d1, double* d2, int len);
	Distance();

	double Euclidean();
	double Cosine();
	double Cosine2d(int** data1, int** data2, int N, int M);
	double Euclidean2d(int** data1, int** data2, int N, int M);
};
#endif // !DISTANCE_H

