#pragma once
#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>
#include <vector>

#include "IUpdate.hpp"
#include "../core/vertex.hpp"
#include "../math/matrix_4.hpp"

namespace engine
{
	namespace core
	{
		class game_object;
		class component : IUpdate
		{
		public:
			//public functions
			explicit component();
			explicit component(const std::string& pName);
			~component();
			void update(double pDeltaTime) override;

			//getters and setters
			void set_owner(game_object* pOwner) { mOwner = pOwner; }
			game_object* get_owner() const { return mOwner; }
			std::string get_name() const { return mName; }

			//virtual funtions
			virtual math::matrix_4* get_model_matrix() { return NULL; }
			virtual std::vector<vertex> get_vertex() { std::vector<vertex> emptyVertexVector; return emptyVertexVector; }
			virtual std::vector<int> get_indices() { std::vector<int> emptyIndexVector; return emptyIndexVector; }
			virtual std::string get_texture_path() { return NULL; }
			virtual math::vector_4* get_position() { return NULL; }
			virtual float *get_movement_value() { return NULL; }
			virtual float *get_angle() { return NULL; }

		protected:
			//members
			game_object *mOwner;
			std::string	mName;
		};
	}
}

#endif 