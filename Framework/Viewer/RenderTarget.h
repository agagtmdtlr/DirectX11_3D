#pragma once

class RenderTarget
{
public:
	// ���е��� ���� format�� ���� // upscailing  ������� �غ��� �� �մ�.
	RenderTarget(UINT width = 0, UINT height = 0, DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM);
	~RenderTarget();

	ID3D11RenderTargetView* RTV() { return rtv; }
	ID3D11ShaderResourceView* SRV() { return srv; }

	void SaveTexture(wstring file);

	void PreRender(class DepthStencil* depthStencil);

	// �������� ����Ÿ�� ��ä��ϱ�
	static void PreRender(RenderTarget** targets, UINT count, class DepthStencil* depthStencil);


private:
	UINT width, height;
	DXGI_FORMAT format;

	ID3D11Texture2D* texture; // rtv - texture
	ID3D11RenderTargetView* rtv;
	ID3D11ShaderResourceView* srv; // �޾ƿ� texture�� ���� ���̴� �Ѱ��� srv
};