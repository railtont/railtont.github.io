#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
	Mat image;
	Vec3b val;

	image= imread("biel.png",CV_LOAD_IMAGE_COLOR);
	if(!image.data){
		cout << "imagem não abriu" << endl;
		return 0;
	}

	int x1, x2, y1, y2;
	cout << "Digite o canto superior direito da imagem (x e y): ";
	cin >> x1 >> y1;
	cout << "Digite o canto infeior esquerdo da imagem (x e y): ";
	cin >> x2 >> y2;
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
	
	//Caso as coordenadas estajem fora do tamanho da imagem
	x1= min(x1, image.rows);
	x1= max(x1, 0);
	x2= min(x2, image.rows);
	x2= max(x2, 0);
	y1= min(y1, image.cols);
	y1= max(y1, 0);
	y2= min(y2, image.cols);
	y2= max(y2, 0);
	
	namedWindow("janela",WINDOW_AUTOSIZE);
	cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			for(int k=0; k<3; k++)
				image.at<Vec3b>(i,j)[k]= 255 - image.at<Vec3b>(i,j)[k];

	imshow("janela", image);  
	waitKey();
	return 0;
}
