#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
	Mat image, aux;
	Vec3b val;

	image= imread("biel.png",CV_LOAD_IMAGE_COLOR);
	aux= imread("biel.png",CV_LOAD_IMAGE_COLOR);
	if(!image.data){
		cout << "imagem não abriu" << endl;
		return 0;
	}
	
	for(int i=0; i<image.rows; i++){
		for(int j=0; j<image.cols/2; j++)
			aux.at<Vec3b>(i,j)= image.at<Vec3b>(i, (image.cols+1)/2+j);
		for(int j=image.cols/2; j<image.cols; j++)
			aux.at<Vec3b>(i,j)= image.at<Vec3b>(i, j-image.cols/2);
	}
	
	for(int i=0; i<image.rows; i++)
		for(int j=0; j<image.cols; j++)
			image.at<Vec3b>(i,j)= aux.at<Vec3b>(i,j);
	for(int j=0; j<image.cols; j++){
		for(int i=0; i<image.rows/2; i++)
			aux.at<Vec3b>(i,j)= image.at<Vec3b>((image.rows+1)/2+i, j);
		for(int i=image.rows/2; i<image.rows; i++)
			aux.at<Vec3b>(i,j)= image.at<Vec3b>(i-image.rows/2, j);
	}
	
	namedWindow("janela",WINDOW_AUTOSIZE);
	imshow("janela", aux);  
	waitKey();
	return 0;
}
