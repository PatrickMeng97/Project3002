#ifndef DCT_H
#define DCT_H
        
#include"bmp_image.h"

class DCT {
private:
	int M, N;
	int pi;

public:
	DCT();
	DCT(int M, int N);
	int** calDCT(BMP_Image** img, int x, int y);
	int** cDCT(int** img, int M, int N);
	BMP_Image** imageConvert(BMP_Image** img, int x, int y);
};

#endif