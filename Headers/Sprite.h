#pragma once
#include <d3dx9.h>
#include <string>
class Sprite{
public:
    Sprite();
    Sprite(float x, float y);
    ~Sprite();

    bool Init(LPDIRECT3DDEVICE9 device, std::string file, int width, int height);
    bool isInit();
    virtual void Update(float GT);
    virtual void Draw(float GT);
    void moveTo(float x, float y);
private:
    LPDIRECT3DTEXTURE9 texture;
    LPD3DXSPRITE sprite;

    D3DXVECTOR3 position;
    D3DCOLOR color;
    int pwidth, pheight;
    bool inited;


};
