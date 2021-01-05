#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace cv;
using namespace std;
Mat img,img1;

void update_img(int t,void *a)
{
Canny(img1,img,t,t*3,5);
imshow("win",img);

}

int main(int argc,char** argv)
{
int lowerth;
img1=imread(argv[1],0);
namedWindow("win",WINDOW_NORMAL);
createTrackbar("CONTRAST_PARAMETER","win",&lowerth,255,update_img);
imwrite("circle1.jpg",img1);
waitKey(0000);
return 0;
}
