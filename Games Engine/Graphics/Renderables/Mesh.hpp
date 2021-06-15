#pragma once
#include "../Vertex.hpp"

#include "../Material.hpp"

namespace eng {
	namespace graphics {

		class Mesh {
		protected:
		public:
			Mesh(VertexArray vertices, IndexArray indices, Material material);
		};

	}
}