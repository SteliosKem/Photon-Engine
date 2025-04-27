#include "main.h"
#include <string>
#include <format>
#include <fstream>
#include <iostream>
#include "Renderer.h"

namespace Photon {
	using namespace Photon;
	void format_ppm(const std::filesystem::path& out_path) {
		std::string text_out = "";

		Renderer renderer{ Camera{ glm::vec3{0.0f}, 16.0f/9.0f, 400, 0.4f} };

		size_t width = renderer.camera().image_width();
		size_t height = renderer.camera().image_height();

		text_out += "P3\n";
		// Specify {width} {height} and color format {255}
		text_out += std::format("{} {} 255\n", width, height);

		std::cout << "Rendering...\n";

		std::vector<uint8_t> values{};
		renderer.render(values);

		for (int i = 0; i < values.size(); i += 3) {
			text_out += std::format("{} {} {}\n", values[i], values[i + 1], values[i + 2]);
		}

		std::cout << std::endl;

		// Write to file
		std::ofstream out_file(out_path);
		out_file << text_out;
		out_file.close();
	}
}

int main() {
	Photon::format_ppm("C:/Projects/Photon-Engine/bin/windows-x86_64/Debug/PhotonEditor/a.ppm");
}