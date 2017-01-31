#include "pch.h"

//using namespace glm;
using namespace Eigen;

namespace Library
{
	RTTI_DEFINITIONS(SpotLight)

	const float SpotLight::DefaultInnerAngle = 0.75f;
	const float SpotLight::DefaultOuterAngle = 0.25f;

	SpotLight::SpotLight(Game& game) :
		PointLight(game), mInnerAngle(DefaultInnerAngle), mOuterAngle(DefaultOuterAngle),
		mDirection(Vector3Helper::Forward), mUp(Vector3Helper::Up), mRight(Vector3Helper::Right)
	{
	}

	//const vec3& SpotLight::Direction() const
	const Vector3f& SpotLight::Direction() const
	{
		return mDirection;
	}
	
	//const vec3& SpotLight::Up() const
	const Vector3f& SpotLight::Up() const
	{
		return mUp;
	}

	//const vec3& SpotLight::Right() const
	const Vector3f& SpotLight::Right() const
	{
		return mRight;
	}

	float SpotLight::InnerAngle()
	{
		return mInnerAngle;
	}

	void SpotLight::SetInnerAngle(float value)
	{
		mInnerAngle = value;
	}

	float SpotLight::OuterAngle()
	{
		return mOuterAngle;
	}

	void SpotLight::SetOuterAngle(float value)
	{
		mOuterAngle = value;
	}
	/*
	void SpotLight::ApplyRotation(const mat4& transform)
	{
	vec4 direction = transform * vec4(mDirection, 0.0f);
	mDirection = static_cast<vec3>(normalize(direction));

	vec4 up = transform * vec4(mUp, 0.0f);
	mUp = static_cast<vec3>(normalize(up));

	mRight = cross(mDirection, mUp);
	mUp = cross(mRight, mDirection);
	}
	*/
    void SpotLight::ApplyRotation(const Matrix4f& transform)
    {	
		Vector4f direction = transform * Vector4f(mDirection.x(), mDirection.y(), mDirection.z(), 0.0f);
		mDirection = direction.normalized().head<3>();

		Vector4f up = transform * Vector4f(mUp.x(), mUp.y(), mUp.z(), 0.0f);
		mUp = up.normalized().head<3>();

		mRight = mDirection.cross(mUp);
		mUp = mRight.cross(mDirection);
    }
}