
#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	_D3D = NULL;
}

GraphicsClass::GraphicsClass(const GraphicsClass& other)
{

}

GraphicsClass::~GraphicsClass()
{

}

bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hWnd)
{
	bool result;

	_D3D = new D3DClass;
	if (!_D3D)
	{
		return false;
	}

	result = _D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hWnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hWnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	return true;
}

void GraphicsClass::Shutdown()
{
	if (_D3D)
	{
		_D3D->Shutdown();
		delete _D3D;
		_D3D = NULL;
	}

	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}

bool GraphicsClass::Render()
{
	_D3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);
	_D3D->EndScene();

	return true;
}