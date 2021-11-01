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
	shader = make_unique<Shader>(L"ddsTest.fx");

	wstring path = L"../../_Textures/White_ACC_Base_Color.png";
	HRESULT hr;
	hr = DirectX::GetMetadataFromWICFile(path.c_str(),WIC_FLAGS_NONE,metaData);
	Check(SUCCEEDED(hr)); // load src metadata;

	hr = DirectX::LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE,&metaData, srcImage);
	Check(SUCCEEDED(hr)); // load src image;

	hr = Compress
	(srcImage.GetImages(), srcImage.GetImageCount(), srcImage.GetMetadata(), DXGI_FORMAT_BC3_UNORM, TEX_COMPRESS_RGB_DITHER,TEX_THRESHOLD_DEFAULT, compressedImage);
	Check(SUCCEEDED(hr)); // compress src image

	// create un-compressed texture view
	CreateShaderResourceView(
		D3D::GetDevice(),
		srcImage.GetImages(),
		srcImage.GetImageCount(),
		srcImage.GetMetadata(),
		srcSRV.GetAddressOf()
	);

	// create compressed texture view
	CreateShaderResourceView(
		D3D::GetDevice(), 
		compressedImage.GetImages(),
		compressedImage.GetImageCount(),
		compressedImage.GetMetadata(),
		srv.GetAddressOf()
	);	
	// bind srv to pipeline
	shader->AsSRV("Texture2DMap")->SetResource(srv.Get());	

	debugRT = make_unique<Render2D>();
	debugRT->GetTransform()->Scale(500.0f, 500.0f, 0.0f);
	debugRT->GetTransform()->Position(250.0f, 250.0f, 0.0f);
	debugRT->SRV(srcSRV.Get());

	debugRT2 = make_unique<Render2D>();
	debugRT2->GetTransform()->Scale(500.0f, 500.0f, 0.0f);
	debugRT2->GetTransform()->Position(750.0f, 250.0f, 0.0f);

	debugRT2->SRV(srv.Get());

	{
		ID3D11Texture2D* srcTxt;
		srcSRV->GetResource((ID3D11Resource**)&srcTxt);
		D3D11_TEXTURE2D_DESC srcDesc;
		srcTxt->GetDesc(&srcDesc);

		ID3D11Texture2D* destTxt;

		
	}

}

void DDSConverter::Ready()
{

}

void DDSConverter::Destroy()
{
}

void DDSConverter::Update()
{
	debugRT->Update();
	debugRT2->Update();
}

void DDSConverter::PreRender()
{
}

void DDSConverter::Render()
{
	debugRT->Render();
	debugRT2->Render();
	//shader->Draw(0, 0, 4, 0);
}

void DDSConverter::PostRender()
{
}

void DDSConverter::ResizeScreen()
{
}
