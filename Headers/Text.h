#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include "GraphicsDevice.h"
class Text{
public:

    ID3DXFont* getFont();
    bool Init(GraphicsDevice * gDev, int height, int width, UINT weight, UINT mipLevel, bool italic, DWORD charset, DWORD OutputPrecision, DWORD Quality, DWORD PitchAndFamiliy, LPCSTR FaceName,LPD3DXFONT& font);
private:
    ID3DXFont * font;
    RECT fRect;
    std::string message;
};
