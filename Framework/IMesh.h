#pragma once


class IMesh
{
public:
	IMesh(Shader* shader = nullptr);
	virtual ~IMesh() {}

	virtual void Initialize();
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void ReadFile(wstring file) = 0;
	virtual void CreateResource() = 0;
private:
	Shader* mShader; // external data;
	UINT mTechnique;
	UINT mPass;

	unique_ptr<VertexBuffer> mVertexBuffer;
	unique_ptr<VertexBuffer> mIndexBuffer;

	
};

