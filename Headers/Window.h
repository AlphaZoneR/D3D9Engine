#pragma once

#include "GraphicsDevice.h"
#include "Sprite.h"
#include <vector>
#include <ctime>
#include "Text.h"


class Window{
public:
    Window();
    ~Window();

    bool Init(HWND hWnd);
    void Run(HWND hWnd);
    void Update(float GT,HWND hWnd);
    void Draw(float GT);
    bool keyboard[1000];
    bool getKeyboard(int id);
    Text * Writer;
private:
    GraphicsDevice* gDev;
    Sprite *player;
    Sprite *player2;
    std::vector<Sprite *> SpriteLs;
    POINT mouseCoord;
    clock_t current_ticks, delta_ticks,fps;
    int mWidth, mHeight;
};
