#pragma once

#include <d3d9.h>
//#include <D3D11.h>
class GraphicsDevice{
public:
    GraphicsDevice();
    ~GraphicsDevice();

    void Init(HWND hWND, bool winMode);
    void Init3D(HWND hWnd, bool winMode);
    void Clear(D3DCOLOR color);
    void Begin();
    void End();
    void Present();
    bool IsInit();

    LPDIRECT3DDEVICE9 device;
    D3DPRESENT_PARAMETERS presentationParams;
private:
    LPDIRECT3D9 direct3d;
    bool isinit;
    D3DDISPLAYMODE  m_Mode;
    D3DDEVTYPE	m_DevType;

};

