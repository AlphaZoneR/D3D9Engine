#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include "GraphicsDevice.h"
class Text{
public:
    ~Text();
    ID3DXFont* getFont();
    bool Init(GraphicsDevice * gDev, int height, bool italic, LPCSTR FaceName, int x, int y);
    void Render(LPCSTR pString, DWORD format, D3DCOLOR Color);
    void Render(LPCSTR pString, DWORD format, D3DCOLOR Color, int x, int y);
private:
    ID3DXFont * font;
    RECT fRect;
    int px, py;
    std::string message;
};
