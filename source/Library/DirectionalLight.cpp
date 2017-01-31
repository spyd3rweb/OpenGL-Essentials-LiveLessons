#include "pch.h"

//using namespace glm;
using namespace Eigen;

namespace Library
{
	RTTI_DEFINITIONS(DirectionalLight)

	DirectionalLight::DirectionalLight(Game& game) :
		Light(game), mDirection(Vector3Helper::Forward), mUp(Vector3Helper::Up), mRight(Vector3Helper::Right)
	{
	}

	//const vec3& DirectionalLight::Direction() const
	const Vector3f& DirectionalLight::Direction() const
	{
		return mDirection;
	}
	
	//const vec3& DirectionalLight::Up() const
	const Vector3f& DirectionalLight::Up() const
	{
		return mUp;
	}

	//const vec3& DirectionalLight::Right() const
	const Vector3f& DirectionalLight::Right() const
	{
		return mRight;
	}
	/*
	void DirectionalLight::ApplyRotation(const mat4& transform)
    {
		vec4 direction = transform * vec4(mDirection, 0.0f);
		mDirection = static_cast<vec3>(normalize(direction));

		vec4 up = transform * vec4(mUp, 0.0f);
		mUp = static_cast<vec3>(normalize(up));

		mRight = cross(mDirection, mUp);
		mUp = cross(mRight, mDirection);
    }
	*/
    void DirectionalLight::ApplyRotation(const Matrix4f& transform)
    {
		Vector4f direction = transform * Vector4f(mDirection.x(), mDirection.y(), mDirection.z(), 0.0f);
		mDirection = direction.normalized().head<3>();

		Vector4f up = transform * Vector4f(mUp.x(), mUp.y(), mUp.z(), 0.0f);
		mUp = up.normalized().head<3>();

		mRight = mDirection.cross(mUp);
		mUp = mRight.cross(mDirection);
    }
}