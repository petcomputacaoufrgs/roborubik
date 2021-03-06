#include "../include/CubeView.h"

#include <cstdio>


CubeView::CubeView(int cameraID) : CameraView(cameraID)
{
    //ctor
    for(int row = 0; row < SIDESIZE; row++)
        for(int col =0; col < SIDESIZE; col++)
        {
            cv::Point2i topLeft = cv::Point_<int>((this->currentFrame->cols*(1+4*col)/12),
                                                  this->currentFrame->rows*(1+4*row)/12);
            cubeSide[row][col] = CubeSquare(topLeft,cv::Size_<int>(this->currentFrame->cols/6,this->currentFrame->rows/6),this->currentFrame);
        }
}

CubeView::CubeView() : CameraView()
{
    //ctor
    for(int row = 0; row < SIDESIZE; row++)
        for(int col =0; col < SIDESIZE; col++)
        {
            cv::Point2i topLeft = cv::Point_<int>((this->currentFrame->cols*(1+4*col)/12),
                                                  this->currentFrame->rows*(1+4*row)/12);
            cubeSide[row][col] = CubeSquare(topLeft,cv::Size_<int>(this->currentFrame->cols/6,this->currentFrame->rows/6),this->currentFrame);
        }
}

CubeView::~CubeView()
{
    //dtor
}

void CubeView::updateFrame()
{
    this->CameraView::updateFrame();
}

void CubeView::printRectangles()
{

    for(int row = 0; row < SIDESIZE; row++)
        for(int col =0; col < SIDESIZE; col++)
        {
            cubeSide[row][col].showRectangle();
        }
}

void CubeView::printColors()
{
    for(int row = 0; row < SIDESIZE; row++)
    {
        for(int col =0; col < SIDESIZE; col++)
        {
            printf("colorCode: %c", cubeSide[row][col].getColorCode());
        }
        printf("\n");
    }
}
