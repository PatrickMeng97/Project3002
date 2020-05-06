#include "imageEditor.h"
#include "videoEditor.h"
#include<istream>


ImageEditor::ImageEditor()
{
}

int ImageEditor::ImageProcesser() {

	cout << endl;
	cout << "Please give the image path" << endl;
	cin >> imagePath;

	cout << endl;
	cout << "Please give the out put path" << endl;
	cin >> outputPath;

	cout << endl;
	cout << "Please give total file numbers " << endl;
	cin >> filenum;



	for (int i = 1; i <= filenum; i++) {

		//int to string
		stringstream stringSteam;
		stringSteam << i;
		stringSteam >> imageNumber;


		fileName = imagePath + "\\" + imageNumber + ".png";
		bmpFileName = outputPath + "\\" + imageNumber + ".bmp";
		cout << bmpFileName << endl;

		Mat srcImage = imread(fileName), grayImage;

		if (srcImage.empty()) {
			cout << endl;
			cout << "Cannot open image. Please check the file folder directory" << endl;
			cout << "Quitting Program" << endl;
			system("pause");
			exit(1);
		}
		cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
		resize(grayImage, grayImage, Size(300, 300), 300., 300, 1);
		imwrite(bmpFileName, grayImage);

		srcImage.~Mat();
	}

	cout << endl;
	cout << "Image conversion finished" << endl;

	return 0;
}

