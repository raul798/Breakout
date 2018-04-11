#pragma once
#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <string>
#include <vector>

#include "IUpdate.hpp"
#include "IRender.hpp"
#include "../BoilerPlate/engine/math/Matrix_4.hpp"
#include "unique_id.hpp"
#include "component.hpp"


namespace engine
{
	namespace core
	{
		class component;
		class game_object : public IUpdate, public IRender, public unique_id
		{
		public:
			//constructors
			game_object();
			~game_object();

			//public functions
			void attach_component(component *pComponent);
			void remove_component(component *pComponent);
			void add_child(game_object *pGame_object);
			void remove_child(game_object *pGame_object);
			void update(double pDeltaTime) override;
			void render() override;

			//getters
			std::vector<game_object*> get_children() const { return mChildren; }
			game_object* get_parent() const { return mParent; }
			math::matrix_4 get_model_matrix();
			component *get_component(std::string pComponentName);

		protected:
			//members
			std::vector<component*>	mComponents;
			std::vector<game_object*> mChildren;
			game_object *mParent;
			math::matrix_4 mModel;
		};
	}
}

#endif
