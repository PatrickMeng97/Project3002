#include"readImageFile.h"
ReadImageFile::ReadImageFile() {

}
ReadImageFile::~ReadImageFile() {

}

BMP_Image** ReadImageFile::ImageFileReader(char name[FILE_NAME_LEN], vector< vector<int> >txt) {
	clips = txt.size();
	fstream fin;

	BMP_Image** img = new BMP_Image * [clips];

	fin.open(name);
	if (line != NULL) {

		for (int c = 1; c < clips; c++) {

			frame = txt[c].size();

			img[c] = new BMP_Image[frame];

			for (int f = 1; f < frame; f++) {
				while (fin.getline(line, FILE_NAME_LEN)) {

					if (line[0] == '*') {
						continue;
					}
					cout << line << endl;
					img[c][f].read(line);
				}
			}
		}
	}else {
		cout << "Failed to load image" << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}
	cout << endl;
	cout << "Finish loading" << endl;
	fin.close();

	return img;
}

BMP_Image** ReadImageFile::ImageFileReaderInt(char name[FILE_NAME_LEN], int frame) {
	clips = 1;
	fstream fin;

	BMP_Image** img = new BMP_Image * [clips];

	fin.open(name);
	if (line != NULL) {


		for (int c = 0; c < clips; c++) {

			img[c] = new BMP_Image[frame];

			for (int f = 0; f < frame; f++) {
				fin.getline(line, FILE_NAME_LEN);
				cout << line << endl;
				img[c][f].read(line);
			}
		}
	}else {
		cout << "Failed to load image" << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}
	cout << endl;
	cout << "Finish loading" << endl;
	fin.close();
	return img;
}
