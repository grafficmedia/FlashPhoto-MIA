//
// Tool.cpp
// Created by Jacob Grafenstein
//

#include <iostream>
#include <cstring>
#include "Tool.h"

using std::cerr;
using std::endl;
using std::fill;

/*Tool::Tool() {
  //we won't need this unless it does something, right now it just causes an error
}*/

bool Tool::isActive() {
  return active;
}

int Tool::getMaskSize() {
  return maskSize;
}

int Tool::getPixel(int x,int y)
{
	if (x>=0 && y>=0 && x<maskSize && y<maskSize)
	{
		return mask[x][y];
	}
	else
	{
		return -1;
	}
}

void Tool::paintMask(int x,int y,ColorData *displayBuffer,int width,int height,ColorData color,ColorData backgroundColor)
{//default paintMask function, can be overwritten for tools like eraser
	int i,j,bufferI,bufferJ;
	for (i=0;i<maskSize;i++)
	{
		for (j=0;j<maskSize;j++)
		{
			bufferI = i - (maskSize/2) - 1;
			bufferJ = j - (maskSize/2) - 1;
                        if ((bufferI > 0) && (bufferI < width) && (bufferJ > 0) && (bufferJ < height))
                        {//make sure width and length are right, be prepared to swap if necessary
				displayBuffer[bufferI*maskSize + bufferJ] = displayBuffer[bufferI*maskSize + bufferJ] * (1 - getPixel(x,y));
				displayBuffer[bufferI*maskSize + bufferJ] = displayBuffer[bufferI*maskSize + bufferJ] + (color * getPixel(x,y));
			}
		}
	}
}
