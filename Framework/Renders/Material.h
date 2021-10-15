#pragma once

class Material
{
public:
	struct MaterialResource
	{
		vector<wstring> TextureNames;
		ComPtr<ID3D11Texture2D> Textures;
		ID3DX11EffectShaderResourceVariable* EffectSRV;
		UINT TextureCounts;
	};

public:
	Material();
	Material(Shader* shader);
	~Material();

	Shader* GetShader() { return shader; }
	void SetShader(Shader* shader);

	void CopyFrom(Material* material);

	void Name(wstring val) { name = val; }
	wstring Name() { return name; }


	void Render();

private:
	void Initialize();

private:	

	struct MaterialDesc
	{
		Color Albedo = { 1,1,1,1 };
		Color Metallic = { 0, 0, 0, 0 };
		Color Roughness = { 0, 0, 0, 0 };
		Color Normal = { 0, 0, 0, 0 };
		Color AO = { 0, 0, 0, 0 };
		Color Height = { 0, 0, 0, 0 };

	} colorDesc;

private:
	Shader* shader = NULL;

	wstring name;

};