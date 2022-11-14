#pragma once
struct circlePoint
{
    int* massiveX;
    int* massiveY;
    const int size;
    circlePoint(int* massX, int* massY, int Size) : 
    massiveX(massX), 
    massiveY(massY), 
    size(Size){}
};