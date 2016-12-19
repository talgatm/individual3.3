#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
#include <math.h>
using namespace std;
using namespace cv;
void myFunction();
int main() {
    myFunction();
    return 0;
}

void myFunction(){
    Mat img = cvLoadImage("/home/tm/lena.jpg");
    cvtColor(img, img, CV_RGB2GRAY );
    Mat res = img.clone();

    int mask[3][3] = { {-1, -1, -1},
                       {-1, 8, -1},
                       {-1, -1, -1}
    };


    for (int i = 0; i < img.rows-1; i++){
        for (int j = 0; j < img.cols-1; j++){
            int sum = 0;

            for (int k = -1; k < 2; k++){
                for (int l = -1; l < 2; l++){
                    sum += (img.at<uchar>((i+k),(j+l))*mask[k+1][l+1]);
                }
            }

            if (sum < 0){
                sum*=-1;
            }
            if (sum > 255){
                sum = 255;
            }


            res.at<uchar>(i,j) = sum;
        }
    }

    cvNamedWindow("PixelFunction",1);
    imshow("PixelFunction", res);
    waitKey(0);


}
