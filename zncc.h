#ifndef ZNCC_H
#define ZNCC_H
#include<iostream>                                                                                                       
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Zncc {
private:
	int** data1, ** data2;
	double sigma_x, sigma_y;
	int I, J;

public:

	Zncc();
	Zncc(int** d1, int** d2, int I, int J);
	double calZncc(int** d1, int** d2, int I, int J);

};
#endif // !DISTANCE_H