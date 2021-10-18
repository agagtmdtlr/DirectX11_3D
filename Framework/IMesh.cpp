#include "Framework.h"
#include "IMesh.h"

IMesh::IMesh(Shader * shader)
	:
	mShader(shader)
	, mTechnique(0)
	, mPass(0)
	, mPerFrame(make_unique<PerFrame>(shader))
{
	if (mShader == nullptr)
	{
		// assert 
		my_assert(L"shader NA Error");
	}
}

void IMesh::Initialize()
{
}
void IMesh::Update()
{
}
// build assert class
void IMesh::Render()
{
	
	if (mVertexBuffer != nullptr)
	{
		mVertexBuffer->Render();
		if (mIndexBuffer != nullptr)
		{
			mIndexBuffer->Render();
			mShader->DrawIndexed(mTechnique,mPass,mIndexBuffer->Count());
		}
		else
		{
			mShader->Draw(mTechnique, mPass, mVertexBuffer->Count());
		}
	}
	else
	{
		// assert no buffer
		my_assert(L"vertexbuffer NA Error");
	}	
}
