#include"readTxtFile.h"
#include <cmath>
#include <iostream>
#include <fstream>


ReadTxtFile::ReadTxtFile() {
	LineCnt = ClipCnt = Space = Image_num = 0;
}

ReadTxtFile::~ReadTxtFile(){

}

int ReadTxtFile::TxtFileReaderInt(char name[FILE_NAME_LEN]) {

	LineCnt = ClipCnt = Space = Image_num = 0;

	fstream fin(name, ios::in);
	if (!fin)
	{
		cout << "Cannot open file. Please check the file directory" << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}

	while (fin.get(c)) //get each char in txt
	{

		if (c == '\n') // if get first char  then get next lane 
			LineCnt++;
		if (c == '*') // count * line 
			Space++;;
	}
	Image_num = LineCnt - Space; // give the image num 
	Image_num = Image_num + 1;
	cout << endl;
	cout << "The number of frame is " << Image_num << endl; // out put image num 
	fin.close();
	return Image_num;
}

vector< vector<int> > ReadTxtFile::TxtFileReader(char name[FILE_NAME_LEN]) {

	LineCnt = ClipCnt = Space = Image_num = 0;

	vector< vector<int> > txt;
	vector<int> frame;
	txt.clear();
	frame.clear();

	fstream fin(name, ios::in);
	if (!fin)
	{
		cout << endl;
		cout << "Cannot open file. Please check the file directory" << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}

	while (fin.get(c)) //get each char in txt
	{
		if (c == '\n') {
			frame.push_back(LineCnt);
		}
		else  if (c == '*') { // if char = * then push frame to txt, reset vector frame
			txt.push_back(frame);
			ClipCnt++;
			LineCnt = 0;
			frame.clear();
			cout << frame.size() << endl << endl;
		}
	}
	fin.close();
	return txt;
}
