#ifndef READTXTFILE_H
#define READTXTFILE_H
#include<iostream>                                                                                                       
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<vector>
using namespace std;

#define FILE_NAME_LEN 100


class ReadTxtFile {
private:

	char c;
	int LineCnt; // total num in txt file 
	int ClipCnt; // clip number
	int Space; // *line num in txt file 
	int Image_num; // blink image num in txt file
	char name[FILE_NAME_LEN];

public:

	ReadTxtFile();
	~ReadTxtFile();
	int TxtFileReaderInt(char name[FILE_NAME_LEN]);
	vector< vector<int> > TxtFileReader(char name[FILE_NAME_LEN]);
	int get_framesNum() const { return  Image_num; }
};
#endif 