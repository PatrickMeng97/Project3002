#include"DCT.h"
#include"bmp_image.h"

DCT::DCT() {

}

DCT::DCT(int M, int N) {
	this->M = M;
	this->N = N;
	int pi = 3.1415926;
}


int** DCT::cDCT(int** img, int M, int N) {

	int** d = new int* [M];

	for (int m = 0; m < M; m++) {
		d[m] = new int[N];
		for (int n = 0; n < N; n++) {
			d[m][n] = 0.;
			for (int i = 0; i < M; i++) {
				float a = cos(pi * (i + 0.5) * m / M);
				for (int j = 0; j < N; j++)
					d[m][n] += img[i][j] * a * cos(pi * (j + 0.5) * n / N);
			}
		}
	}
	return d;
}

int** DCT::calDCT(BMP_Image** img, int x,int y) {

		int** d = new int* [M];

		for (int m = 0; m < M; m++) {
			d[m] = new int[N];
			for (int n = 0; n < N; n++) {
				d[m][n] = 0.;
				for (int i = 0; i < M; i++) {
					float a = cos(pi * (i + 0.5) * m / M);
					for (int j = 0; j < N; j++)
						d[m][n] += img[x][y].b_data[i][j] * a * cos(pi * (j + 0.5) * n / N);
				}
			}
		}
	return d;
}

BMP_Image** DCT::imageConvert(BMP_Image** img, int x, int y) {

	int frame = y;
	int clip = x;
	BMP_Image** dct = new BMP_Image * [clip];
	for (int i = 0; i < clip; i++) {
		dct[i] = new BMP_Image[frame];
		for (int j = 0; j < frame; j++) {
			int** dc = calDCT(img, i, j);
			dct[i][j].b_data = dc;
		}
	}
	return dct;
}