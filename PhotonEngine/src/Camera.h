#pragma once
#include <cstdint>
#include "glm/glm.hpp"

namespace Photon {
	class Camera {
	public:
		Camera() {}
		~Camera() {}

		Camera(const glm::vec3& position, float aspect_ratio, uint32_t image_width, float focal_length) : 
			m_camera_pos{ position }, m_aspect_ratio{ aspect_ratio }, m_image_width{ image_width }, m_focal_length{ focal_length } {
			recalculate(); 
		}

		// Getters

		float aspect_ratio() const { return m_aspect_ratio; }
		uint32_t image_width() const { return m_image_width; }
		uint32_t image_height() const { return m_image_height; }

		float viewport_width() const { return m_viewport_width; }
		float viewport_height() const { return m_viewport_height; }

		const glm::vec3& position() const { return m_camera_pos; }
		const glm::vec3& origin_pixel() const { return m_origin_pixel; }
		const glm::vec3& dw() const { return m_dw; }
		const glm::vec3& dh() const { return m_dh; }

		// Setters

		void aspect_ratio(float aspect_ratio) {
			m_aspect_ratio = aspect_ratio;
			recalculate();
		}
		void image_width(uint32_t width) {
			m_image_width = width;
			recalculate();
		}
		void viewport_height(float hight) { 
			m_viewport_height = hight;
			recalculate();
		}
	private:
		void recalculate() {
			m_image_height = uint32_t(m_image_width / m_aspect_ratio);
			// Image height cannot be less than 1
			m_image_height = (m_image_height < 1) ? 1 : m_image_height;
			m_viewport_width = m_viewport_height * (float(m_image_width) / m_image_height);

			m_width_vector = { m_viewport_width, 0.0f, 0.0f };
			m_height_vector = { 0.0f, -m_viewport_height, 0.0f };
			m_dw = m_width_vector / (float)m_image_width;
			m_dh = m_height_vector / (float)m_image_height;

			m_viewport_upper_left = m_camera_pos - glm::vec3{ 0.0f, 0.0f, m_focal_length } - (m_viewport_width / 2.0f) - (m_viewport_height / 2.0f);
			m_origin_pixel = m_viewport_upper_left + (m_dw / 2.0f) + (m_dh / 2.0f);
		}
	private:
		// Camera
		glm::vec3 m_camera_pos{ 0.0f };
		float m_aspect_ratio{ 16.0f / 9.0f };
		float m_focal_length{ 1.0f };
		uint32_t m_image_width{ 400 };
		uint32_t m_image_height{ 400 };

		// Viewport
		float m_viewport_width{ 2.0f };
		float m_viewport_height{ 2.0f };

		glm::vec3 m_width_vector{};
		glm::vec3 m_height_vector{};
		// Delta Width
		glm::vec3 m_dw{};
		// Delta Height
		glm::vec3 m_dh{};

		glm::vec3 m_viewport_upper_left{};
		glm::vec3 m_origin_pixel{};
	};
}