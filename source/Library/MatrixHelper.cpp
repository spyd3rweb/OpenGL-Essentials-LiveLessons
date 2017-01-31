#include "pch.h"

//using namespace glm;
using namespace Eigen;

namespace Library
{
	//void MatrixHelper::GetForward(mat4& matrix, vec3& vector)
	void MatrixHelper::GetForward(Matrix4f& matrix, Vector3f& vector)
	{
		//vec4 m3 = matrix[2];
		Vector4f m3 = matrix.col(2);

        vector.x() = -m3.x();
        vector.y() = -m3.y();
        vector.z() = -m3.z();
	}

	//void MatrixHelper::GetUp(mat4& matrix, vec3& vector)
	void MatrixHelper::GetUp(Matrix4f& matrix, Vector3f& vector)
	{
		//vec4 m2 = matrix[1];
		Vector4f m2 = matrix.col(1);

		vector.x() = m2.x();
        vector.y() = m2.y();
        vector.z() = m2.z();
	}

	//void MatrixHelper::GetRight(mat4& matrix, vec3& vector)
	void MatrixHelper::GetRight(Matrix4f& matrix, Vector3f& vector)
	{
		//vec4 m1 = matrix[0];
		Vector4f m1 = matrix.col(0);

		vector.x() = m1.x();
        vector.y() = m1.y();
        vector.z() = m1.z();
	}

	//void MatrixHelper::GetTranslation(mat4& matrix, vec3& vector)
	void MatrixHelper::GetTranslation(Matrix4f& matrix, Vector3f& vector)
	{
		//vec4 m4 = matrix[3];
		Vector4f m4 = matrix.col(3);
		
		vector.x() = m4.x();
        vector.y() = m4.y();
        vector.z() = m4.z();
	}

	//void MatrixHelper::SetForward(mat4& matrix, vec3& forward)
	void MatrixHelper::SetForward(Matrix4f& matrix, Vector3f& forward)
	{
		//vec4 m3 = matrix[2];
		Vector4f m3 = matrix.col(2);

		m3.x() = -forward.x();
        m3.y() = -forward.y();
        m3.z() = -forward.z();

		//matrix[2] = m3;
		matrix.col(2) = m3;
	}

	//void MatrixHelper::SetUp(mat4& matrix, vec3& up)
	void MatrixHelper::SetUp(Matrix4f& matrix, Vector3f& up)
	{
		//vec4 m2 = matrix[1];
		Vector4f m2 = matrix.col(1);

		m2.x() = up.x();
        m2.y() = up.y();
        m2.z() = up.z();

		//matrix[1] = m2;
		matrix.col(1) = m2;
	}

	//void MatrixHelper::SetRight(mat4& matrix, vec3& right)
	void MatrixHelper::SetRight(Matrix4f& matrix, Vector3f& right)
	{
		//vec4 m1 = matrix[0];
		Vector4f m1 = matrix.col(0);

		m1.x() = right.x();
        m1.y() = right.y();
        m1.z() = right.z();

		//matrix[0] = m1;
		matrix.col(0) = m1;
	}

	//void MatrixHelper::SetTranslation(mat4& matrix, vec3& translation)
	void MatrixHelper::SetTranslation(Matrix4f& matrix, Vector3f& translation)
	{
		Vector4f m4 = matrix.col(3);

		m4.x() = translation.x();
        m4.y() = translation.y();
        m4.z() = translation.z();

		//matrix[3] = m4;
		matrix.col(3) = m4;
	}

	float MatrixHelper::Radians(float degreef)
	{
		return (degreef * (M_PI / 180.0f));
	}

	/// @brief Returns a perspective transformation matrix like the one from gluPerspective
	/// @see http://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml
	/// @see glm::perspective
	Matrix4f MatrixHelper::Perspective(float fovy, float aspect, float zNear, float zFar)
	{
		Transform<float, 3, Projective> tr;
		tr.matrix().setZero();
		assert(aspect > 0);
		assert(zFar > zNear);
		float radf = Radians(fovy);
		float tan_half_fovy = static_cast<float>(std::tan(radf / 2.0f));
		tr(0, 0) = 1.0f / (aspect * tan_half_fovy);
		tr(1, 1) = 1.0f / (tan_half_fovy);
		tr(2, 2) = -(zFar + zNear) / (zFar - zNear);
		tr(3, 2) = -1.0f;
		tr(2, 3) = -(2.0f * zFar * zNear) / (zFar - zNear);
		return tr.matrix();
	}

	/// @brief Returns a view transformation matrix like the one from glu's lookAt
	/// @see http://www.opengl.org/sdk/docs/man2/xhtml/gluLookAt.xml
	/// @see glm::lookAt
	Matrix4f MatrixHelper::LookAt(Vector3f const & eye, Vector3f const & center, Vector3f const & up)
	{
		Vector3f f = (center - eye).normalized();
		Vector3f u = up.normalized();
		Vector3f s = f.cross(u).normalized();
		u = s.cross(f);
		Matrix4f mat = Matrix4f::Zero();
		mat(0, 0) = s.x();
		mat(0, 1) = s.y();
		mat(0, 2) = s.z();
		mat(0, 3) = -s.dot(eye);
		mat(1, 0) = u.x();
		mat(1, 1) = u.y();
		mat(1, 2) = u.z();
		mat(1, 3) = -u.dot(eye);
		mat(2, 0) = -f.x();
		mat(2, 1) = -f.y();
		mat(2, 2) = -f.z();
		mat(2, 3) = f.dot(eye);
		mat.row(3) << 0, 0, 0, 1;
		return mat;
	}
}