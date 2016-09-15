#include <windows.h>
#include <iostream>
#include "../Headers/Window.h"
#include "../Headers/Test.h"
#include "../Headers/Text.h"
#include <stdio.h>
#include "../Headers/Utils.h"
using namespace std;
using namespace util;
Window * window;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    HWND hWnd;
    mainR(hInstance,nCmdShow,"Win32","Reduced",1280,720,hWnd,window);
  	return 0;
}

bool Window::Init(HWND hWnd){
    vertexBuffer = NULL;
    gDev = new GraphicsDevice();
    gDev->Init3D(hWnd,true);
    InitMatrix();
    InitBoxResources();
    Writer = new Text();
    if(!Writer->Init(gDev,20,false,"Arial",200,200)){
        return false;
    }
    ShowCursor(false);
    GetCursorPos(&mouseCoord);
    fps = 0;
    if(!gDev->IsInit()){
        return false;
    }

    return true;
}

void Window::Update(float GT,HWND hWnd){
    GetCursorPos(&mouseCoord);
    ScreenToClient(hWnd,&mouseCoord);


    if(getKeyboard(VK_ESCAPE)){
        PostQuitMessage(0);
    }
}

void Window::Draw(float GT){
    gDev->device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
    gDev->Begin();
    for(int i = 0 ; i < SpriteLs.size();i++){
        SpriteLs[i]->Draw(GT);
    }
    char buffer[100];
    sprintf(buffer,"%d",fps);
    Writer->Render(buffer,DT_CENTER,D3DCOLOR_XRGB(255,255,255),0,0);
    DrawCircleFilled(mouseCoord.x,mouseCoord.y,10,D3DCOLOR_XRGB(255,255,255),gDev);
    for(int i = 0 ; i < 6 ;i++){
         gDev->device->DrawPrimitive(D3DPT_TRIANGLESTRIP, i * 4 , 2);
    }

    gDev->End();
    gDev->Present();
}


