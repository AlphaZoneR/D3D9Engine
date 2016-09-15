#include "../Headers/Text.h"



bool Text::Init(GraphicsDevice * gDev, int height, int width, UINT weight, UINT mipLevel, bool italic, DWORD charset, DWORD OutputPrecision, DWORD Quality, DWORD PitchAndFamiliy, LPCSTR FaceName,LPD3DXFONT& font){
    if(SUCCEEDED(D3DXCreateFont(gDev->device, height, width, weight, mipLevel, italic, charset, OutputPrecision, Quality, PitchAndFamiliy, FaceName, &font))){
        return true;
    }
    return false;
}
 ID3DXFont* Text::getFont(){
    return font;
 }

