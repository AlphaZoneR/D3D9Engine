#include "../Headers/Window.h"
#include "../Headers/GraphicsDevice.h"
#include <iostream>
#include <ctime>
#include "../Headers/Utils.h"

using namespace util;


Window::Window(){
    ///Constructor
}


bool Window::getKeyboard(int id){
    if(keyboard[id]){
        keyboard[id] = false;
        return true;
    }
    return false;
}


void Window::Run(HWND hWnd){
    float GT = 0;
    Update(GT,hWnd);
    current_ticks = clock();
    Draw(GT);
    delta_ticks = clock() - current_ticks;
    if(delta_ticks > 0)
        fps = CLOCKS_PER_SEC / delta_ticks;
        //std::cout << fps << std::endl;
}



Window::~Window(){
    for(int i = 0 ; i < SpriteLs.size();i++){
        if(SpriteLs[i]){
            delete SpriteLs[i];
            SpriteLs[i] = NULL;
        }
    }
    SpriteLs.clear();
    if(gDev){
        delete gDev;
        gDev = NULL;
    }
}

void Window::InitMatrix(){
    D3DXVECTOR3 viewV[3] ={
        D3DXVECTOR3(2.5f, 3.5f, -3.5f),
		D3DXVECTOR3(0.0f, 0.0f, 0.0f),
		D3DXVECTOR3(0.0f, 1.0f, 0.0f)
    };
    setViewMatrix(viewV);
    setProjectionMatrix();
    gDev->device->SetRenderState(D3DRS_LIGHTING,false);
}
void Window::setViewMatrix(const D3DXVECTOR3& eye, const D3DXVECTOR3& lookAt, const D3DXVECTOR3& up){
    D3DXMATRIXA16 viewMatrix;
    D3DXMatrixLookAtLH(&viewMatrix,&eye,&lookAt,&up);
    gDev->device->SetTransform(D3DTS_VIEW,&viewMatrix);
}

void Window::setProjectionMatrix(float fov, float aspectRatio, float zClose, float zFar){
    D3DXMATRIXA16 projectionMatrix;
    D3DXMatrixPerspectiveFovLH(&projectionMatrix, fov, aspectRatio, zClose, zFar);
    gDev->device->SetTransform(D3DTS_PROJECTION, &projectionMatrix);
}

void Window::InitBoxResources(){
    UntransformedColouredVertex vertices[] = {
		// Front Face (1-2-3-4)
		{ -1.0f, 1.0f, -1.0f, 0xffff0000 },
		{ 1.0f, 1.0f, -1.0f, 0xffffafaf },
		{ -1.0f, -1.0f, -1.0f, 0xffffafaf },
		{ 1.0f, -1.0f, -1.0f, 0xffff0000 },

		// Right Face (2-6-4-8)
		{ 1.0f, 1.0f, -1.0f, 0xff00ff00 },
		{ 1.0f, 1.0f, 1.0f, 0xffafffaf },
		{ 1.0f, -1.0f, -1.0f, 0xffafffaf },
		{ 1.0f, -1.0f, 1.0f, 0xff00ff00 },

		// Top Face (5-6-1-2)
		{ -1.0f, 1.0f, 1.0f, 0xff0000ff },
		{ 1.0f, 1.0f, 1.0f, 0xffafafff },
		{ -1.0f, 1.0f, -1.0f, 0xffafafff },
		{ 1.0f, 1.0f, -1.0f, 0xff0000ff },

		// Back Face (6-5-8-7)
		{ 1.0f, 1.0f, 1.0f, 0xffffff00 },
		{ -1.0f, 1.0f, 1.0f, 0xffffffaf },
		{ 1.0f, -1.0f, 1.0f, 0xffffffaf },
		{ -1.0f, -1.0f, 1.0f, 0xffffff00 },

		// Left Face (5-1-7-3)
		{ -1.0f, 1.0f, 1.0f, 0xffff00ff },
		{ -1.0f, 1.0f, -1.0f, 0xffffafff },
		{ -1.0f, -1.0f, 1.0f, 0xffffafff },
		{ -1.0f, -1.0f, -1.0f, 0xffff00ff },

		// Bottom Face (3-4-7-8)
		{ -1.0f, -1.0f, -1.0f, 0xff00ffff },
		{ 1.0f, -1.0f, -1.0f, 0xffafffff },
		{ -1.0f, -1.0f, 1.0f, 0xffafffff },
		{ 1.0f, -1.0f, 1.0f, 0xff00ffff }
	};

	gDev->device->CreateVertexBuffer(sizeof(vertices), D3DUSAGE_WRITEONLY, vertices[0].FORMAT, D3DPOOL_DEFAULT, &vertexBuffer, NULL);
	void* bMem;
	vertexBuffer->Lock(0, sizeof(vertices), &bMem, NULL);
	memcpy(bMem, vertices, sizeof(vertices));
	vertexBuffer->Unlock();
	gDev->device->SetFVF(vertices[0].FORMAT);
	gDev->device->SetStreamSource(0, vertexBuffer, 0, vertices[0].STRIDE_SIZE);

}
