#include "stdafx.h"
#include "Draw.h"
#include <math.h>

	void Draw :: setPixel(int x,int y,COLORREF selcolor){
		SetPixel ( ps.hdc , x , int(y) , selcolor ) ; 
	}

	void Draw :: circlePoints(int xCenter, int yCenter, int x, int y , COLORREF selcolor){
		setPixel(xCenter + x, yCenter + y , selcolor);
		setPixel(xCenter - x, yCenter + y , selcolor);
		setPixel(xCenter + x, yCenter - y , selcolor);
		setPixel(xCenter - x, yCenter - y , selcolor);
		setPixel(xCenter + y, yCenter + x , selcolor);
		setPixel(xCenter - y, yCenter + x , selcolor);
		setPixel(xCenter + y, yCenter - x , selcolor);
		setPixel(xCenter - y, yCenter - x , selcolor);
	}
	double Draw :: Distance(double dX0, double dY0, double dX1, double dY1){
		return sqrt(abs((dX1 - dX0)*(dX1 - dX0) + (dY1 - dY0)*(dY1 - dY0)));
	}

	void Draw :: drawCircle(int xCenter, int yCenter, int radius , COLORREF selcolor){
		int x = 0;
		int y = radius;
		int p = 1 - radius;
		circlePoints(xCenter, yCenter, x, y , selcolor );
		while(x < y){
			x++;
			if (p < 0)
				p += 2 * x + 1;
			else{
				y-- , p += 2 * (x - 0 - y) + 1;
			}
			circlePoints(xCenter, yCenter, x, y , selcolor);
		}
	}
	void Draw :: MIDPOINT_CARTISIEAN(int x , int y , int  radios, COLORREF selcolor){
		for(int X = 0 ; X <= radios ; X++){
			int Y = sqrt((double(radios*radios)) - (X*X));
			circlePoints(x, y, X, Y , selcolor );
		}
	}
	void Draw :: DDA(int X1, int Y1, int X2, int Y2 , COLORREF selcolor) {
         double dx = X2 - X1 , dy = Y2 - Y1;
		double m = dy/dx , c = Y1 - (m*X1) , x , y;
		if(abs(m) <= 1)
			for ( x = min(X1,X2) ; x <= max(X1, X2) ; x++){
				y = m*x + c ;
				SetPixel ( ps.hdc , x , int(y) , selcolor) ;
			}
		else 
	        for ( y = min(Y1,Y2) ; y <= max(Y1, Y2) ; y++){
				x = (y - c)/m ;
	 			SetPixel ( ps.hdc , x , int(y) , selcolor) ;
			}
	}
	
	void Draw :: MidPoint(int X1, int Y1, int X2, int Y2 , COLORREF selcolor) {
		int dx = X2 - X1, dy = Y2 - Y1, d, dNE, dE;
		float m = (float) dy / (float) dx;
		if (m >= -1 && m <= 1) {
			if (X1 > X2) {
				MidPoint(X2, Y2, X1, Y1 , selcolor);  return;
			}
			if (dy < 0) 
				m = -1 , dy = -dy;
			 else
				m = 1;
			SetPixel(ps.hdc, X1, int(Y1), selcolor);
			d = 2 * dy - dx , dNE = 2 * dy , dE = 2 * dy - 2 * dx;
			while (X1 < X2) {
				X1++;
				if (d < 0)
					d += dNE;
				else {
					Y1 += m , d += dE;
				}
				SetPixel(ps.hdc, X1, int(Y1), selcolor);
			}
		} else {
			if (Y1 > Y2) {
				MidPoint(X2, Y2, X1, Y1 , selcolor); return;
			}
			(dx < 0) ? m = -1 , dx = -dx : m = 1;
			SetPixel(ps.hdc, X1, int(Y1), selcolor);
			d = 2 * dx - dy , dNE = 2 * dx , dE = 2 * dx - 2 * dy;
			while (Y1 < Y2) {
				Y1++ , (d < 0) ?d += dNE : X1 += m , d += dE;
				SetPixel(ps.hdc, X1, int(Y1), selcolor);
			}
		}
	}


Draw::Draw(){
}


Draw::~Draw(void)
{
}
