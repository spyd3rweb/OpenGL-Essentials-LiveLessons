#include "pch.h"

//using namespace glm;
using namespace Eigen;

namespace Library
{
	RTTI_DEFINITIONS(FirstPersonCamera)

		//const float FirstPersonCamera::DefaultRotationRate = radians(1.0f);
		const float FirstPersonCamera::DefaultRotationRate = MatrixHelper::Radians(1.0f);
    const float FirstPersonCamera::DefaultMovementRate = 10.0f;
    const float FirstPersonCamera::DefaultMouseSensitivity = 3.0f;

    FirstPersonCamera::FirstPersonCamera(Game& game) :
		Camera(game),
        mMouseSensitivity(DefaultMouseSensitivity), mRotationRate(DefaultRotationRate), mMovementRate(DefaultMovementRate),
		mLastCursorX(0.0), mLastCursorY(0.0)
    {
    }

    FirstPersonCamera::FirstPersonCamera(Game& game, float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance) :
		Camera(game, fieldOfView, aspectRatio, nearPlaneDistance, farPlaneDistance),
        mMouseSensitivity(DefaultMouseSensitivity), mRotationRate(DefaultRotationRate), mMovementRate(DefaultMovementRate),
		mLastCursorX(0.0), mLastCursorY(0.0)
    {
    }

    float&FirstPersonCamera:: MouseSensitivity()
    {
        return mMouseSensitivity;
    }

    float& FirstPersonCamera::RotationRate()
    {
        return mRotationRate;
    }

    float& FirstPersonCamera::MovementRate()
    {
        return mMovementRate;
    }

    void FirstPersonCamera::Initialize()
    {
        Camera::Initialize();

		glfwGetCursorPos(mGame->Window(), &mLastCursorX, &mLastCursorY);
    }

    void FirstPersonCamera::Update(const GameTime& gameTime)
    {
		//vec2 movementAmount = Vector2Helper::Zero;
		Vector2f movementAmount = Vector2Helper::Zero;
		if (glfwGetKey(mGame->Window(), GLFW_KEY_W))
		{
			movementAmount.y() = 1.0f;
		}

		if (glfwGetKey(mGame->Window(), GLFW_KEY_S))
		{
			movementAmount.y() = -1.0f;
		}

		if (glfwGetKey(mGame->Window(), GLFW_KEY_A))
		{
			movementAmount.x() = -1.0f;
		}

		if (glfwGetKey(mGame->Window(), GLFW_KEY_D))
		{
			movementAmount.x() = 1.0f;
		}

		//vec2 rotationAmount = Vector2Helper::Zero;
		Vector2f rotationAmount = Vector2Helper::Zero;
		
		double x, y;
		glfwGetCursorPos(mGame->Window(), &x, &y);		

		if (glfwGetMouseButton(mGame->Window(), GLFW_MOUSE_BUTTON_LEFT))
		{
			rotationAmount.x() = static_cast<float>(mLastCursorX - x) * mMouseSensitivity;
			rotationAmount.y() = static_cast<float>(mLastCursorY - y) * mMouseSensitivity;
		}

		mLastCursorX = x;
		mLastCursorY = y;

		float elapsedTime = gameTime.ElapsedGameTimeSeconds().count();
		//vec2 rotationVector = rotationAmount * mRotationRate * elapsedTime;
		Vector2f rotationVector = rotationAmount * mRotationRate * elapsedTime;

		/*
		mat4 rotationMatrix = rotate(mat4(), rotationVector.y, mRight);
		rotationMatrix = rotate(rotationMatrix, rotationVector.x, Vector3Helper::Up);
		*/

		Affine3f rotationMatrix = (Affine3f(AngleAxisf(rotationVector.y(), mRight)) * Affine3f(AngleAxisf(rotationVector.x(), Vector3Helper::Up)));
		ApplyRotation(rotationMatrix.matrix());

		//vec2 movement = movementAmount * mMovementRate * elapsedTime;
		Vector2f movement = movementAmount * mMovementRate * elapsedTime;

		//vec3 strafe = mRight * movement.x;
		Vector3f strafe = mRight * movement.x();
		mPosition += strafe;

		//vec3 forward = mDirection * movement.y;
		Vector3f forward = mDirection * movement.y();
		mPosition += forward;

        Camera::Update(gameTime);
    }
}
