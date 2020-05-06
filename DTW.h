#ifndef DTW_H
#define DTW_H
#include"bmp_image.h"

class DTW {
private:
	int Ymin, Ymax, X;
	int d_len;

public:
	DTW();
	DTW(int Ymin, int Ymax, int X);
	double euDTW(BMP_Image** data1, BMP_Image** data2);
	double cosDTW(BMP_Image** data1, BMP_Image** data2);
	double znccDTW(BMP_Image** data1, BMP_Image** data2);
};
#endif // !DTW_H
