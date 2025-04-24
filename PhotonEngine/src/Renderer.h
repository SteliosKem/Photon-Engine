#pragma once
#include "Camera.h"
#include "Ray.h"
#include <vector>

namespace Photon {
	class Renderer {
	public:
		Renderer() {}
		~Renderer() {}

		Renderer(const Camera& camera) : m_camera{ camera } {}

		void render(std::vector<uint8_t>& data) const;

		// Getters
		const Camera& camera() const { return m_camera; }
	private:
		glm::vec3 hit_color(const Ray& ray) const;
	private:
		Camera m_camera;
	};
}