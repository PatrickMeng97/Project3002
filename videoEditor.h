#ifndef VIDEOEDITOR_H
#define VIDEOEDITOR_H

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class VideoEditor {
private:

	string videoPath, outputPath;
	long totalFrameNumber;
	long frameToStart;
	long frameToStop;
	bool stop = false;
public:
	int n;
	VideoEditor();
	int VideoProcesser();
	void set_frameToStart(int n) { frameToStart = n; }
	int get_frameToStart() const { return frameToStart; }
	void set_frameToStop(int n) { frameToStop = n; }
	int get_frameToStop() const { return frameToStop; }
	void set_stop(bool n) { stop = n; }
	int get_stop() const { return stop; }
	int get_totalFrameNumber() const { return totalFrameNumber; }
};

#endif
