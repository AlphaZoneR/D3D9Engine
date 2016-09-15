#include "../Headers/GraphicsDevice.h"
#include <d3d9.h>
//#include <D3D11.h>
GraphicsDevice::GraphicsDevice(){
    ///Constructor
}
GraphicsDevice::~GraphicsDevice(){
        if(device){
            device->Release();
            device = NULL;
        }
        if(direct3d){
            direct3d->Release();
            direct3d = NULL;
        }
}
void GraphicsDevice::Init(HWND hWnd, bool winMode){
    isinit = false;
    direct3d = Direct3DCreate9(D3D_SDK_VERSION);
    D3DPRESENT_PARAMETERS presentationParams;
    ZeroMemory(&presentationParams,sizeof(presentationParams));
    presentationParams.Windowed = winMode;
    presentationParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
    presentationParams.hDeviceWindow = hWnd;

    if(SUCCEEDED(direct3d->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL, hWnd, D3DCREATE_MIXED_VERTEXPROCESSING, &presentationParams, &device))){
        isinit = true;
    }

}

void GraphicsDevice::Clear(D3DCOLOR color){
    device->Clear(0,NULL,D3DCLEAR_TARGET,color,1.0f,0);

}

void GraphicsDevice::Begin(){
    device->BeginScene();
}

void GraphicsDevice::End(){
    device->EndScene();
}

void GraphicsDevice::Present(){
    device->Present(NULL, NULL, NULL, NULL);
}

bool GraphicsDevice::IsInit(){
    return isinit;
}
