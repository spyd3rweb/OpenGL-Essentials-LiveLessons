#include "pch.h"

//using namespace glm;
using namespace Eigen;
using namespace std;

namespace Library
{
	RTTI_DEFINITIONS(ProxyModel)

	ProxyModel::ProxyModel(Game& game, Camera& camera, const string& modelFileName, float scale) :
		DrawableGameComponent(game, camera),
		mModelFileName(modelFileName), mVertexArrayObject(0), mVertexBuffer(0),
		mIndexBuffer(0), mIndexCount(0), mDisplayWireframe(true), mPosition(Vector3Helper::Zero),
		mDirection(Vector3Helper::Forward), mUp(Vector3Helper::Up), mRight(Vector3Helper::Right), 
		mWorldMatrix(Eigen::Matrix4f::Identity()), mScaleMatrix()
	{
		//mScaleMatrix = glm::scale(mat4(), vec3(scale));
		mScaleMatrix = Affine3f(Eigen::UniformScaling<float>(scale)).matrix();
	}

	ProxyModel::~ProxyModel()
	{
		glDeleteBuffers(1, &mIndexBuffer);
		glDeleteBuffers(1, &mVertexBuffer);
		glDeleteVertexArrays(1, &mVertexArrayObject);
	}

	//const vec3& ProxyModel::Position() const
	const Vector3f& ProxyModel::Position() const
    {
        return mPosition;
    }

    //const vec3& ProxyModel::Direction() const
	const Vector3f& ProxyModel::Direction() const
    {
        return mDirection;
    }
    
    //const vec3& ProxyModel::Up() const
	const Vector3f& ProxyModel::Up() const
    {
        return mUp;
    }

    //const vec3& ProxyModel::Right() const
	const Vector3f& ProxyModel::Right() const
    {
        return mRight;
    }

	bool& ProxyModel::DisplayWireframe()
	{
		return mDisplayWireframe;
	}

	void ProxyModel::SetPosition(float x, float y, float z)
    {
		//mPosition = vec3(x, y, z);
		mPosition = Vector3f(x, y, z);
    }

    //void ProxyModel::SetPosition(const vec3& position)
	void ProxyModel::SetPosition(const Vector3f& position)
    {
        mPosition = position;
    }

	/*
	void ProxyModel::ApplyRotation(const mat4& transform)
	{
		vec4 direction = transform * vec4(mDirection, 0.0f);
		mDirection = static_cast<vec3>(normalize(direction));

		vec4 up = transform * vec4(mUp, 0.0f);
		mUp = static_cast<vec3>(normalize(up));

		mRight = cross(mDirection, mUp);
		mUp = cross(mRight, mDirection);
	}
	*/
	void ProxyModel::ApplyRotation(const Matrix4f& transform)
	{
		Vector4f direction = transform * Vector4f(mDirection.x(), mDirection.y(), mDirection.z(), 0.0f);
		mDirection = direction.normalized().head<3>();

		Vector4f up = transform * Vector4f(mUp.x(), mUp.y(), mUp.z(), 0.0f);
		mUp = up.normalized().head<3>();

		mRight = mDirection.cross(mUp);
		mUp = mRight.cross(mDirection);
	}

	void ProxyModel::Initialize()
	{
		SetCurrentDirectory(Utility::ExecutableDirectory().c_str());

		// Build the shader program
		vector<ShaderDefinition> shaders;
		shaders.push_back(ShaderDefinition(GL_VERTEX_SHADER, L"Content\\Effects\\BasicEffect.vert"));
		shaders.push_back(ShaderDefinition(GL_FRAGMENT_SHADER, L"Content\\Effects\\BasicEffect.frag"));
		mShaderProgram.BuildProgram(shaders);

		Model model(mModelFileName, true);

		// Create the vertex and index buffers
		Mesh* mesh = model.Meshes().at(0);
		mShaderProgram.CreateVertexBuffer(*mesh, mVertexBuffer);
		mesh->CreateIndexBuffer(mIndexBuffer);
		mIndexCount = mesh->Indices().size();

		// Create the vertex array object
		glGenVertexArrays(1, &mVertexArrayObject);
		mShaderProgram.Initialize(mVertexArrayObject);
		glBindVertexArray(0);
	}

	void ProxyModel::Update(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		//mat4 worldMatrix;
		Matrix4f worldMatrix = Eigen::Matrix4f::Identity();
		MatrixHelper::SetForward(worldMatrix, mDirection);
		MatrixHelper::SetUp(worldMatrix, mUp);
		MatrixHelper::SetRight(worldMatrix, mRight);
		MatrixHelper::SetTranslation(worldMatrix, mPosition);

		mWorldMatrix = worldMatrix * mScaleMatrix;
	}

	void ProxyModel::Draw(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);

		mShaderProgram.Use();

		//mat4 wvp = mCamera->ViewProjectionMatrix() * mWorldMatrix;
		Matrix4f wvp = mCamera->ViewProjectionMatrix() * mWorldMatrix;
		mShaderProgram.WorldViewProjection() << wvp;

		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CCW);

		if (mDisplayWireframe)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, 0);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		else
		{
			glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, 0);
		}

		glBindVertexArray(0);
	}
}