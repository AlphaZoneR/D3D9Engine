#include "../Headers/GraphicsDevice.h"
#include <d3d9.h>
#include "../Headers/Utils.h"
#include <iostream>
using namespace std;
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
    ZeroMemory(&presentationParams,sizeof(presentationParams));
    presentationParams.Windowed = winMode;
    presentationParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
    presentationParams.hDeviceWindow = hWnd;

    if(SUCCEEDED(direct3d->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL, hWnd, D3DCREATE_MIXED_VERTEXPROCESSING, &presentationParams, &device))){
        isinit = true;
    }

}

void GraphicsDevice::Init3D(HWND hWnd, bool winMode){
    m_DevType = D3DDEVTYPE_HAL;
    direct3d = Direct3DCreate9(D3D_SDK_VERSION);
    if(!direct3d){
        MessageBox(NULL, "Failed to create Direct3D interface object", NULL, NULL);
    }
    direct3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_Mode);
    HR(direct3d->CheckDeviceType(D3DADAPTER_DEFAULT, m_DevType, m_Mode.Format, m_Mode.Format, true));
	HR(direct3d->CheckDeviceType(D3DADAPTER_DEFAULT, m_DevType, D3DFMT_X8R8G8B8, D3DFMT_X8R8G8B8, false));
	int vp = 0;
	D3DCAPS9 devCaps;
    HR(direct3d->GetDeviceCaps(D3DADAPTER_DEFAULT, m_DevType, &devCaps));
    if(devCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
    ZeroMemory(&presentationParams,sizeof(presentationParams));
    presentationParams.BackBufferFormat = D3DFMT_A8R8G8B8;
	presentationParams.Windowed = true;
	presentationParams.BackBufferCount = 1;
	presentationParams.MultiSampleType = D3DMULTISAMPLE_NONE;
	presentationParams.MultiSampleQuality = 0;
	presentationParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentationParams.hDeviceWindow = hWnd;
	presentationParams.Flags = 0;
	presentationParams.EnableAutoDepthStencil =  true;
	presentationParams.AutoDepthStencilFormat = D3DFMT_D24S8;
	presentationParams.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	presentationParams.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
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
