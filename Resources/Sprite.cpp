#include "../Headers/Sprite.h"

Sprite::Sprite(){
    position.x = 0;
    position.y = 0;
    position.z = 0;

    color = D3DCOLOR_ARGB(255,255,255,255);
    inited = false;
}

Sprite::Sprite(float x, float y){
    position.x = x;
    position.y = y;
    position.z = 0;


    color = D3DCOLOR_ARGB(255,255,255,255);
    inited = false;
}

bool Sprite::Init(LPDIRECT3DDEVICE9 device, std::string file, int width, int height){
    if(!SUCCEEDED(D3DXCreateTextureFromFileEx(device, file.c_str(), width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &texture))){
        std::string s = "Issue creating texture, does the file even exist? Requested image was : " + file;
        MessageBox(NULL, s.c_str(), NULL, NULL);
        return false;
    }

    if(!(SUCCEEDED(D3DXCreateSprite(device, &sprite)))){
        MessageBox(NULL, "Issue creating sprite.", NULL, NULL);
        return false;
    }
    pheight = height;
    pwidth = width;
    inited = true;
    return true;

}

bool Sprite::isInit(){
    return inited;
}

void Sprite::Update(float GT){
    //Update the logic;
}

void Sprite::Draw(float GT){
    if(sprite && texture){
        sprite->Begin(D3DXSPRITE_ALPHABLEND);
        sprite->Draw(texture, NULL, NULL, &position, color);
        sprite->End();
    }
}

Sprite::~Sprite(){
    if(sprite){
        sprite->Release();
        sprite = NULL;
    }

    if(texture){
        texture->Release();
        texture = NULL;
    }
}
void Sprite::moveTo(float x, float y){
    if(x >= 0 and x <= 1280-pwidth){
        position.x = x;
    }else if(x < 0){
        position.x = 0;
    }else if(x > 1280 - pwidth){
        position.x = 1280-pwidth;
    }
    if(y >= 0 and y <= 720 - pheight){
        position.y = y;
    }else if(y < 0){
        position.y = 0;
    }else if(y > 720 - pheight){
        position.y = 720 - pheight;

    }

}

