#pragma once

//#include "glm/glm.hpp"
#include <Eigen/Core>
#include <string>

namespace Library
{
	class Vector2Helper final
	{
	public:
		Vector2Helper() = delete;
		Vector2Helper(const Vector2Helper&) = delete;
		Vector2Helper& operator=(const Vector2Helper&) = delete;
		Vector2Helper(Vector2Helper&&) = delete;
		Vector2Helper& operator=(Vector2Helper&&) = delete;
		~Vector2Helper() = default;

		/*
		static const glm::vec2 Zero;
		static const glm::vec2 One;


		static std::string ToString(const glm::vec2& vector);
		*/
		static const Eigen::Vector2f Zero;
		static const Eigen::Vector2f One;

		static std::string ToString(const Eigen::Vector2f& vector);
	};

	class Vector3Helper
	{
	public:
		Vector3Helper() = delete;
		Vector3Helper(const Vector3Helper&) = delete;
		Vector3Helper& operator=(const Vector3Helper&) = delete;
		Vector3Helper(Vector3Helper&&) = delete;
		Vector3Helper& operator=(Vector3Helper&&) = delete;
		~Vector3Helper() = default;

		/*
		static const glm::vec3 Zero;
		static const glm::vec3 One;
		static const glm::vec3 Forward;
		static const glm::vec3 Backward;
		static const glm::vec3 Up;
		static const glm::vec3 Down;
		static const glm::vec3 Right;
		static const glm::vec3 Left;

		static std::string ToString(const glm::vec3& vector);
		*/

		static const Eigen::Vector3f Zero;
		static const Eigen::Vector3f One;
		static const Eigen::Vector3f Forward;
		static const Eigen::Vector3f Backward;
		static const Eigen::Vector3f Up;
		static const Eigen::Vector3f Down;
		static const Eigen::Vector3f Right;
		static const Eigen::Vector3f Left;

		static std::string ToString(const Eigen::Vector3f& vector);
	};

	class Vector4Helper
	{
	public:
		Vector4Helper() = delete;
		Vector4Helper(const Vector4Helper&) = delete;
		Vector4Helper& operator=(const Vector4Helper&) = delete;
		Vector4Helper(Vector4Helper&&) = delete;
		Vector4Helper& operator=(Vector4Helper&&) = delete;
		~Vector4Helper() = default;
		/*
		static const glm::vec4 Zero;
		static const glm::vec4 One;

		static std::string ToString(const glm::vec4& vector);
		*/
		static const Eigen::Vector4f Zero;
		static const Eigen::Vector4f One;

		static std::string ToString(const Eigen::Vector4f& vector);
	};
}