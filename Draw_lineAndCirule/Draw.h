#pragma once
class Draw
{
public:
	PAINTSTRUCT ps;
	Draw();
	~Draw(void);
	void MIDPOINT_CARTISIEAN(int x , int y , int  radios, COLORREF selcolor);
	void setPixel(int x,int y,COLORREF selcolor);
	void circlePoints(int xCenter, int yCenter, int x, int y , COLORREF selcolor);
	double Distance(double dX0, double dY0, double dX1, double dY1);
	void drawCircle(int xCenter, int yCenter, int radius , COLORREF selcolor);
	void DDA(int X1, int Y1, int X2, int Y2 , COLORREF selcolor) ;
	void MidPoint(int X1, int Y1, int X2, int Y2 , COLORREF selcolor) ;
};

