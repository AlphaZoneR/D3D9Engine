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
    void InitMatrix();
    void InitBoxResources();
    Text * Writer;
    void setViewMatrix(const D3DXVECTOR3& eye, const D3DXVECTOR3& lookAt, const D3DXVECTOR3& up);
	void setViewMatrix(D3DXVECTOR3 vector[3]) { setViewMatrix(vector[0], vector[1], vector[2]); };
	void setProjectionMatrix(float fov, float aspectRatio, float zClose, float zFar);
	void setProjectionMatrix(float fov, float zClose, float zFar) {
		setProjectionMatrix(fov, gDev->presentationParams.BackBufferWidth / (float)gDev->presentationParams.BackBufferHeight, zClose, zFar);
	}
	void setProjectionMatrix(float zClose, float zFar) {
		setProjectionMatrix(D3DX_PI / 4.0f, gDev->presentationParams.BackBufferWidth / (float)gDev->presentationParams.BackBufferHeight, zClose, zFar);
	}
	void setProjectionMatrix() {
		setProjectionMatrix(D3DX_PI / 4.0f, gDev->presentationParams.BackBufferWidth / (float)gDev->presentationParams.BackBufferHeight, 0.5f, 100.0f);
	}
private:
    GraphicsDevice* gDev;
    //Sprite *player;
    //Sprite *player2;
    std::vector<Sprite *> SpriteLs;
    POINT mouseCoord;
    clock_t current_ticks, delta_ticks,fps;
    int mWidth, mHeight;
    IDirect3DVertexBuffer9* vertexBuffer;
};
