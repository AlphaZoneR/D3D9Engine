#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "../Headers/Test.h"
#include <iostream>
#include "../Headers/Window.h"
using namespace std;
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowName, int width, int heigth, HWND& hWnd) {
	return GenerateWindowE(hInstance, nCmdShow, className, windowName, (GetSystemMetrics(SM_CXSCREEN) - width) / 2, (GetSystemMetrics(SM_CYSCREEN) - heigth) / 2, width, heigth, hWnd);
}

bool GenerateWindowE(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowName, int x, int y, int width, int heigth, HWND& hWnd) {
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW || CS_VREDRAW;
	wcex.lpfnWndProc = WindowProc;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wcex.lpszClassName = className;
	wcex.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

	if (!RegisterClassEx(&wcex)) {
		return false;
	}

	hWnd= CreateWindowEx(NULL, className, windowName, WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX, x, y, width, heigth, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	return true;
}

LRESULT CALLBACK WindowProc(HWND hWND, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
	}
	return DefWindowProc(hWND, message, wParam, lParam);
}

void Stealth()
{
 HWND Stealth;
 AllocConsole();
 Stealth = GetConsoleWindow();
 ShowWindow(Stealth,0);
}

void ShowConsole()
{
 HWND Stealth;
 AllocConsole();
 Stealth = GetConsoleWindow();
 ShowWindow(Stealth,1);
}

int mainR(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowName, int width, int heigth, HWND& hWnd, Window * window){
    if (GenerateWindow(hInstance, nCmdShow, className, windowName, width, heigth, hWnd)) {
        Stealth();
		MSG msg;
		window = new Window();
		cout << WM_KEYDOWN << endl;
		if(window->Init(hWnd)){
            while (true) {
                while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                    if(msg.message == WM_KEYDOWN){
                        if(msg.wParam < 256){
                            window->keyboard[msg.wParam] = true;
                        }
                    }
                    if (msg.message == WM_QUIT) {
                        ShowConsole();
                        return 0;
                        break;

                    }else{
                        window->Run(hWnd);
                    }
                }
            }
                        delete window;
            return msg.wParam;

        }
	}
}
