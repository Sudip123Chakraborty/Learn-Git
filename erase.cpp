#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace cv;
using namespace std;

Mat img;

bool isvalid(int i,int j)
{
	if(i<0||j<0||i>img.rows||j>img.cols)
		return false;
	return true;
}
int main(int argc,char** argv)
{
	img = imread(argv[1],0);
	Mat img1 = imread(argv[1],0);
	namedWindow("original",0);
	imshow("original",img);
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			bool condition=true;
			for(int k=i-2;k<i+3;k++)
			{
				for(int l=j-2;l<j+3;l++)
				{
					if(isvalid(k,l))
					{
						condition = condition*(img.at<uchar>(k,l)>230);
					}
				}
			}
			if(condition)
					img1.at<uchar>(i,j)=255;
			else
					img1.at<uchar>(i,j)=0;
			}
		}
	namedWindow("final",0);
	imshow("final",img1);
	imwrite("erode1.png",img1);
	waitKey();
}
