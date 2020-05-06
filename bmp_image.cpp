#include "bmp_image.h"
#include <fstream>
#include <iostream>
using namespace std;
using std::ifstream; using std::ofstream; using std::ios;

BMP_Image::BMP_Image()
{
	b_data = g_data = r_data = 0;
}

BMP_Image::BMP_Image(char* fname)
{
	b_data = g_data = r_data = 0;
	read(fname);
}

BMP_Image::~BMP_Image()
{
	if (b_data) {
		for (int i = 0; i < header.get_height(); i++) {
			delete[] b_data[i];
			delete[] g_data[i];
			delete[] r_data[i];
		}
		delete[] b_data;
		delete[] g_data;
		delete[] r_data;
	}
}

void BMP_Image::read(char* fname)
{
	ifstream fin(fname, ios::binary);
	if (!fin) {
		cout << endl;
		cout << "Cannot open image. Please check the image directory in text file" << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}

	// load header
	if (!header.read(fin)) {
		cout << "Failed to load image " << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}

	// allocate space for image data
	b_data = new  int* [get_height()];
	g_data = new  int* [get_height()];
	r_data = new  int* [get_height()];
	for (int i = 0; i < get_height(); i++) {
		b_data[i] = new  int[header.get_width()];
		g_data[i] = new  int[header.get_width()];
		r_data[i] = new  int[header.get_width()];
	}

	// pad zeros at the end of each row so it is multiple of 4 bytes long
	int num_zeros = 4 - (header.get_width() * (header.get_bits() / 8) % 4);
	if (num_zeros == 4) num_zeros = 0;

	// load the image data row by row 
	for (int i = get_height() - 1; i >= 0; i--) {
		unsigned char b, g, r;
		for (int j = 0; j < header.get_width(); j++) {
			// read pixel values at (i,j)
			fin.read((char*)&b, 1);
			fin.read((char*)&g, 1);
			fin.read((char*)&r, 1);
			// for greyscale image: r = g = b
			b_data[i][j] = b;
			g_data[i][j] = g;
			r_data[i][j] = r;
		}

		// read padded zeros at the end of the row if any
		for (int j = 0; j < num_zeros; j++)
			fin.read((char*)&b, 1);
	}
	fin.close();
}

void BMP_Image::save(char* fname)
{
	ofstream fout(fname, ios::binary);
	// write header
	header.write(fout);

	// pad zeros at the end of each row so it is multiple of 4 bytes long
	int num_zeros = 4 - (header.get_width() * (header.get_bits() / 8) % 4);
	if (num_zeros == 4) num_zeros = 0;

	// write image data row by row 
	for (int i = header.get_height() - 1; i >= 0; i--) {
		unsigned char b, g, r;
		for (int j = 0; j < header.get_width(); j++) {
			b = b_data[i][j];
			g = g_data[i][j];
			r = r_data[i][j];
			// write pixel values at (i,j)
			fout.write((char*)&b, 1);
			fout.write((char*)&g, 1);
			fout.write((char*)&r, 1);
		}
		// write padded zeros at the end of the row if any
		b = 0;
		for (int j = 0; j < num_zeros; j++)
			fout.write((char*)&b, 1);
	}
	fout.close();
}

void BMP_Image::get_pixel(int i, int j, int& b, int& g, int& r)
{
	b = b_data[i][j];
	g = b_data[i][j];
	r = b_data[i][j];
}

int BMP_Image::get_gry_pixel(int i, int j, int& b) {
	b = b_data[i][j];
	return b;
}

void BMP_Image::set_pixel(int i, int j, int b, int g, int r)
{
	if (i >= 0 && i < header.get_height() && j >= 0 && j < header.get_width()) {
		b_data[i][j] = (b >= 0 && b <= 255) ? b : b_data[i][j];
		g_data[i][j] = (g >= 0 && g <= 255) ? g : g_data[i][j];
		r_data[i][j] = (r >= 0 && r <= 255) ? r : r_data[i][j];
	}
}
