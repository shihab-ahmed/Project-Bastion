#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;
typedef vector<double> Row;
typedef vector<Row> Matrix;


double GetValueOfSin(int degree)
{
	double sinVal = sin(degree*PI / 180);
	return sinVal;

}
double GetValueOfCos(int degree)
{
	double cosVal = cos(degree*PI / 180);
	return cosVal;
}
/*.............................................................................*/

/*The following method will multiply matrix*/
Matrix MatrixMultiplication(Matrix MatrixA, Matrix MatrixB)
{
	int row = MatrixA.size();
	int column = MatrixB[0].size();

	Matrix multiplicationMatrix(row, Row(column));
	int size = MatrixB[0].size();
	for (int i = 0; i < 3; i++)
	{
		multiplicationMatrix[i].resize(size);
	}
	for (int i = 0; i <MatrixA.size(); ++i)
	{
		for (int j = 0; j < MatrixB[0].size(); ++j)
		{
			for (int k = 0; k < MatrixA[0].size(); ++k)
			{

				multiplicationMatrix[i][j] += MatrixA[i][k] * MatrixB[k][j];

			}

		}
	}
	return multiplicationMatrix;
}

/*The following method will create and identity matrix*/
Matrix CreateIdentityMatrix()
{
	Matrix IdentifyMatrix(4, Row(4));
	for (int i = 0; i<4; i++)
	{

		for (int j = 0; j<4; j++)
		{
			if (i == j)
			{
				IdentifyMatrix[i][j] = 1;
			}
			else
			{
				IdentifyMatrix[i][j] = 0;
			}
		}

	}
	return IdentifyMatrix;
}
/*....................................................................................................*/
Matrix CreateTranslationMatrix2D(double dx, double dy,double dz)
{
	Matrix TranslationMatrix(4, Row(4));
	TranslationMatrix = CreateIdentityMatrix();
	TranslationMatrix[0][3] = dx;
	TranslationMatrix[1][3] = dy;
	TranslationMatrix[2][3] = dz;
	return TranslationMatrix;
}
/*....................................................................................................*/
Matrix CreateOriginTranslationMatrix2D(Matrix OldMatrix, bool ReverseTranslation)
{
	Matrix OriginMatrix(4, Row(4));
	OriginMatrix = CreateIdentityMatrix();

	if (ReverseTranslation)
	{
		for (int i = 0; i<3; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				OriginMatrix[0][2] = OldMatrix[0][0];
			}
		}
		OriginMatrix[0][3] = OldMatrix[0][0];
		OriginMatrix[1][3] = OldMatrix[1][0];
		OriginMatrix[2][3] = OldMatrix[2][0];
	}
	else
	{
		OriginMatrix[0][3] = -OldMatrix[0][0];
		OriginMatrix[1][3] = -OldMatrix[1][0];
		OriginMatrix[2][3] = -OldMatrix[2][0];
	}
	return OriginMatrix;
}
/*....................................................................................................*/


/*....................................................................................................*/
Matrix CreateScallingMatrix2D(double Sx, double Sy)
{
	Matrix ScallingMatrix(3, Row(3));
	ScallingMatrix = CreateIdentityMatrix();
	ScallingMatrix[0][0] = Sx;
	ScallingMatrix[1][1] = Sy;
	return ScallingMatrix;
}
/*....................................................................................................*/
Matrix CreateMirrorMatrixX()
{
	Matrix MirrorMatrixX(3, Row(3));
	MirrorMatrixX = CreateIdentityMatrix();
	MirrorMatrixX[1][1] = -1;
	return MirrorMatrixX;
}
Matrix CreateMirrorMatrixY()
{
	Matrix MirrorMatrixY(3, Row(3));
	MirrorMatrixY = CreateIdentityMatrix();
	MirrorMatrixY[0][0] = -1;
	return MirrorMatrixY;
}
Matrix RoundMatrix(Matrix roundMatrix)
{
	for (int i = 0; i < roundMatrix.size(); i++)
	{
		for (int j = 0; j < roundMatrix[0].size(); j++)
		{
			roundMatrix[i][j] = round(roundMatrix[i][j]);
		}
	}


	return roundMatrix;
}
/*....................................................................................................*/
Matrix CreateRotationMatrix3D(double degree,int AxisOfRotation)
{
	Matrix RotationgMatrix(4, Row(4));
	RotationgMatrix = CreateIdentityMatrix();

	if (AxisOfRotation == 1) //Along x axis
	{
		RotationgMatrix[1][1] = GetValueOfCos(degree);
		RotationgMatrix[1][2] = -GetValueOfSin(degree);
		RotationgMatrix[2][1] = GetValueOfSin(degree);
		RotationgMatrix[2][2] = GetValueOfCos(degree);
	}
	if (AxisOfRotation == 2) //Along y axis
	{
		RotationgMatrix[0][0] = GetValueOfCos(degree);
		RotationgMatrix[2][0] = -GetValueOfSin(degree);
		RotationgMatrix[0][2] = GetValueOfSin(degree);
		RotationgMatrix[2][2] = GetValueOfCos(degree);
	}
	if (AxisOfRotation == 3) //Along z axis
	{
		RotationgMatrix[0][0] = GetValueOfCos(degree);
		RotationgMatrix[0][1] = -GetValueOfSin(degree);
		RotationgMatrix[1][0] = GetValueOfSin(degree);
		RotationgMatrix[1][1] = GetValueOfCos(degree);
	}
	
	return RotationgMatrix;
}
void ShowMatrix(Matrix PreviewMatrix)
{
	for (int i = 0; i < PreviewMatrix.size(); i++)
	{
		for (int j = 0; j < PreviewMatrix[0].size(); j++)
		{
			cout << PreviewMatrix[i][j] << "  ";
		}
		cout << endl;
	}
}
Matrix Translation(Matrix Poisition, double x, double y,double z)
{
	Poisition = MatrixMultiplication(CreateTranslationMatrix2D(x, y, z), Poisition);
	return Poisition;
}
Matrix Scalling(Matrix Poisition, double x, double y)
{
	Matrix mat1 = MatrixMultiplication(CreateOriginTranslationMatrix2D(Poisition, false), Poisition);
	Matrix mat2 = MatrixMultiplication(CreateScallingMatrix2D(x, y), mat1);
	Matrix mat3 = MatrixMultiplication(CreateOriginTranslationMatrix2D(Poisition, true), mat2);
	return mat3;
}
Matrix Rotation(Matrix Poisition, double degree, int AxisOfRotation)
{
	Matrix mat1 = MatrixMultiplication(CreateOriginTranslationMatrix2D(Poisition, false), Poisition);
	Matrix mat2 = MatrixMultiplication(CreateRotationMatrix3D(degree,AxisOfRotation), mat1);
	Matrix mat3 = MatrixMultiplication(CreateOriginTranslationMatrix2D(Poisition, true), mat2);
	return mat3;
}
Matrix Mirror(Matrix Poisition, bool Xmirror)
{
	if (Xmirror)
	{
		Matrix mat = MatrixMultiplication(CreateMirrorMatrixX(), Poisition);
		return mat;
	}
	else
	{
		Matrix mat = MatrixMultiplication(CreateMirrorMatrixY(), Poisition);
		return mat;
	}
}
int getCircleDecesionPoint(int h0, int drawX, int drawY)
{
	if (h0 < 0)
	{
		h0 = h0 + (2 * drawX) + 2;
	}
	else
	{
		h0 = h0 + (2 * (drawX - drawY)) + 2;
	}
	return h0;
}
Matrix CreateCircle2D(int Radius, int X, int Y)
{
	int X_Pos = 0, Y_Pos = Radius, h0, counter = 0;
	Matrix circle(3);
	while (Y_Pos >= X_Pos)
	{
		if (counter == 0)
		{
			h0 = 1 - Radius;
			if (h0 < 0)
			{
				X_Pos++;
			}
			else
			{
				X_Pos++;
				Y_Pos--;
			}

		}
		else
		{
			h0 = getCircleDecesionPoint(h0, X_Pos, Y_Pos);
			if (h0 < 0)
			{
				X_Pos++;
			}
			else
			{
				X_Pos++;
				Y_Pos--;
			}
		}
		if (Y_Pos >= X_Pos)
		{
			circle[0].push_back(X_Pos);
			circle[1].push_back(Y_Pos);
			circle[2].push_back(1);
		}
		counter++;
	}
	return circle;
}
Matrix DrawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	Matrix quad(3, Row(4));
	quad[0][0] = x1;
	quad[1][0] = y1;
	quad[0][1] = x2;
	quad[1][1] = y2;
	quad[0][2] = x3;
	quad[1][2] = y3;
	quad[0][3] = x4;
	quad[1][3] = y4;

	quad[2][0] = 1;
	quad[2][1] = 1;
	quad[2][2] = 1;
	quad[2][3] = 1;
	return quad;
}

Matrix DrawTriangle()
{
	Matrix triangle(3, Row(3));

	cout << "X1:";
	cin >> triangle[0][0];
	cout << "Y1:";
	cin >> triangle[1][0];
	cout << "X2:";
	cin >> triangle[0][1];
	cout << "Y2:";
	cin >> triangle[1][1];
	cout << "X3:";
	cin >> triangle[0][2];
	cout << "Y3:";
	cin >> triangle[1][2];
	triangle[2][0] = 1;
	triangle[2][1] = 1;
	triangle[2][2] = 1;
	return triangle;
}