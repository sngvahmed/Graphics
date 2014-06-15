// graphics.cpp : Defines the entry point for the application.
//
#include "graphics.h"
#include <shlobj.h>
#include <tchar.h>
#include <stdio.h>
#include "stdafx.h"
#include <Shlobj.h>
#include <cstring>
#include "resource.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <cmath>
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<conio.h>
#include<fstream>
#include <deque>
#include "commdlg.h"
#include<vector>
#include "Draw.h"
using namespace std;
#define MAX_LOADSTRING 100
#define _WIN32_DCOM
double X1, X2, Y1, Y2, m;
struct PT{
	double x1 , x2 , y1 , y2 ;  char P;
	PT(double x1 , double y1 , double x2 , double y2 , char d){
		this->x1 = x1 , this->y1 = y1 , this->x2 = x2 ,this->y2 = y2 , P = d;
	}
	PT(){}
};

// Global Variables:
deque< PT > var;
PAINTSTRUCT ps;
CHOOSECOLOR color; //the struct for the dialog
COLORREF ccref[16];//custom colors
COLORREF selcolor=0x000000;//the default selected color
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow){
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;
	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GRAPHICS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
		return FALSE;
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GRAPHICS));
	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			TranslateMessage(&msg) , DispatchMessage(&msg);
	return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance){

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW , wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra = wcex.cbWndExtra = 0 , wcex.hInstance		= hInstance;
	wcex.hIcon	= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GRAPHICS));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_GRAPHICS);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	return RegisterClassEx(&wcex);

}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
   HWND hWnd;
   hInst = hInstance; // Store instance handle in our global variable
   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   if (!hWnd)
      return FALSE;

   ShowWindow(hWnd, nCmdShow) , UpdateWindow(hWnd);
   return TRUE;

}

fstream ss;
int wmId, wmEvent;
bool isSecond = false , U = false , R = false , RES = false;
bool BDDA = true , BMP = false , MPC = false , cartizen = false , OT = false;
deque<PT> tmp;
void clr(){
	R = cartizen = RES = isSecond  = MPC = BMP = BDDA = U = OT = false; 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	Draw Ahmed;
	switch (message)
	{
		case WM_LBUTTONDOWN: 
			if(!isSecond) 
				X1 = LOWORD(lParam), Y1 = HIWORD(lParam) , isSecond = true;
			else 
				X2 = LOWORD(lParam) , Y2 = HIWORD(lParam) , InvalidateRect(hWnd, NULL, false);
		break;
		case WM_COMMAND:
			wmId = LOWORD(wParam) , wmEvent = HIWORD(wParam);
			// Parse the menu selections:
			switch (wmId){
				case IDM_S:
					ss.open("input.in") , tmp.clear() , tmp = var;
					while(var.size())
						ss << var.front().x1 << " " << var.front().y1 << " " << var.front().x2 << " " << 
							var.front().y2 << " " << var.front().P <<"\n" , var.pop_front();
					var = tmp , ss.close();
				break;
				case IDM_O:
					clr() , OT = true;
					InvalidateRect(hWnd, NULL, true); // draw only a line on the screen
				break;
				case IDM_DDA_LINE:
					clr() , BDDA = 1;
				break;
				case IDM_MP_LINE:
					clr() , BMP = true;
				break;
					case IDM_MP_CIRCULE:
					clr() , MPC = true;
				break;
				case IDM_CIRC_CART:
					clr() , cartizen = true;
				break;
				case IDM_RES:
					RES = true;
					isSecond  = false;
					InvalidateRect(hWnd, NULL, true); // draw only a line on the screen
				break;
				case IDM_R:
					clr() ,  R = true , InvalidateRect(hWnd , 0 , false);
				break;
				case IDM_U:
					clr() ,  U = true , InvalidateRect(hWnd , 0 , false);
				break;
				case IDM_COL:
					memset(&color,0,sizeof(color));
					color.lStructSize=sizeof(CHOOSECOLOR);
					color.hwndOwner=hWnd;
					color.lpCustColors=ccref;
					color.rgbResult=selcolor;
					color.Flags=CC_RGBINIT;
					if(ChooseColor(&color))
						selcolor=color.rgbResult;
					isSecond = false;
				break;
				case IDM_ABOUT:
					DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
					break;
				case IDM_EXIT:
					DestroyWindow(hWnd);
					break;
				default:
					return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
			case WM_PAINT:
				hdc = BeginPaint(hWnd, &ps);
				Ahmed.ps = ps ;
				if(OT == true){
					ss.open("input.in");
					PT tmst;
					while(!ss.eof()){
						ss >> tmst.x1 >> tmst.y1 >> tmst.x2 >> tmst.y2 >> tmst.P;			
						if (tmst.P == 'D')
							Ahmed.DDA(tmst.x1 , tmst.y1 , tmst.x2 , tmst.y2 , selcolor);
						if (tmst.P == 'M')
							Ahmed.MidPoint(tmst.x1 , tmst.y1 , tmst.x2 , tmst.y2 , selcolor);
						if (tmst.P == 'C')
							Ahmed.drawCircle(tmst.x1 , tmst.y1 , Ahmed.Distance(tmst.x1 , tmst.y1 , tmst.x2 , tmst.y2), selcolor);
						if(tmst.P == 'Z')
							Ahmed.MIDPOINT_CARTISIEAN(tmst.x1, tmst.y1 , Ahmed.Distance(tmst.x1 , tmst.y1 , tmst.x2 , tmst.y2), selcolor);
					}
					ss.close();
					clr() , BDDA = true , X1 = X2 = Y1 = Y2 = 0;
					EndPaint(hWnd, &ps);
					break;
				}
				if(U == true){
					if(var.size() != 0){
						PT t = var.back();
						var.pop_back() , var.push_front(t) ;
						if (t.P == 'D')
							Ahmed.DDA(t.x1 , t.y1 , t.x2 , t.y2 , RGB(250,250,250));
						if (t.P == 'M')
							Ahmed.MidPoint(t.x1 , t.y1 , t.x2 , t.y2 , RGB(250,250,250)); 
						if (t.P == 'C')
							Ahmed.drawCircle(t.x1 , t.y1 , Ahmed.Distance(t.x1,t.y1,t.x2,t.y2), RGB(250,250,250));
						if(t.P == 'Z')
							Ahmed.MIDPOINT_CARTISIEAN(t.x1, t.y1 , Ahmed.Distance(t.x1 , t.y1 , t.x2 , t.y2), RGB(250,250,250));
					}
					clr() , BDDA = true , X1 = X2 = Y1 = Y2 = 0;
					EndPaint(hWnd, &ps);
					break;
				} 
				if(R == true){
					if(var.size() != 0){
						PT t = var.front();
						var.pop_front() , var.push_back(t);
						if (t.P == 'D')
							Ahmed.DDA(t.x1 , t.y1 , t.x2 , t.y2 , selcolor);
						if (t.P == 'M')
							Ahmed.MidPoint(t.x1 , t.y1 , t.x2 , t.y2 , selcolor);
						if (t.P == 'C')
							Ahmed.drawCircle(t.x1 , t.y1 , Ahmed.Distance(t.x1 , t.y1 , t.x2 , t.y2), selcolor);
						if(t.P == 'Z')
							Ahmed.MIDPOINT_CARTISIEAN(t.x1, t.y1 , Ahmed.Distance(t.x1 , t.y1 , t.x2 , t.y2), selcolor);
					}
					clr() , BDDA = true , X1 = X2 = Y1 = Y2 = 0;
					EndPaint(hWnd, &ps);
					break;
				}
				if(MPC == true)
					Ahmed.drawCircle(X1 , Y1 , Ahmed.Distance(X1,Y1,X2,Y2), selcolor) , var.push_back(PT(X1,Y1,X2,Y2,'C'));
				if(BDDA == true)
					Ahmed.DDA(X1 , Y1 , X2 , Y2 , selcolor) ,var.push_back(PT(X1,Y1,X2,Y2,'D'));
				if (BMP == true)
					Ahmed.MidPoint(X1 , Y1 , X2 , Y2 , selcolor) ,var.push_back(PT(X1,Y1,X2,Y2,'M'));
				if(cartizen == true)
					Ahmed.MIDPOINT_CARTISIEAN(X1,Y1 , Ahmed.Distance(X1,Y1,X2,Y2) , selcolor) , var.push_back(PT(X1,Y1,X2,Y2,'Z'));
				EndPaint(hWnd, &ps) , isSecond = false;
				break;
			case WM_DESTROY:
				PostQuitMessage(0);
			break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
