#pragma once 
#include "../System/Types.hpp"
#include "../System/Assert.hpp"

#include <initializer_list>

namespace eng {
	namespace math {

		template<typename Type>
		class Vector2 {
		public:
			union {
				struct {
					Type x;
					Type y;
				};

				struct {
					Type width;
					Type height;
				};

				struct {
					Type first;
					Type second;
				};

				Type arr[2];
			};

			Vector2(Type x, Type y) 
				: x(x), y(y) {
			}

			Vector2(std::initializer_list<Type> init) {
				massert("Vector2 expects 2 elements when initialized", init.size() == 2);

				this->first = *init.begin();
				this->second = *(init.begin() + 1);
			}
		};
	}
}