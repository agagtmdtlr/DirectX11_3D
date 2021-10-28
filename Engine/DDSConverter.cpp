#include "stdafx.h"
#include "DDSConverter.h"

using namespace DirectX;

DDSConverter::DDSConverter()
{
}

DDSConverter::~DDSConverter()
{
}

void DDSConverter::Initialize()
{
	wstring path;

	HRESULT hr;
	DirectX::TexMetadata metaData;

	DirectX::GetMetadataFromWICFile(path.c_str(),WIC_FLAGS_NONE,metaData);

	DirectX::Image image;
	DirectX::ScratchImage scrathImage;

	DirectX::LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE,&metaData, scrathImage);

	DirectX::SaveToDDSFile(image, DDS_FLAGS_NONE, path.c_str());

	
	D3D11_TEXTURE2D_DESC textureDesc;
	textureDesc.ArraySize = 1;
	textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	textureDesc.Format = DXGI_FORMAT_BC5_UNORM;
	textureDesc.Width = metaData.width;
	textureDesc.Height = metaData.height;
}

void DDSConverter::Ready()
{
}

void DDSConverter::Destroy()
{
}

void DDSConverter::Update()
{
}

void DDSConverter::PreRender()
{
}

void DDSConverter::Render()
{
}

void DDSConverter::PostRender()
{
}

void DDSConverter::ResizeScreen()
{
}
