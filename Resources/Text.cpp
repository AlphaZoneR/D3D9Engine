#include "../Headers/Text.h"
#include <string>


bool Text::Init(GraphicsDevice * gDev, int height, bool italic, LPCSTR FaceName, int x, int y){
    font = NULL;
    HRESULT hr;
    if(!SUCCEEDED(D3DXCreateFont(gDev->device, height, 0, FW_NORMAL, 1, italic, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, FaceName, &font))){
        return false;
    }
    px = x;
    py = y;
    SetRect(&fRect, px, py, 1280, 720);
    return true;
}
void Text::Render(LPCSTR pString, DWORD format, D3DCOLOR Color){
    Render(pString, format, Color, px , py);
}
void Text::Render(LPCTSTR pString, DWORD format, D3DCOLOR Color, int x, int y){
    SetRect(&fRect, x, y, 1280, 720);
    if(font){
        font->DrawTextA(NULL, pString, -1, &fRect, format, Color);
    }
}

 ID3DXFont* Text::getFont(){
    return font;
 }

Text::~Text(){
    if(font){
        font->Release();
        font = NULL;
    }
}
