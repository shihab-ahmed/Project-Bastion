#ifndef Algorithm_H
#define Algorithm_H
#include <vector>
using namespace std;
typedef vector<double> Row;
typedef vector<Row> Matrix;
double GetValueOfSin(int degree);
double GetValueOfCos(int degree);
void ShowMatrix(Matrix PreviewMatrix);
Matrix DrawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
Matrix DrawTriangle();
Matrix Translation(Matrix Poisition, double x, double y, double z);
Matrix RoundMatrix(Matrix roundMatrix);
Matrix Scalling(Matrix Poisition, double x, double y);
Matrix Mirror(Matrix Poisition, bool Xmirror);
Matrix Rotation(Matrix Poisition, double degree, int AxisOfRotation);
Matrix CreateCircle2D(int Radius, int X, int Y);
#endif // !Graphics_Algorithm_H
#pragma once