#pragma once

//#include "glm/glm.hpp"
#include <Eigen/Core>

namespace Library
{
	class VertexPosition final
    {
	public:
        //glm::vec4 Position;
		Eigen::Vector4f Position;

        VertexPosition() { }

		/*
		VertexPosition(const glm::vec4& position) :
		Position(position){ }
		*/
		VertexPosition(const Eigen::Vector4f& position) :
			Position(position){ }
    };

	class VertexPositionColor final
    {
	public:
		/*
		glm::vec4 Position;
		glm::vec4 Color;
		*/
		Eigen::Vector4f Position;
		Eigen::Vector4f Color;

        VertexPositionColor() { }

		/*
		VertexPositionColor(const glm::vec4& position, const glm::vec4& color) :
		Position(position), Color(color) { }
		*/
		VertexPositionColor(const Eigen::Vector4f& position, const Eigen::Vector4f& color) :
			Position(position), Color(color) { }
    };

	class VertexPositionColorTexture final
	{
	public:
		/*
		glm::vec4 Position;
		glm::vec4 Color;
		glm::vec2 TextureCoordinates;
		*/
		Eigen::Vector4f Position;
		Eigen::Vector4f Color;
		Eigen::Vector2f TextureCoordinates;

		VertexPositionColorTexture() { }

		/*
		VertexPositionColorTexture(const glm::vec4& position, const glm::vec4& color, const glm::vec2& textureCoordinates) :
		Position(position), Color(color), TextureCoordinates(textureCoordinates) { }
		*/
		VertexPositionColorTexture(const Eigen::Vector4f& position, const Eigen::Vector4f& color, const Eigen::Vector2f& textureCoordinates) :
			Position(position), Color(color), TextureCoordinates(textureCoordinates) { }
	};

	class VertexPositionTexture final
	{
	public:
		/*
		glm::vec4 Position;
		glm::vec2 TextureCoordinates;
		*/
		Eigen::Vector4f Position;
		Eigen::Vector2f TextureCoordinates;

		VertexPositionTexture() { }

		/*
		VertexPositionTexture(const glm::vec4& position, const glm::vec2& textureCoordinates) :
		Position(position), TextureCoordinates(textureCoordinates) { }
		*/
		VertexPositionTexture(const Eigen::Vector4f& position, const Eigen::Vector2f& textureCoordinates) :
			Position(position), TextureCoordinates(textureCoordinates) { }
	};

	class VertexPositionSize final
	{
	public:
		/*
		glm::vec4 Position;
		glm::vec2 Size;
		*/
		Eigen::Vector4f Position;
		Eigen::Vector2f Size;

		VertexPositionSize() { }

		VertexPositionSize(const Eigen::Vector4f& position, const Eigen::Vector2f& size) :
			Position(position), Size(size) { }
	};

	class VertexPositionNormal final
    {
	public:
		/*
		glm::vec4 Position;
		glm::vec3 Normal;
		*/
		Eigen::Vector4f Position;
		Eigen::Vector3f Normal;

        VertexPositionNormal() { }

		/*
		VertexPositionNormal(const glm::vec4& position, const glm::vec3& normal) :
		Position(position), Normal(normal) { }
		*/
		VertexPositionNormal(const Eigen::Vector4f& position, const Eigen::Vector3f& normal) :
			Position(position), Normal(normal) { }
    };

	class VertexPositionTextureNormal final
	{
	public:
		/*
		glm::vec4 Position;
		glm::vec2 TextureCoordinates;
		glm::vec3 Normal;
		*/
		Eigen::Vector4f Position;
		Eigen::Vector2f TextureCoordinates;
		Eigen::Vector3f Normal;

		VertexPositionTextureNormal() { }

		/*
		VertexPositionTextureNormal(const glm::vec4& position, const glm::vec2& textureCoordinates, const glm::vec3& normal) :
		Position(position), TextureCoordinates(textureCoordinates), Normal(normal) { }
		*/
		VertexPositionTextureNormal(const Eigen::Vector4f& position, const Eigen::Vector2f& textureCoordinates, const Eigen::Vector3f& normal) :
			Position(position), TextureCoordinates(textureCoordinates), Normal(normal) { }
	};

	class VertexPositionTextureNormalTangentBinormal final
	{
	public:
		/*
		glm::vec4 Position;
		glm::vec2 TextureCoordinates;
		glm::vec3 Normal;
		glm::vec3 Tangent;
		glm::vec3 Binormal;
		*/
		Eigen::Vector4f Position;
		Eigen::Vector2f TextureCoordinates;
		Eigen::Vector3f Normal;
		Eigen::Vector3f Tangent;
		Eigen::Vector3f Binormal;

		VertexPositionTextureNormalTangentBinormal() { }

		/*
		VertexPositionTextureNormalTangentBinormal(const glm::vec4& position, const glm::vec2& textureCoordinates, const glm::vec3& normal, const glm::vec3& tangent, const glm::vec3& binormal) :
		Position(position), TextureCoordinates(textureCoordinates), Normal(normal), Tangent(tangent), Binormal(binormal) { }
		*/
		VertexPositionTextureNormalTangentBinormal(const Eigen::Vector4f& position, const Eigen::Vector2f& textureCoordinates, const Eigen::Vector3f& normal, const Eigen::Vector3f& tangent, const Eigen::Vector3f& binormal) :
			Position(position), TextureCoordinates(textureCoordinates), Normal(normal), Tangent(tangent), Binormal(binormal) { }
	};

	class VertexSkinnedPositionTextureNormal final
	{
	public:
		/*
		glm::vec4 Position;
		glm::vec2 TextureCoordinates;
		glm::vec3 Normal;
		glm::uvec4 BoneIndices;
		glm::vec4 BoneWeights;
		*/
		Eigen::Vector4f Position;
		Eigen::Vector2f TextureCoordinates;
		Eigen::Vector3f Normal;
		Eigen::Vector4i BoneIndices;
		Eigen::Vector4f BoneWeights;

		VertexSkinnedPositionTextureNormal() { }
		/*
		VertexSkinnedPositionTextureNormal(const glm::vec4& position, const glm::vec2& textureCoordinates, const glm::vec3& normal, const glm::uvec4& boneIndices, const glm::vec4& boneWeights) :
		Position(position), TextureCoordinates(textureCoordinates), Normal(normal), BoneIndices(boneIndices), BoneWeights(boneWeights) { }
		*/
		VertexSkinnedPositionTextureNormal(const Eigen::Vector4f& position, const Eigen::Vector2f& textureCoordinates, const Eigen::Vector3f& normal, const Eigen::Vector4i& boneIndices, const Eigen::Vector4f& boneWeights) :
			Position(position), TextureCoordinates(textureCoordinates), Normal(normal), BoneIndices(boneIndices), BoneWeights(boneWeights) { }
	};
}
