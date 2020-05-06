#ifndef BMP_H
#define BMP_H
#include <fstream>
using std::ifstream;
using std::ofstream;

// BMP header
class header {
public:
	// read & write the header with given file stream
	bool read(ifstream& fin);
	void write(ofstream& fin);

	// get information of the image
	int get_height() const { return height; }
	int get_width() const { return width; }
	short int get_bits() const { return bits_per_pixel; }

private:
	// BMP header structure
	char type[2];
	int file_size;
	int reserved;
	int offset;
	int info_header_size;
	int width;
	int height;
	short int planes;
	short int bits_per_pixel;
	int compression;
	int data_size;
	int h_resolution;
	int v_resolution;
	int colors;
	int	important_colors;
};
#endif
