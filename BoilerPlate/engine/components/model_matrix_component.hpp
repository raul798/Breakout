#pragma once
#ifndef MODEL_MATRIX_COMPONENT_HPP
#define MODEL_MATRIX_COMPONENT_HPP

#include "../core/component.hpp"


namespace engine
{
	namespace component
	{
		class model_matrix_component : public core::component
		{
		public:
			explicit model_matrix_component(const std::string& pName);
			math::matrix_4 get_model_matrix();
		private:
			math::matrix_4 mModelMatrix;
		};
	}
}

#endif