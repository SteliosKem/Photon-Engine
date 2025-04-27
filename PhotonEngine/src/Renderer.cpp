#include "Renderer.h"
#include "Utility.h"
#include "Objects.h"

namespace Photon {
	void Renderer::render(std::vector<uint8_t>& data) const {
		for (int i = 0; i < m_camera.image_height(); i++) {
			// For every row from top to bottom, output all pixels from left to right
			for (int k = 0; k < m_camera.image_width(); k++) {
				glm::vec3 pixel_center = m_camera.origin_pixel() + (float)i * m_camera.dh() + (float)k * m_camera.dw();
				glm::vec3 ray_direction = pixel_center - m_camera.position();

				Ray ray(m_camera.position(), ray_direction);
				Color color = hit_color(ray);
				data.push_back(write_color_value(color.r));
				data.push_back(write_color_value(color.g));
				data.push_back(write_color_value(color.b));
			}
		}
	}

	Color Renderer::hit_color(const Ray& ray) const {
		HitInfo h = Sphere(glm::vec3{ 0.0f, 0.0f, -1.0f }, 0.9f).hit(ray, 0.0f, 100.0f);
		float t = h.t;
		if (t > 0) {
			glm::vec3 normal = ray.get_point_at(t) - glm::vec3{ 0.0f, 0.0f, -1.0f };
			normal /= 0.9f;
			return 0.5f * Color{ normal.x + 1, normal.y + 1, normal.z + 1 };
		}

		glm::vec3 unit_direction = glm::normalize(ray.direction());
		//glm::vec3 unit_direction = ray.direction() / (float)ray.direction().length();
		float a = 0.5f * (unit_direction.y + 1.0f);
		return (1 - a) * Color { 1.0f } + a * Color{ 0.0f };
	}
}