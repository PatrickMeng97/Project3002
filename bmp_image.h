#ifndef BMPIM_H
#define BMPIM_H
#include "bmp_header.h"

class BMP_Image {
public:
	// constructors
	BMP_Image();
	BMP_Image(char* fname);
	// destructor
	~BMP_Image();

	// read & save an image with given fname
	void read(char* fname);
	void save(char* fname);

	// get information of the image
	int get_height() { return header.get_height(); }
	int get_width() { return header.get_width(); }

	// get/set pixel values at (i,j)
	void get_pixel(int i, int j, int& b, int& g, int& r);
	int get_gry_pixel(int i, int j, int& b);
	void set_pixel(int i, int j, int b, int g, int r);


	// image header & data
	header header;
	int** b_data, ** g_data, ** r_data;
};
#endif
