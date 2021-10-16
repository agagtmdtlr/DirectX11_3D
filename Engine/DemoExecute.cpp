#include "stdafx.h"
#include "DemoExecute.h"

DemoExecute::DemoExecute()
{
	D3DX11_IMAGE_LOAD_INFO info;
	info.Width = 1024;
	info.Height = 1024;
	texture = new Texture(L"White_ACC_Base_Color.png", &info);
}

void DemoExecute::Initialize()
{
}

void DemoExecute::Ready()
{
}

void DemoExecute::Destroy()
{
}

void DemoExecute::Update()
{
	DirectX::TexMetadata data;
	texture->GetImageInfo(&data);
	string width = to_string(data.width);
	string height = to_string(data.height);
	Gui::Get()->RenderText(10.f, 50.f, 1.f, 1.f, 1.f, width);
	Gui::Get()->RenderText(10.f, 60.f, 1.f, 1.f, 1.f, height);

}

void DemoExecute::PreRender()
{
}

void DemoExecute::Render()
{
}

void DemoExecute::PostRender()
{
}

void DemoExecute::ResizeScreen()
{
}
