#include "Framework.h"
#include "Material.h"

Material::Material()
{
	Initialize();
}

Material::Material(Shader * shader)
{
	Initialize();

	SetShader(shader);
}

void Material::Initialize()
{
	name = L"";


}

Material::~Material()
{
}

void Material::SetShader(Shader * shader)
{
	this->shader = shader;
}

void Material::CopyFrom(Material * material)
{
	name = material->name;
	colorDesc = material->colorDesc;

	if (material->shader != NULL)
		SetShader(material->shader);
}


void Material::Render()
{
}