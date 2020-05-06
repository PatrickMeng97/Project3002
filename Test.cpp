//#include"bmp_header.h"
//#include"bmp_image.h"
//#include"videoEditor.h"
//#include"imageEditor.h"
//#include"readTxtFile.h"
//#include"readImageFile.h"
//#include"distance.h"
//#include"DTW.h"
//#include"DCT.h"
//#include"zncc.h"
//
//char Textname[FILE_NAME_LEN]; // no blink txt file name 
//int frame;
//int clip = 1;
//
//
//char nTxtname[FILE_NAME_LEN]; // no blink txt file name 
//char bTxtname[FILE_NAME_LEN];
//char tTxtname1[FILE_NAME_LEN];
//char tTxtname2[FILE_NAME_LEN];
//int n_frame, b_frame, t_frame1, t_frame2;
//
//int main() {
//
//	ReadTxtFile rt;
//	ReadImageFile ri;
//	//// DCT TEST
//
//	//cout << "Give the test text file name" << endl;
//	//cin >> Textname;
//	//frame = rt.TxtFileReaderInt(Textname);
//	//BMP_Image** img = ri.ImageFileReaderInt(Textname, frame);
//
//	//DCT dct = DCT();
//	//int** cdct = dct.cDCT(img[0][0].b_data,50,50);
//	//cout << endl;
//	//cout << "The first pixel value before DCT is "<<img[0][0].b_data[2][2]<<endl ;
//
//	//cout << "The first pixel value after DCT is " << cdct[2][2] << endl;
//
//	//cout << endl;
//
//	//cout << "The centra pixel value before DCT is " << img[0][0].b_data[30][30] << endl;
//
//	//cout << "The centra pixel value after DCT is " << cdct[30][30] << endl;
//
//	//cout << endl;
//
//	//cout << "The last pixel value before DCT is " << img[0][0].b_data[48][48] << endl;
//
//	//cout << "The last pixel value after DCT is " << cdct[48][48] << endl;
//
//
//	//// mutipal 
//
//	//cout << "Please give the test image txt file name" << endl;
//	//cin >> nTxtname;
//	//n_frame = rt.TxtFileReaderInt(nTxtname);
//	//BMP_Image** n_img = ri.ImageFileReaderInt(nTxtname, n_frame);
//
//	//DCT dct1 = DCT(50, 50);
//
//
//	//BMP_Image** dct_n = dct1.imageConvert(n_img, clip, n_frame);
//	//cout << endl;
//	//cout << "Image 1 pixel value after DCT is " << dct_n[0][0].b_data[30][30] <<endl;
//	//cout << "Image 2 pixel value after DCT is " << dct_n[0][1].b_data[30][30] << endl;
//	//cout << endl;
//
//	// DTW TEST
//
//	// load no blink data
//	cout << "Give the no blink txt file name" << endl;
//	cin >> nTxtname;
//	n_frame = rt.TxtFileReaderInt(nTxtname);
//	BMP_Image** n_img = ri.ImageFileReaderInt(nTxtname, n_frame);
//
//	// load blink data
//	cout << "Give the blink txt file name" << endl;
//	cin >> bTxtname;
//	b_frame = rt.TxtFileReaderInt(bTxtname);
//	BMP_Image** b_img = ri.ImageFileReaderInt(bTxtname, b_frame);
//
//	//load test data 1
//	cout << "Give the test1 txt file name" << endl;
//	cin >> tTxtname1;
//	t_frame1 = rt.TxtFileReaderInt(tTxtname1);
//	BMP_Image** t_img1 = ri.ImageFileReaderInt(tTxtname1, t_frame1);
//
//	//load test data 2
//	cout << "Give the test2 txt file name" << endl;
//	cin >> tTxtname2;
//	t_frame2 = rt.TxtFileReaderInt(tTxtname2);
//	BMP_Image** t_img2 = ri.ImageFileReaderInt(tTxtname2, t_frame2);
//
//	DTW  dtw = DTW(6, 6, 13);
//
//
//	double temp1 = dtw.znccDTW(t_img1, n_img);
//	double temp2 = dtw.znccDTW(t_img1, b_img);
//
//	double temp3 = dtw.znccDTW(t_img2, n_img);
//	double temp4 = dtw.znccDTW(t_img2, b_img);
//
//	if (temp1 > temp2) {
//		cout << "Test1 image have blink" << endl;
//	}
//	else {
//		cout << "Test1 image have no blink" << endl;
//	}
//
//
//	if (temp3 > temp4) {
//		cout << "Test2 image have blink" << endl;
//	}
//	else {
//		cout << "Test2 image have no blink" << endl;
//	}
//
//}