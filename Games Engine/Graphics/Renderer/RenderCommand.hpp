#pragma once
#include <vector>
#include <memory>

#include "Renderable.hpp"

namespace eng {
	namespace graphics {

		struct RenderCommand {
			std::shared_ptr<Renderable> renderable;
		};

		typedef std::vector<RenderCommand> CommandQueue;

	}
}