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
	ComPtr<ID3D11Texture2D> loadTexture;
	ComPtr<ID3D11Texture2D> saveTexture;
};

