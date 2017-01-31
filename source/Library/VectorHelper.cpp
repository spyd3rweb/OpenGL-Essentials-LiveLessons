#include "pch.h"

//using namespace glm;
using namespace Eigen;
using namespace std;

namespace Library
{
	const Vector2f Vector2Helper::Zero = Vector2f(0.0f, 0.0f);
	const Vector2f Vector2Helper::One = Vector2f(1.0f, 1.0f);

	string Vector2Helper::ToString(const Vector2f& vector)
	{
		stringstream stream;

		stream << "{" << vector.x() << ", " << vector.y() << "}";

		return stream.str();
	}

	/*
	const vec3 Vector3Helper::Zero = vec3(0.0f, 0.0f, 0.0f);
	const vec3 Vector3Helper::One = vec3(1.0f, 1.0f, 1.0f);
	const vec3 Vector3Helper::Forward = vec3(0.0f, 0.0f, -1.0f);
	const vec3 Vector3Helper::Backward = vec3(0.0f, 0.0f, 1.0f);
	const vec3 Vector3Helper::Up = vec3(0.0f, 1.0f, 0.0f);
	const vec3 Vector3Helper::Down = vec3(0.0f, -1.0f, 0.0f);
	const vec3 Vector3Helper::Right = vec3(1.0f, 0.0f, 0.0f);
	const vec3 Vector3Helper::Left = vec3(-1.0f, 0.0f, 0.0f);
	*/
	const Vector3f Vector3Helper::Zero = Vector3f(0.0f, 0.0f, 0.0f);
	const Vector3f Vector3Helper::One = Vector3f(1.0f, 1.0f, 1.0f);
	const Vector3f Vector3Helper::Forward = Vector3f(0.0f, 0.0f, -1.0f);
	const Vector3f Vector3Helper::Backward = Vector3f(0.0f, 0.0f, 1.0f);
	const Vector3f Vector3Helper::Up = Vector3f(0.0f, 1.0f, 0.0f);
	const Vector3f Vector3Helper::Down = Vector3f(0.0f, -1.0f, 0.0f);
	const Vector3f Vector3Helper::Right = Vector3f(1.0f, 0.0f, 0.0f);
	const Vector3f Vector3Helper::Left = Vector3f(-1.0f, 0.0f, 0.0f);

	//string Vector3Helper::ToString(const vec3& vector)
	string Vector3Helper::ToString(const Vector3f& vector)
	{
		stringstream stream;

		stream << "{" << vector.x() << ", " << vector.y() << ", " << vector.z() << "}";

		return stream.str();
	}

	/*
	const vec4 Vector4Helper::Zero = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	const vec4 Vector4Helper::One = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	*/
	const Vector4f Vector4Helper::Zero = Vector4f(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4f Vector4Helper::One = Vector4f(1.0f, 1.0f, 1.0f, 1.0f);

	//string Vector4Helper::ToString(const vec4& vector)
	string Vector4Helper::ToString(const Vector4f& vector)
	{
		stringstream stream;

		stream << "{" << vector.x() << ", " << vector.y() << ", " << vector.z() << ", " << vector.w() << "}";

		return stream.str();
	}
}
