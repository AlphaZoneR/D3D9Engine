#include <windows.h>
#include <iostream>
#include "../Headers/Window.h"
#include "../Headers/Test.h"
using namespace std;

Window * window;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    HWND hWnd;
    mainR(hInstance,nCmdShow,"Win32","Reduced",1280,720,hWnd,window);
  	return 0;
}

bool Window::Init(HWND hWnd){
    gDev = new GraphicsDevice();
    gDev->Init(hWnd,true);
    Writer = new Text();
    Writer->Init(gDev->device, 40, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &Writer->getFont());
    ShowCursor(false);
    GetCursorPos(&mouseCoord);
    fps = 0;
    if(!gDev->IsInit()){
        return false;
    }
    player = new Sprite(100,200);
    if(!player->Init(gDev->device,"PlayerPaper.png",58,86)){
        return false;
    }
    player2 = new Sprite(80,200);
    if(!player2->Init(gDev->device,"PlayerPaper.png",58,86)){
        return false;
    }
    SpriteLs.push_back(player);
    SpriteLs.push_back(player2);

    return true;
}

void Window::Update(float GT,HWND hWnd){
    GetCursorPos(&mouseCoord);
    ScreenToClient(hWnd,&mouseCoord);
    player2->moveTo(mouseCoord.x,mouseCoord.y);
    player->moveTo(1280-mouseCoord.x,mouseCoord.y);

    if(getKeyboard(VK_ESCAPE)){
        PostQuitMessage(0);
    }
}

void Window::Draw(float GT){
    gDev->Clear(D3DCOLOR_XRGB(0,100,100));
    gDev->Begin();
    for(int i = 0 ; i < SpriteLs.size();i++){
        SpriteLs[i]->Draw(GT);
    }
    gDev->End();
    gDev->Present();
}
