#include<iostream>
using namespace std;

struct Rect{
    double x,y,w,h;
};

double overlap(Rect& A, Rect& B){
    double ALeft  = A.x;
    double ARight = A.x + A.w;
    double BLeft  = B.x;
    double BRight = B.x + B.w;
    
    double ATop    = A.y;
    double ABottom = A.y - A.h;
    double BTop    = B.y;
    double BBottom = B.y - B.h;

    double left, right, bottom, top;

    if (ALeft > BLeft) left = ALeft;
    else left = BLeft;

    if (ARight < BRight) right = ARight;
    else right = BRight;

    if (ABottom > BBottom) bottom = ABottom;
    else bottom = BBottom;

    if (ATop < BTop) top = ATop;
    else top = BTop;

    double overlapW = right - left;
    double overlapH = top - bottom;
    
    if (overlapW <= 0 || overlapH <= 0) return 0;
    return overlapW * overlapH;
}
