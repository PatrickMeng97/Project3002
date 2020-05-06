#ifndef READIMAGEFILE_H
#define READIMAGEFILE_H
#include<iostream>                                                                                                       
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iomanip>
#include"bmp_image.h"
#include<vector>

using namespace std;

#define FILE_NAME_LEN 100


class ReadImageFile {
private:

	char c;
	char line[FILE_NAME_LEN]; //image file name 
	char file[FILE_NAME_LEN];
	int frame; // total num in txt file 
	int clips; // clip number

	char name[FILE_NAME_LEN];

public:

	ReadImageFile();
	~ReadImageFile();
	BMP_Image** ImageFileReaderInt(char name[FILE_NAME_LEN], int frame);
	BMP_Image** ImageFileReader(char name[FILE_NAME_LEN], vector< vector<int> >txt);
};
#endif 