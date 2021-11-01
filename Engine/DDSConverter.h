#pragma once
class DDSConverter : public IExecute
{
public:
	DDSConverter();
	virtual ~DDSConverter();

public:
	// Inherited via IExecute
	virtual void Initialize() override;
	virtual void Ready() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
	virtual void ResizeScreen() override;

private:
	unique_ptr<Shader> shader;
	unique_ptr<VertexBuffer> vertexBuffer;

	unique_ptr<Render2D> debugRT;
	unique_ptr<Render2D> debugRT2;

	ComPtr<ID3D11Texture2D> loadTexture;
	ComPtr<ID3D11ShaderResourceView> srcSRV;
	ComPtr<ID3D11ShaderResourceView> srv;
	ComPtr<ID3D11Texture2D> saveTexture;

	DirectX::TexMetadata metaData;

	DirectX::ScratchImage srcImage;
	DirectX::ScratchImage compressedImage;
	DirectX::ScratchImage lodImage;

};

