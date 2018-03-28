#pragma once
#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <vector>

//
#include "IUpdate.hpp"
#include "IRender.hpp"
#include "../BoilerPlate/engine/math/Matrix_4.hpp"
#include "unique_id.hpp"

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
			std::vector<component*>GetComponents() const { return mComponents; }
			std::vector<game_object*> GetChildren() const { return mChildren; }
			game_object* GetParent() const { return mParent; }
			math::matrix_4 get_model_matrix();

			template<typename T>
			T* GetComponent()
			{
				// If no components have been attached then return nothing
				if (mComponents.size() == 0) return nullptr;

				std::vector< component* >::iterator comp = mComponents.begin();
				for (; comp != mComponents.end(); ++comp)
				{
					T* theComponent = dynamic_cast<T*>(*comp);
					if (theComponent)
					{
						return theComponent;
					}
				}

				return nullptr;
			}

		protected:
			/* =============================================================
			* MEMBERS
			* ============================================================= */
			std::vector<component*>	mComponents;
			std::vector<game_object*> mChildren;
			game_object *mParent;
			math::matrix_4 mModel;
		};
	}
}

#endif
