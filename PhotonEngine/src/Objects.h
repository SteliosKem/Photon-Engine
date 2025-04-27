#pragma once
#include "glm/glm.hpp"

namespace Photon {
	class Sphere {
	public:
		Sphere() {}
		~Sphere() {}

		Sphere(const glm::vec3& position, float radius) : m_position{ position }, m_radius{ radius } {}

		const glm::vec3& position() const { return m_position; }
		float radius() const { return m_radius; }

		glm::vec3& position() { return m_position; }
		float& radius() { return m_radius; }
	private:
		glm::vec3 m_position{ 0.0f };
		float m_radius{ 1.0f };
	};
}