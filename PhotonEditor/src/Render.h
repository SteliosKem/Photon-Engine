#pragma once
#include <array>
#include <filesystem>
#include "glm/glm.hpp"

namespace Photon {
	using Color3 = glm::vec3;
	using HD_PixelDataArray = std::array<std::array<Color3, 1920>, 1080>;
	using LowRes_PixelDataArray = std::array<std::array<Color3, 426>, 240>;

	//void render(uint16_t width, uint16_t height, const Color3** data);
	void format_ppm(LowRes_PixelDataArray& data, const std::filesystem::path& out_path);
}