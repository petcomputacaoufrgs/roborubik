#ifndef CUBEVIEW_H
#define CUBEVIEW_H

#include "opencv2/highgui/highgui.hpp"

#include "CameraView.h"
#include "CubeSquare.h"

#define SIDESIZE 3     ///size of a cube side, in squares


class CubeView : public CameraView
{
    public:
        //constructors
        CubeView();
        CubeView(int cameraID);

        //destructor
        virtual ~CubeView();

        //methods
        cv::Mat getCubeView();
        void printColors();
        string getColors();
        void updateFrame();
        void printRectangles();
        CubeSquare cubeSide[SIDESIZE][SIDESIZE];   ///represents a side of the cube, where the first index is the index of the row and the second of the line of the square in the cube
        void initColors();
    protected:
    private:
};

#endif // CUBEVIEW_H
