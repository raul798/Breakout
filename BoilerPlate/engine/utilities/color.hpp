#pragma once
#ifndef COLOR_HPP
#define COLOR_HPP

#include "../BoilerPlate//engine/math/vector_4.hpp"

namespace engine
{
	namespace utilities
	{
		struct color
		{
			engine::math::vector_4 WHITE = engine::math::vector_4(1.0f, 1.0f, 1.0f, 1.0f);
			engine::math::vector_4 BLUE = engine::math::vector_4(0.2f, 0.6f, 1.0f, 1.0f);
			engine::math::vector_4 GREEN = engine::math::vector_4(0.0f, 0.7f, 0.0f, 1.0f);
			engine::math::vector_4 YELLOW = engine::math::vector_4(0.8f, 0.8f, 0.4f, 1.0f);
			engine::math::vector_4 ORANGE = engine::math::vector_4(1.0f, 0.5f, 0.0f, 1.0f);
			engine::math::vector_4 GREY = engine::math::vector_4(0.8f, 0.8f, 0.7f, 1.0f);
		};
	}
}

#endif
