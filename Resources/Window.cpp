#include "../Headers/Window.h"
#include "../Headers/GraphicsDevice.h"
#include <iostream>
#include <ctime>



Window::Window(){
    ///Constructor
}


bool Window::getKeyboard(int id){
    if(keyboard[id]){
        keyboard[id] = false;
        return true;
    }
    return false;
}


void Window::Run(HWND hWnd){
    float GT = 0;
    Update(GT,hWnd);
    current_ticks = clock();
    Draw(GT);
    delta_ticks = clock() - current_ticks;
    if(delta_ticks > 0)
        fps = CLOCKS_PER_SEC / delta_ticks;
        //std::cout << fps << std::endl;
}



Window::~Window(){
    for(int i = 0 ; i < SpriteLs.size();i++){
        if(SpriteLs[i]){
            delete SpriteLs[i];
            SpriteLs[i] = NULL;
        }
    }
    SpriteLs.clear();
    if(gDev){
        delete gDev;
        gDev = NULL;
    }
}
