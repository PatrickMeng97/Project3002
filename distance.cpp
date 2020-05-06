#include"distance.h"
#include <cmath>
#include <iostream>
using namespace std;

Distance::Distance(double* d1, double* d2, int len)
	: data1(d1), data2(d2), d_len(len)
{
}

Distance::Distance()
{
	data1 = data2 = NULL;
	d_len = 0;
}

double Distance::Euclidean()
{
	if (!data1 || !data2 || d_len <= 0) {
		cout << "invalid vector(s)" << endl;
		return 0.;
	}

	double dis = 0.;
	for (int i = 0; i < d_len; i++) {
		double d = data1[i] - data2[i];
		dis += d * d;
	}
	return sqrt(dis);
}

double Distance::Cosine()
{
	if (!data1 || !data2 || d_len <= 0) {
		cout << "invalid vector(s)" << endl;
		return 0.;
	}

	double norm1 = 0., norm2 = 0., dot_product = 0.;
	for (int i = 0; i < d_len; i++) {
		norm1 += data1[i] * data1[i];
		norm2 += data2[i] * data2[i];
		dot_product += data1[i] * data2[i];
	}
	norm1 = sqrt(norm1);
	norm2 = sqrt(norm2);

	if (norm1 <= 0. || norm2 <= 0.) {
		cout << "invalid vector(s)" << endl;
		return 0.;
	}

	return dot_product / (norm1 * norm2);
}


double Distance::Euclidean2d(int** data1, int** data2, int N, int M)
{
	double d = 0.;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			float a = data1[i][j] - data2[i][j];
			d += a * a;
		}
	}

	return sqrt(d / (N * M));
}



double Distance::Cosine2d(int** data1, int** data2, int N, int M)
{
	double temp1, temp2, cos;
	temp1 = temp2 = cos = 0.;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp1 += data1[i][j] * data1[i][j];
			temp2 += data2[i][j] * data2[i][j];
			cos += data1[i][j] * data2[i][j];
		}
	}

	temp1 = sqrt(temp1);
	temp2 = sqrt(temp2);

	return - cos / (temp1 * temp2);
}


