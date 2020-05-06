//#include<iostream>
//#include<fstream>
//#include<opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//string input_image_path = "C:\\Users\\Yao\\Desktop\\images\\Final\\bmp\\";
//string image_list = "C:\\Users\\Yao\\Desktop\\images\\Final\\bmp\\b.txt";
//string save_image_path = "C:\\Users\\Yao\\Desktop\\images\\Final\\bmp\\";
//int x = 0;
//int main()
//{
//
//	string name;
//
//	string input_image_name;
//
//	string save_image_name;
//
//
//
//	ifstream str_file(image_list);
//	while (getline(str_file, name))
//	{
//		//单个图片全名
//		input_image_name = input_image_path + name;
//		cout << input_image_name << endl;
//
//
//		x++;
//		cout << x << endl;
//	}
//
//	ofstream OutFile;
//	OutFile.open(image_list); //打开并写入文件
//
//	for (int i = 1; i <= x; i++) {
//		string num;
//		stringstream temp;
//		temp << i;
//		num = temp.str();
//		OutFile << save_image_path + num + ".bmp" + '\n';
//	}
//	return 0;
//}
//
