#include "pch.h"

//using namespace glm;
using namespace Eigen;

namespace Library
{
	Variable::Variable(ShaderProgram& shaderProgram, const std::string& name) :
		mShaderProgram(shaderProgram), mLocation(-1), mName(name)
	{
		mLocation = glGetUniformLocation(mShaderProgram.Program(), name.c_str());
		if (mLocation == -1)
		{
			throw GameException("glGetUniformLocation() did not find uniform location.");
		}
	}

	ShaderProgram& Variable::GetShaderProgram()
	{
		return mShaderProgram;
	}

	const GLint& Variable::Location() const
	{
		return mLocation;
	}
	
	const std::string& Variable::Name() const
	{
		return mName;
	}

	Variable& Variable::operator<<(const Matrix4f& value)
	{
		//glUniformMatrix4fv(mLocation, 1, GL_FALSE, &value[0][0]);
		glUniformMatrix4fv(mLocation, 1, GL_FALSE, value.data());

		return *this;
	}

	//Variable& Variable::operator<<(const vec4& value)
	Variable& Variable::operator<<(const Vector4f& value)
	{
		//glUniform4fv(mLocation, 1, &value[0]);
		glUniform4fv(mLocation, 1, value.data());
	
		return *this;
	}

	//Variable& Variable::operator<<(const vec3& value)
	Variable& Variable::operator<<(const Vector3f& value)
	{
		//glUniform3fv(mLocation, 1, &value[0]);
		glUniform4fv(mLocation, 1, value.data());

		return *this;
	}

	//Variable& Variable::operator<<(const vec2& value)
	Variable& Variable::operator<<(const Vector2f& value)
	{
		//glUniform2fv(mLocation, 1, &value[0]);
		glUniform2fv(mLocation, 1, value.data());

		return *this;
	}

	Variable& Variable::operator<<(float value)
	{
		glUniform1f(mLocation, value);				

		return *this;
	}

	Variable& Variable::operator<<(int value)
	{
		glUniform1i(mLocation, value);

		return *this;
	}
}