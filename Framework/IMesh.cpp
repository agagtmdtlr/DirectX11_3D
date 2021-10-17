#include "Framework.h"
#include "IMesh.h"

IMesh::IMesh(Shader * shader)
	:mShader(shader)
{
}

void IMesh::Initialize()
{
	CreateResource();
}
void IMesh::Update()
{
}
// build assert class
void IMesh::Render()
{
	if (mShader == nullptr)
	{
		// assert
	}

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
	}

	

	
}
