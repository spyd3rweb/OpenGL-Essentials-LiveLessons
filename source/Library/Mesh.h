#pragma once

#include "GL/glcorearb.h"
//#include "glm/glm.hpp"
#include <Eigen/Core>
#include <cstdint>
#include <string>
#include <vector>

struct aiMesh;

namespace Library
{
    class Material;
    class ModelMaterial;

    class Mesh final
    {
        friend class Model;

    public:
		Mesh(const Mesh&) = delete;
		Mesh& operator=(const Mesh&) = delete;
		Mesh(Mesh&&) = delete;
		Mesh& operator=(Mesh&&) = delete;
        ~Mesh();

        Model& GetModel();
        ModelMaterial* GetMaterial();
        const std::string& Name() const;

		/*
		const std::vector<glm::vec3>& Vertices() const;
		const std::vector<glm::vec3>& Normals() const;
		const std::vector<glm::vec3>& Tangents() const;
		const std::vector<glm::vec3>& BiNormals() const;
		const std::vector<std::vector<glm::vec3>*>& TextureCoordinates() const;
		const std::vector<std::vector<glm::vec4>*>& VertexColors() const;
		*/
        const std::vector<Eigen::Vector3f>& Vertices() const;
        const std::vector<Eigen::Vector3f>& Normals() const;
        const std::vector<Eigen::Vector3f>& Tangents() const;
        const std::vector<Eigen::Vector3f>& BiNormals() const;
        const std::vector<std::vector<Eigen::Vector3f>*>& TextureCoordinates() const;
        const std::vector<std::vector<Eigen::Vector4f>*>& VertexColors() const;
        std::uint32_t FaceCount() const;
        const std::vector<std::uint32_t>& Indices() const;

        void CreateIndexBuffer(GLuint& indexBuffer);

    private:
        Mesh(Model& model, aiMesh& mesh);

        Model& mModel;
        ModelMaterial* mMaterial;
        std::string mName;
		/*
		std::vector<glm::vec3> mVertices;
		std::vector<glm::vec3> mNormals;
		std::vector<glm::vec3> mTangents;
		std::vector<glm::vec3> mBiNormals;
		std::vector<std::vector<glm::vec3>*> mTextureCoordinates;
		std::vector<std::vector<glm::vec4>*> mVertexColors;
		*/
        std::vector<Eigen::Vector3f> mVertices;
        std::vector<Eigen::Vector3f> mNormals;
        std::vector<Eigen::Vector3f> mTangents;
        std::vector<Eigen::Vector3f> mBiNormals;
        std::vector<std::vector<Eigen::Vector3f>*> mTextureCoordinates;
        std::vector<std::vector<Eigen::Vector4f>*> mVertexColors;
        std::uint32_t mFaceCount;
        std::vector<std::uint32_t> mIndices;
    };
}