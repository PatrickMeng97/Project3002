#include "opencv2/opencv.hpp"
#include "videoEditor.h"
#include<istream>



VideoEditor::VideoEditor()
{
}

int VideoEditor::VideoProcesser() {

	cout << endl;
	cout << "Please give the video path " << endl;
	cin >> videoPath;
	cout << endl;
	cout << "Please give the out put path " << endl;
	cin >> outputPath;

	//open video file
	VideoCapture capture(videoPath);
	//check the file is open or not£¬isOpened return ture

	if (!capture.isOpened()) {
		cout << endl;
		cout << "Cannot open video. Please check the file directory." << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}



	//get all frames 
	totalFrameNumber = capture.get(CAP_PROP_FRAME_COUNT);
	cout << endl;
	cout << "This video have " << totalFrameNumber << " frames" << endl;


	//set frame to start 
	cout << endl;

	cout << "Please give frame number to start" << endl;
	cin >> frameToStart;
	capture.set(CAP_PROP_POS_FRAMES, frameToStart);
	cout << endl;

	/*frameToStop = totalFrameNumber;*/

	//get frame to stop
	cout << endl;
	cout << "Please give frame to stop" << endl;
	cin >> frameToStop;
	if (frameToStop < frameToStart)
	{
		cout << "Invalid frame stop number" << endl;
		cout << "Quitting Program" << endl;
		system("pause");
		exit(1);
	}

	//get fps 
	double rate = capture.get(CAP_PROP_FPS);
	cout << endl;
	cout << "The FPS of this video is " << rate << endl;

	//get every frames
	Mat frame;

	//the delay between two frames:
	//int delay = 1000/rate;
	double delay = 1000 / rate;


	//use while loop read frames

	long currentFrame = frameToStart;


	while (!stop)
	{
		//read next frames
		if (!capture.read(frame))
		{
			cout << "Frame read failed" << endl;
			abort();
		}


		cout << "Processing the " << currentFrame << " frames" << endl;

		stringstream str;
		str << currentFrame << ".png";        /*images store*/

		imwrite(outputPath + "\\" + str.str(), frame);

		//waitKey(intdelay=0) when delay¡Ü 0will wait forever£»when delay>0 will delay delay second

		int c = waitKey(delay);
		//reach the end frames quie 
		if (currentFrame > frameToStop-1)
		{
			stop = true;
		}
		//wait key 
		if (c >= 0)
		{
			waitKey(0);
		}
		currentFrame++;
	}

	//close video caoture
	capture.release();
	cout << endl;
	cout << "Video conversion finished" << endl;
	return rate;
}