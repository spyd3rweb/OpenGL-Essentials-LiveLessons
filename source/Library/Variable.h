#pragma once

#include <GL/glcorearb.h>
//#include "glm/glm.hpp"
#include <Eigen/Core>
#include <string>

namespace Library
{
	class ShaderProgram;

    class Variable final
    {
    public:
		Variable(ShaderProgram& shaderProgram, const std::string& name);
		Variable(const Variable&) = delete;
		Variable& operator=(const Variable&) = delete;
		Variable(Variable&&) = delete;
		Variable& operator=(Variable&&) = delete;
		~Variable() = default;

        ShaderProgram& GetShaderProgram();
		const GLint& Location() const;
        const std::string& Name() const;

		/*
		Variable& operator<<(const glm::mat4& value);
		Variable& operator<<(const glm::vec4& value);
		Variable& operator<<(const glm::vec3& value);
		Variable& operator<<(const glm::vec2& value);
		*/
        Variable& operator<<(const Eigen::Matrix4f& value);
        Variable& operator<<(const Eigen::Vector4f& value);
		Variable& operator<<(const Eigen::Vector3f& value);
		Variable& operator<<(const Eigen::Vector2f& value);
		Variable& operator<<(float value);
		Variable& operator<<(int value);

    private:
		ShaderProgram& mShaderProgram;
		GLint mLocation;
        std::string mName;
    };
}