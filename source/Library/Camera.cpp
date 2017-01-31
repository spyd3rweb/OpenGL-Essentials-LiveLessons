#include "pch.h"

//using namespace glm;
using namespace Eigen;

namespace Library
{
	RTTI_DEFINITIONS(Camera)

	const float Camera::DefaultFieldOfView = 45.0f;
	const float Camera::DefaultNearPlaneDistance = 0.01f;
	const float Camera::DefaultFarPlaneDistance = 1000.0f;

	Camera::Camera(Game& game) :
		GameComponent(game),
		mFieldOfView(DefaultFieldOfView), mAspectRatio(game.AspectRatio()), mNearPlaneDistance(DefaultNearPlaneDistance), mFarPlaneDistance(DefaultFarPlaneDistance),
		mPosition(), mDirection(), mUp(), mRight(), mViewMatrix(Eigen::Matrix4f::Identity()), mProjectionMatrix(Eigen::Matrix4f::Identity())
	{
	}

	Camera::Camera(Game& game, float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance) :
		GameComponent(game),
		mFieldOfView(fieldOfView), mAspectRatio(aspectRatio), mNearPlaneDistance(nearPlaneDistance), mFarPlaneDistance(farPlaneDistance),
		mPosition(), mDirection(), mUp(), mRight(), mViewMatrix(), mProjectionMatrix()
	{
	}

	//const glm::vec3& Camera::Position() const
	const Vector3f& Camera::Position() const
	{
		return mPosition;
	}

	//const glm::vec3& Camera::Direction() const
	const Vector3f& Camera::Direction() const
	{
		return mDirection;
	}

	//const glm::vec3& Camera::Up() const
	const Vector3f& Camera::Up() const
	{
		return mUp;
	}

	//const glm::vec3& Camera::Right() const
	const Vector3f& Camera::Right() const
	{
		return mRight;
	}

	float Camera::AspectRatio() const
	{
		return mAspectRatio;
	}

	float Camera::FieldOfView() const
	{
		return mFieldOfView;
	}

	float Camera::NearPlaneDistance() const
	{
		return mNearPlaneDistance;
	}

	float Camera::FarPlaneDistance() const
	{
		return mFarPlaneDistance;
	}

	//const glm::mat4& Camera::ViewMatrix() const
	const Matrix4f& Camera::ViewMatrix() const
	{
		return mViewMatrix;
	}

	//const glm::mat4&Camera::ProjectionMatrix() const
	const Matrix4f&Camera::ProjectionMatrix() const
	{
		return mProjectionMatrix;
	}

	//glm::mat4 Camera::ViewProjectionMatrix() const
	Matrix4f Camera::ViewProjectionMatrix() const
	{
		return mProjectionMatrix * mViewMatrix;
	}

	void Camera::SetPosition(float x, float y, float z)
	{
		//mPosition = vec3(x, y, z);
		mPosition = Vector3f(x, y, z);
	}

	//void Camera::SetPosition(const glm::vec3& position)
	void Camera::SetPosition(const Vector3f& position)
	{
		mPosition = position;
	}

	void Camera::Reset()
	{
		mPosition = Vector3Helper::Zero;
		mDirection = Vector3Helper::Forward;
		mUp = Vector3Helper::Up;
		mRight = Vector3Helper::Right;

		UpdateViewMatrix();
	}

	void Camera::Initialize()
	{
		UpdateProjectionMatrix();
		Reset();
	}

	void Camera::Update(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		UpdateViewMatrix();
	}

	void Camera::UpdateViewMatrix()
	{
		/*
		vec3 target = mPosition + mDirection;
		mViewMatrix = lookAt(mPosition, target, mUp);
		*/
		Vector3f target = mPosition + mDirection;
		mViewMatrix = MatrixHelper::LookAt(mPosition, target, mUp);
	}

	void Camera::UpdateProjectionMatrix()
	{
		mProjectionMatrix = MatrixHelper::Perspective(mFieldOfView, mAspectRatio, mNearPlaneDistance, mFarPlaneDistance);
	}

	/*
	void Camera::ApplyRotation(const glm::mat4& transform)
	{
		vec4 direction = transform * vec4(mDirection, 0.0f);
		mDirection = (vec3)normalize(direction);

		vec4 up	= transform * vec4(mUp, 0.0f);
		mUp = (vec3)normalize(up);

		mRight = cross(mDirection, mUp);
		mUp = cross(mRight, mDirection);
	}
	*/
	void Camera::ApplyRotation(const Matrix4f& transform)
	{
		Vector4f direction = transform * Vector4f(mDirection.x(), mDirection.y(), mDirection.z(), 0.0f);
		mDirection = direction.normalized().head<3>();

		Vector4f up = transform * Vector4f(mUp.x(), mUp.y(), mUp.z(), 0.0f);
		mUp = up.normalized().head<3>();

		mRight = mDirection.cross(mUp);
		mUp = mRight.cross(mDirection);
	}
}