#include "FilterGrayscale.h"

#include <opencv/cv.h>

FilterGrayscale::FilterGrayscale() :
    Filter()
{
}

FilterGrayscale::~FilterGrayscale() {}

QImage FilterGrayscale::process(const QImage& image)
{
    // QImage => cv::mat
    cv::Mat tmp(image.height(),
                image.width(),
                CV_8UC4,
                (uchar*)image.bits(),
                image.bytesPerLine());

    cv::Mat resultMat;
    cv::cvtColor(tmp, resultMat, CV_BGR2GRAY);

    // cv::mat => QImage
    QImage resultImage((const uchar *) resultMat.data,
                       resultMat.cols,
                       resultMat.rows,
                       resultMat.step,
                       QImage::Format_Grayscale8);
    return resultImage.copy();
}
