#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);

int main() {
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();

	HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}

int HW01_TestFunction() {
	Mat img = imread("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/lena.jpg");
	Mat BinaryImage;
	Mat GrayImage;
	namedWindow ("InputImage");
	namedWindow("GrayImage");
	namedWindow("BinaryImage");

	cvtColor(img, GrayImage, CV_BGR2GRAY);
	cv::threshold(GrayImage, BinaryImage, 100.0, 255.0, THRESH_BINARY);
	imshow("InputImage", img);
	imshow("GrayImage", GrayImage);
	imshow("BinaryImage", BinaryImage);
	moveWindow("InputImage", 20, 20);
	moveWindow("GrayImage", 500, 20);
	moveWindow("BinaryImage", 900,20);
	waitKey(0);
	destroyWindow("InputImage");
	destroyWindow("GrayImage");
	destroyWindow("BinaryImage");

	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {
	vector<string>pic;
	pic.push_back("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/capture/1.jpg");
	pic.push_back("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/capture/2.jpg");
	pic.push_back("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/capture/3.jpg");
	pic.push_back("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/capture/4.jpg");
	pic.push_back("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/capture/5.jpg");
	pic.push_back("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/capture/6.jpg");
	pic.push_back("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/capture/7.jpg");
	pic.push_back("C:/Users/user/Desktop/opencv-1and2-shihlun1208/testImage/capture/8.jpg");


	int i;
	for (i = 0; i < numberOfImgs; i++)
	{
		Mat img = imread(pic[i]);

		Mat GrayImage;
		cvtColor(img, GrayImage, CV_BGR2GRAY);

		Mat BinaryImage;
		cv::threshold(GrayImage, BinaryImage, 100.0, 255.0, THRESH_BINARY);

		imshow("InputImage", img);
		imshow("GrayImage", GrayImage);
		imshow("BinaryImage", BinaryImage);
		
		moveWindow("InputImage", 0, 20);
		moveWindow("GrayImage", 500, 20);
		moveWindow("BinaryImage", 900, 20);

		while(true){
		char key = waitKey(0);   
		if (key == 13) {
			destroyAllWindows();
			break;
			}
		}
	}
	return 0;
} 