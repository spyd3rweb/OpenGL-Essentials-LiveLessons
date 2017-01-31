#pragma once

//#include "glm/glm.hpp"
#include <Eigen/Core>

namespace Library
{
	class MatrixHelper final
	{
	public:
		MatrixHelper() = delete;
		MatrixHelper(const MatrixHelper& ) = delete;
		MatrixHelper& operator=(const MatrixHelper&) = delete;
		MatrixHelper(MatrixHelper&&) = delete;
		MatrixHelper& operator=(MatrixHelper&&) = delete;
		~MatrixHelper() = default;

		/*
		static void GetForward(glm::mat4& matrix, glm::vec3& vector);
		static void GetUp(glm::mat4& matrix, glm::vec3& vector);
		static void GetRight(glm::mat4& matrix, glm::vec3& vector);
		static void GetTranslation(glm::mat4& matrix, glm::vec3& vector);
		*/
		static void GetForward(Eigen::Matrix4f& matrix, Eigen::Vector3f& vector);
		static void GetUp(Eigen::Matrix4f& matrix, Eigen::Vector3f& vector);
		static void GetRight(Eigen::Matrix4f& matrix, Eigen::Vector3f& vector);
		static void GetTranslation(Eigen::Matrix4f& matrix, Eigen::Vector3f& vector);

		/*
		static void SetForward(glm::mat4& matrix, glm::vec3& forward);
		static void SetUp(glm::mat4& matrix, glm::vec3& up);
		static void SetRight(glm::mat4& matrix, glm::vec3& right);
		static void SetTranslation(glm::mat4& matrix, glm::vec3& translation);
		*/
		static void SetForward(Eigen::Matrix4f& matrix, Eigen::Vector3f& forward);
		static void SetUp(Eigen::Matrix4f& matrix, Eigen::Vector3f& up);
		static void SetRight(Eigen::Matrix4f& matrix, Eigen::Vector3f& right);
		static void SetTranslation(Eigen::Matrix4f& matrix, Eigen::Vector3f& translation);

		/* New */
		static float Radians(float degreef);
		static Eigen::Matrix4f Perspective(float fovy, float aspect, float zNear, float zFar);
		static Eigen::Matrix4f LookAt(Eigen::Vector3f const & eye, Eigen::Vector3f const & center, Eigen::Vector3f const & up);

	};
}