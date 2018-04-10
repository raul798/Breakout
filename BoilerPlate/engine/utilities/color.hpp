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
			engine::math::vector_4 YELLOW = engine::math::vector_4(0.9372f, 0.9058f, 0.0f, 1.0f);
			engine::math::vector_4 ORANGE = engine::math::vector_4(1.0f, 0.4784f, 0.0156f, 1.0f);
			engine::math::vector_4 GREY = engine::math::vector_4(0.8f, 0.8f, 0.7f, 1.0f);

			engine::math::vector_4 PURPLE = engine::math::vector_4(0.4745f, 0.0509f, 0.7254f, 1.0f);
			engine::math::vector_4 PINK = engine::math::vector_4(0.9607f, 0.2156f, 0.5529f, 1.0f);
		};
	}
}

#endif
