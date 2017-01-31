#pragma once

//#include "glm/glm.hpp"
#include <Eigen/Core>

#include <random>

namespace Library
{
	class ColorHelper final
	{
	public:
		ColorHelper() = delete;
		ColorHelper(const ColorHelper&) = delete;
		ColorHelper& operator=(const ColorHelper&) = delete;
		ColorHelper(ColorHelper&&) = delete;
		ColorHelper& operator=(ColorHelper&&) = delete;
		~ColorHelper() = default;
		/*
		static const glm::vec4 Black;
		static const glm::vec4 White;
		static const glm::vec4 Red;
		static const glm::vec4 Green;
		static const glm::vec4 Blue;
		static const glm::vec4 Yellow;
		static const glm::vec4 BlueGreen;
		static const glm::vec4 Purple;
		static const glm::vec4 CornflowerBlue;
		static const glm::vec4 Wheat;
		static const glm::vec4 LightGray;

		static glm::vec4 RandomColor();
		*/

		static const Eigen::Vector4f Black;
		static const Eigen::Vector4f White;
		static const Eigen::Vector4f Red;
		static const Eigen::Vector4f Green;
		static const Eigen::Vector4f Blue;
		static const Eigen::Vector4f Yellow;
		static const Eigen::Vector4f BlueGreen;
		static const Eigen::Vector4f Purple;
		static const Eigen::Vector4f CornflowerBlue;
		static const Eigen::Vector4f Wheat;
		static const Eigen::Vector4f LightGray;

		static Eigen::Vector4f RandomColor();

	private:
		static std::random_device sDevice;
		static std::default_random_engine sGenerator;
		static std::uniform_real_distribution<float> sDistribution;
	};
}