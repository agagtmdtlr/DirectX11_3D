#include "Framework.h"
#include "AssertMessage.h"

void AssertMessage(const bool& bFlag, string message)
{
	AssertMessage(bFlag, String::ToWString(message));	
}

void AssertMessage(const bool& bFlag, wstring message)
{
	if (bFlag == false)
	{
		MessageBox(D3D::GetHandle(), message.c_str(), L"ERROR", MB_OK);
		assert(bFlag);
	}	
}
