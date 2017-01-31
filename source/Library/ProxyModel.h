#pragma once

//#include "glm/glm.hpp"
#include <Eigen/Core>
#include "DrawableGameComponent.h"
#include "BasicEffect.h"

namespace Library
{
	class Mesh;

	class ProxyModel final : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(ProxyModel, DrawableGameComponent)

	public:
		ProxyModel(Game& game, Camera& camera, const std::string& modelFileName, float scale = 1.0f);
		ProxyModel(const ProxyModel&) = delete;
		ProxyModel& operator=(const ProxyModel&) = delete;
		ProxyModel(ProxyModel&&) = delete;
		ProxyModel& operator=(ProxyModel&&) = delete;
		~ProxyModel();

		/*
		const glm::vec3& Position() const;
		const glm::vec3& Direction() const;
		const glm::vec3& Up() const;
		const glm::vec3& Right() const;
		*/
		const Eigen::Vector3f& Position() const;
        const Eigen::Vector3f& Direction() const;
        const Eigen::Vector3f& Up() const;
        const Eigen::Vector3f& Right() const;

		bool& DisplayWireframe();

		void SetPosition(float x, float y, float z);
		/*
		void SetPosition(const glm::vec3& position);

		void ApplyRotation(const glm::mat4& transform);
		*/
        void SetPosition(const Eigen::Vector3f& position);

        void ApplyRotation(const Eigen::Matrix4f& transform);

		virtual void Initialize() override;
		virtual void Update(const GameTime& gameTime) override;		
		virtual void Draw(const GameTime& gameTime) override;

	private:
		/*
		glm::mat4 mWorldMatrix;
		glm::mat4 mScaleMatrix;
		glm::vec3 mPosition;
		glm::vec3 mDirection;
		glm::vec3 mUp;
		glm::vec3 mRight;
		*/
		Eigen::Matrix4f mWorldMatrix;
		Eigen::Matrix4f mScaleMatrix;
		Eigen::Vector3f mPosition;
		Eigen::Vector3f mDirection;
		Eigen::Vector3f mUp;
		Eigen::Vector3f mRight;
		std::string mModelFileName;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		std::uint32_t mIndexCount;				
		bool mDisplayWireframe;
		BasicEffect mShaderProgram;
	};
}