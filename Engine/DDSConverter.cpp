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
	shader = make_unique<Shader>(new Shader(L""));

	wstring path = L"../../_Textures/White_ACC_Base_Color.png";
	HRESULT hr;
	hr = DirectX::GetMetadataFromWICFile(path.c_str(),WIC_FLAGS_NONE,metaData);
	Check(SUCCEEDED(hr)); // load src metadata;

	hr = DirectX::LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE,&metaData, srcImage);
	Check(SUCCEEDED(hr)); // load src image;

	hr = Compress
	(srcImage.GetImages(), srcImage.GetImageCount(), srcImage.GetMetadata(), DXGI_FORMAT_BC3_UNORM, TEX_COMPRESS_RGB_DITHER,TEX_THRESHOLD_DEFAULT, compressedImage);
	Check(SUCCEEDED(hr)); // compress src image


	CreateShaderResourceView(
		D3D::GetDevice(), 
		compressedImage.GetImages(),
		compressedImage.GetImageCount(),
		compressedImage.GetMetadata(),
		srv.GetAddressOf()
	);	

	shader->AsSRV("Texture2DMap")->SetResource(srv.Get());
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
	shader->Draw(0, 0, 4, 0);
}

void DDSConverter::PostRender()
{
}

void DDSConverter::ResizeScreen()
{
}
