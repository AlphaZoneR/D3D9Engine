#pragma once

#include <d3d9.h>
//#include <D3D11.h>
class GraphicsDevice{
public:
    GraphicsDevice();
    ~GraphicsDevice();

    void Init(HWND hWND, bool winMode);
    void Clear(D3DCOLOR color);
    void Begin();
    void End();
    void Present();
    bool IsInit();

    LPDIRECT3DDEVICE9 device;
private:
    LPDIRECT3D9 direct3d;
    bool isinit;


};

