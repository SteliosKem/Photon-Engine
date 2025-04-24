#include "Render.h"
#include <string>
#include <format>
#include <fstream>

namespace Photon {
	void format_ppm(LowRes_PixelDataArray& data, const std::filesystem::path& out_path) {
		std::string text_out = "";

		text_out += "P3\n";
		// Specify {width} {height} and color format {255}
		text_out += std::format("{} {} 255\n", data[0].size(), data.size());

		for (auto& row : data) {
			// For every row from top to bottom, output all pixels from left to right
			for (auto& pixel : row) {
				// Change scale from 0-1 float to 0-255 int
				uint8_t r = uint8_t(pixel.r * 255.999);
				uint8_t g = uint8_t(pixel.g * 255.999);
				uint8_t b = uint8_t(pixel.b * 255.999);
				text_out += std::format("{} {} {}\n", r, g, b);
			}
		}

		// Write to file
		std::ofstream out_file(out_path);
		out_file << text_out;
		out_file.close();
	}
}

int main() {
	Photon::LowRes_PixelDataArray* data = new Photon::LowRes_PixelDataArray{ { Photon::Color3{ 0.5f, 0.5f, 0.5f } } };
	(*data)[0][0] = Photon::Color3{0.5f, 0.5f, 0.5f};
	Photon::format_ppm(*data, "C:/Projects/Photon-Engine/bin/windows-x86_64/Debug/PhotonEditor/a.ppm");
}