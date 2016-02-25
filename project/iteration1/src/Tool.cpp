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

float Tool::getPixel(int x,int y)
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

void Tool::paintMask(int x,int y,PixelBuffer **displayBuffer,ColorData color,ColorData backgroundColor)
{//default paintMask function, can be overwritten for tools like eraser
	int i,j,bufferI,bufferJ,width,height;
	width = (*displayBuffer)->getWidth();
	height = (*displayBuffer)->getHeight();
	ColorData tempPixel;
	for (i=0;i<maskSize;i++)
	{
		for (j=0;j<maskSize;j++)
		{
			bufferI = x + i - (maskSize/2) - 1;
			bufferJ = y + j - (maskSize/2) - 1;
                        if ((bufferI > 0) && (bufferI < width) && (bufferJ > 0) && (bufferJ < height))
                        {//make sure width and length are right, be prepared to swap if necessary
				tempPixel = (**displayBuffer).getPixel(bufferI,height - bufferJ) * (1 - getPixel(i,j));
				(**displayBuffer).setPixel(bufferI,height - bufferJ,tempPixel + (color * getPixel(i,j)));
			}
		}
	}
	if (previousX == NULL || previousY == NULL) {
		previousX = x;
		previouxY = y;
	} else {
		fillLine(x,y);
		previouxX = x;
		previouxY = y;
	}
}

void Tool::fillLine(int x, int y) {
	float slope = (previousX - x)/(previousY - y);
	int newX = x++;
	
}

void Tool::setPreviousPointToNull() {
	previousX = NULL;
	previousY = NULL;
}
