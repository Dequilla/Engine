#include "Event.hpp"

namespace eng {
	namespace system {
		bool Event::poll(Event& event)
		{
			return SDL_PollEvent(&event.base);
		}
	}
}