#include"bmp_header.h"
#include"bmp_image.h"
#include"videoEditor.h"
#include"imageEditor.h"
#include"readTxtFile.h"
#include"readImageFile.h"
#include"distance.h"
#include"DTW.h"
#include"DCT.h"
#include"zncc.h"
#include"druation.h"

char nTxtname[FILE_NAME_LEN]; // no blink txt file name 
char bTxtname[FILE_NAME_LEN];
char tTxtname[FILE_NAME_LEN];
int n_frame, b_frame, t_frame;
int clip = 1;
char a,b,c;
int video_FPS = NULL;
int main() {

	

	Druation du;
    VideoEditor ve;
    ImageEditor ie;
	ReadTxtFile rt;
	ReadImageFile ri;
	
	cout << "Do you want to edit video?" << endl;
	cout << "Please enter Y for yes, N for no" << endl;
	cin >> a;

	switch (a)
	{
	case 'y' :
			video_FPS = ve.VideoProcesser();
			break;
	case 'Y':
		video_FPS = ve.VideoProcesser();
		break;
	case 'n' :
		break;
	case  'N' :
		break;
	default :
		cout << endl;
		cout << "Invalid Input " << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}

	cout << endl;
	cout << "Do you want to edit image?" << endl;
	cout << "Please enter Y for yes, N for no" << endl;
	cin >> b;

	switch (b)
	{
	case 'y' :
		ie.ImageProcesser();
		break;
	case 'Y' :
		ie.ImageProcesser();
		break;
	case 'n' :
		break;
	case 'N':
		break;
	default:
		cout << endl;
		cout << "Invalid Input " << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}

	cout << endl;
	cout << "Do you want to continue detection?" << endl;
	cout << "Please enter Y for yes, N for no" << endl;
	cin >> c;

	switch (c)
	{
	case 'y' :
		break;
	case 'Y':
		break;
	case 'n' :
		cout << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	case 'N':
		cout << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	default:
		cout << endl;
		cout << "Invalid Input " << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}


	// read multiple clips of frames 
	// vector< vector<int> >n_txt;
	// vector< vector<int> >b_txt;

	// load no blink frames
	cout << "Please give the no blink txt file name" << endl;
	cin >> nTxtname;
	n_frame = rt.TxtFileReaderInt(nTxtname);
	BMP_Image** n_img = ri.ImageFileReaderInt(nTxtname, n_frame);
	// n_txt = rt.TxtFileReader(nTxtname);
	// BMP_Image** n_img = ri.ImageFileReader(nTxtname, n_txt);

	// load blink frames
	cout << "Please give the blink txt file name" << endl;
	cin >> bTxtname;
	b_frame = rt.TxtFileReaderInt(bTxtname);
	BMP_Image** b_img = ri.ImageFileReaderInt(bTxtname, b_frame);
	// b_txt = rt.TxtFileReader(bTxtname);
	// BMP_Image** b_img = ri.ImageFileReader(bTxtname, b_txt);

	// load test frames
	cout << "Please give the test txt file name" << endl;
	cin >> tTxtname;
	t_frame = rt.TxtFileReaderInt(tTxtname);
	BMP_Image** t_img = ri.ImageFileReaderInt(tTxtname, t_frame);
	// t_txt = rt.TxtFileReader(tTxtname);
	// BMP_Image** t_img = ri.ImageFileReader(tTxtname, t_txt);

	// create DTW
	int Ymin = t_frame - 1;
	int Ymax = t_frame - 1;
	int X = b_frame - 1;
	DTW  dtw = DTW(Ymin,Ymax,X);
	double temp1 = dtw.znccDTW(n_img, t_img);
	double temp2 = dtw.znccDTW(b_img, t_img);

	// print the result
	if (temp1 > temp2) {
	cout << endl;
	cout << "Test image have blink" << endl;

		if (video_FPS == NULL) {

			//calculate eye blink duration
			cout << "Please give the FPS of the video" << endl;
			cin >> video_FPS;	
			double a = t_frame;
			double b = video_FPS;
			cout.setf(ios::fixed);
			cout << "Eye blink duration is "  << setprecision(1) << du.calDruation(a, b) << " second" << endl;

			ofstream of("Result.txt", ios::app);
			of << "Test image have blink" << endl;
			of << "Eye blink duration is " << setprecision(1) << du.calDruation(a, b) << " second" << endl;
			of << "----------------------------------------------------------------------------------------------------- " << endl;
			of << endl;
			of.close();
		}else {
			double a = t_frame;
			double b = video_FPS;
			cout.setf(ios::fixed);
			cout << "Eye blink duration is " << setprecision(1) << du.calDruation(a, b) << " second" << endl;

			ofstream of("Result.txt", ios::app);
			of << "Test image have blink" << endl;
			of << "Eye blink duration is " << setprecision(1) << du.calDruation(a, b) << " second" << endl;
			of << "-----------------------------------------------------------------------------------------------------" << endl;
			of << endl;
			of.close();
		}

	}else {
	cout << endl;
	cout << "Test image have no blink" << endl;

		ofstream of("Result.txt", ios::app);
		of << "Test image have no blink" << endl;
		of << "-----------------------------------------------------------------------------------------------------" << endl;
		of << endl;
		of.close();
	}

	// Distance test
	// Distance dist;
	// Zncc zn;

	// cout << "Test" << zn.calZncc(b_img[0][0].b_data, n_img[0][0].b_data, 300, 300) << endl;
	// cout << "Test" << zn.calZncc(b_img[0][1].b_data, n_img[0][1].b_data, 300, 300) << endl;
	// cout << "Test"<< dist.Euclidean2d(b_img[0][0].b_data, n_img[0][0].b_data, 300, 300) << endl;
	// cout << "Test" << dist.Euclidean2d(b_img[0][1].b_data, n_img[0][1].b_data, 300, 300) << endl;


}