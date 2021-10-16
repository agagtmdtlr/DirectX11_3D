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
// build assert class
void IMesh::Render()
{
	if (mShader == nullptr)
	{
		// assert
	}

	if (mVertexBuffer != nullptr)
	{
		if (mIndexBuffer != nullptr)
		{
			mShader->DrawIndexed(mTechnique,mPass,mIndexCount);
		}
		else
		{
			mShader->Draw(mTechnique, mPass, mVertexCount);
		}
	}
	else
	{
		// assert no buffer
	}

	

	
}
