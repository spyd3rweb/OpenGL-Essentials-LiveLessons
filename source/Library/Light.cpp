#include "pch.h"
//using namespace glm;
using namespace Eigen;

namespace Library
{
	RTTI_DEFINITIONS(Light)

	Light::Light(Game& game) :
		GameComponent(game), mColor(ColorHelper::White)
	{
	}

	const Vector4f& Light::Color() const
	{
		return mColor;
	}

	void Light::SetColor(float r, float g, float b, float a)
	{
		SetColor(Vector4f(r, g, b, a));
	}

	void Light::SetColor(const Vector4f& color)
	{
		mColor = color;
	}
}