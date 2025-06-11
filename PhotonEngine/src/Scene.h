#pragma once
#include "Objects.h"
#include "Utility.h"

namespace Photon {
	class Scene {
	public:
		Scene() {}
		~Scene() {}

		void add(ptr<Object> object) { m_objects.push_back(object); }
		void clear() { m_objects.clear(); }
	private:
		std::vector<ptr<Object>> m_objects;
	};
}