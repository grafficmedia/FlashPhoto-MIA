//
// ConvolutionFilter.h
// Created by Jonathon Meyer
//
#ifndef CON_FILTER_H
#define CON_FILTER_H
#include "Filter.h"

class ConvolutionFilter: public Filter
{
public:

	virtual void applyFilter(PixelBuffer *buf);
	virtual ColorData modifyPixel(ColorData pixel)=0;
	virtual void applyMask(int x,int y,PixelBuffer *buf,PixelBuffer *temp);

protected:
	float **mask;
	int size;
};
#endif





