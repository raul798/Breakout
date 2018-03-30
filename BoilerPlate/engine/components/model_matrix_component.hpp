#pragma once
#ifndef MODEL_MATRIX_COMPONENT_HPP
#define MODEL_MATRIX_COMPONENT_HPP

#include "../core/component.hpp"
#include "../math/matrix_4.hpp"

namespace engine
{
	namespace component
	{
		class model_matrix_component : core::component
		{
			math::matrix_4 mModelMatrix;
		};
	}
}

#endif