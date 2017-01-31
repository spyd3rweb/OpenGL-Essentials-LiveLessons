#include "pch.h"

//using namespace glm;
using namespace Eigen;

namespace Library
{
	RTTI_DEFINITIONS(PointLight)

	const float PointLight::DefaultRadius = 10.0f;

	PointLight::PointLight(Game& game) :
		//Light(game), mPosition(0), mRadius(DefaultRadius)
		Light(game), mPosition(Vector3Helper::Zero), mRadius(DefaultRadius)
	{
	}

	//const vec3& PointLight::Position() const
	const Vector3f& PointLight::Position() const
	{
		return mPosition;
	}

	float PointLight::Radius() const
	{
		return mRadius;
	}

	void PointLight::SetPosition(float x, float y, float z)
    {
		//mPosition = vec3(x, y, z);
		mPosition = Vector3f(x, y, z);
    }

    //void PointLight::SetPosition(const vec3& position)
	void PointLight::SetPosition(const Vector3f& position)
    {
        mPosition = position;
    }

	void PointLight::SetRadius(float value)
	{
		mRadius = value;
	}
}