#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H
#include <iostream>
#include <string>
#include "videoEditor.h"

class ImageEditor {
private:
	string fileName, bmpFileName, imagePath, outputPath, imageNumber;
	int filenum;
public:
	ImageEditor();
	int ImageProcesser();
	void set_filenum(int n) { filenum = n; }
	int get_filenum() const { return filenum; }
};
#endif