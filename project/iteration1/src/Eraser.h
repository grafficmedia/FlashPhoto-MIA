#ifndef ERASER_H
#define ERASER_H

// Eraser.h
// Created by Stevie Frisbie

class PixelBuffer;
class ColorData;
class Tool;

class Eraser: public Tool
{

  public:
    Eraser();
    virtual ~Eraser();
    float** computeMask();
    float calculateDistance(int x, int y);
    void paintMask(int x,int y,ColorData *displayBuffer,int width,int height,ColorData color,ColorData backgroundColor);
};

#endif
