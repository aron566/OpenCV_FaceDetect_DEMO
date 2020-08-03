#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <opencv2/face.hpp>
using namespace  cv;
using namespace cv::face;
using namespace std;

int main(int argc, char *argv[])
{
    /*消除未使用参数编译警告*/
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    VideoCapture Camera(0);

    namedWindow("src",WINDOW_AUTOSIZE);

    CascadeClassifier DetectModule;

    /*载入训练数据集*/
    bool ret = DetectModule.load("haarcascade_frontalface_alt.xml");
    if(ret == true)
    {
        qDebug() << "load xml file ok";
    }
    else
    {
        qDebug() << "load xml file error";
        return -1;
    }
    int KeyValue = 0;
    Mat src;
    Mat dst;
    Mat dstBlack;
    vector<Rect> faces;
    Mat image;
    Mat imageout;
    int count = 1;
    while(Camera.read(src))
    {
        /*转为灰度图像*/
        cvtColor(src,dst,COLOR_BGR2GRAY);

        /*构建一张与dst一样大小的，纯黑图片*/
        dstBlack = Mat::zeros(dst.size(),dst.type());

        /*直方图均衡化->增强图像对比度
          -直方图是图像中像素强度分布的图形表达方式.
          -它统计了每一个强度值所具有的像素个数.
        */
        equalizeHist(dst,dstBlack);

        /*匹配人脸信息，加入到faces向量表*/
        DetectModule.detectMultiScale(dstBlack,faces,1.1,3,0,Size(50,50));

        /*检测到人脸数量*/
        qDebug() << "Can Check Face Num :"<< faces.size();

        for(unsigned long long i = 0;i < faces.size();i++)
        {
            /*在原始彩图上绘制矩形框，红色，线条8*/
            rectangle(src,faces[i],Scalar(0,0,255),2,LINE_8,0);

            /*设置新图片为检测到的脸部矩形区域大小*/
            image = src(Rect(faces[i].x,faces[i].y,faces[i].width, faces[i].height));

            /*再次调整至统一100*100像素大小*/
            resize(image,imageout,Size(100,100));

            /*保存为jpg图片*/
            imwrite(format("rrr%d.jpg",count),imageout);

            count++;
        }

        imshow("src",src);

        /*延时30ms，按下esc时停止程序*/
        KeyValue = waitKey(30);
        if(KeyValue == 27)
        {
            break;
        }
    }
    waitKey(0);
    return 0;
}
