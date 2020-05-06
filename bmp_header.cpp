#include "bmp_header.h"

bool header::read(ifstream& fin)
{
	fin.read((char*)type, 2);
	fin.read((char*)&file_size, sizeof(int));
	fin.read((char*)&reserved, sizeof(int));
	fin.read((char*)&offset, sizeof(int));
	fin.read((char*)&info_header_size, sizeof(int));
	fin.read((char*)&width, sizeof(int));
	fin.read((char*)&height, sizeof(int));
	fin.read((char*)&planes, sizeof(short int));
	fin.read((char*)&bits_per_pixel, sizeof(short int));
	fin.read((char*)&compression, sizeof(int));
	fin.read((char*)&data_size, sizeof(int));
	fin.read((char*)&h_resolution, sizeof(int));
	fin.read((char*)&v_resolution, sizeof(int));
	fin.read((char*)&colors, sizeof(int));
	fin.read((char*)&important_colors, sizeof(int));
	if (type[0] != 'B' || type[1] != 'M') return 0;
	return 1;
}

void header::write(ofstream& fout)
{
	fout.write((char*)type, 2);
	fout.write((char*)&file_size, sizeof(int));
	fout.write((char*)&reserved, sizeof(int));
	fout.write((char*)&offset, sizeof(int));
	fout.write((char*)&info_header_size, sizeof(int));
	fout.write((char*)&width, sizeof(int));
	fout.write((char*)&height, sizeof(int));
	fout.write((char*)&planes, sizeof(short int));
	fout.write((char*)&bits_per_pixel, sizeof(short int));
	fout.write((char*)&compression, sizeof(int));
	fout.write((char*)&data_size, sizeof(int));
	fout.write((char*)&h_resolution, sizeof(int));
	fout.write((char*)&v_resolution, sizeof(int));
	fout.write((char*)&colors, sizeof(int));
	fout.write((char*)&important_colors, sizeof(int));
}

