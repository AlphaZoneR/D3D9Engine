#pragma once
#include <d3d9.h>
#include <windows.h>
#include "Window.h"


bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowName, int width, int heigth, HWND& hWnd);

bool GenerateWindowE(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowName, int x, int y, int width, int heigth, HWND& hWnd);

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

void Stealth();

void ShowConsole();

int mainR(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowName, int width, int heigth, HWND& hWnd, Window * window);


