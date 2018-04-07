#include "game_object.hpp"

#include <algorithm>

namespace engine
{
	namespace core
	{
		game_object::game_object()
		{
			mParent = nullptr;
			mModel = math::matrix_4();
		}

		game_object::~game_object()
		{
			//delete all attached components
			//while (!mComponents.empty())
			//{
			//	delete mComponents[mComponents.size() - 1];
			//	mComponents.pop_back();
			//}

			//delete all attached children
			while (!mChildren.empty())
			{
				delete mChildren.back(), mChildren.pop_back();
			}
		}

		void game_object::attach_component(component *pComponent)
		{
			pComponent->set_owner(this);
			mComponents.push_back(pComponent);
		}

		void game_object::remove_component(component *pComponent)
		{
			mComponents.erase(remove(mComponents.begin(), mComponents.end(), pComponent), mComponents.end());

			delete pComponent;
		}

		void game_object::add_child(game_object* pChild)
		{
			//set the child parent
			pChild->mParent = this;

			mChildren.push_back(pChild);
		}

		void game_object::remove_child(game_object* pChild)
		{
			mChildren.erase(remove(mChildren.begin(), mChildren.end(), pChild), mChildren.end());

			delete pChild;
		}

		void game_object::update(double pDeltaTime)
		{
			//update components
			std::vector< component* >::iterator comp = mComponents.begin();

			for (; comp != mComponents.end(); ++comp)
			{
				(*comp)->update(pDeltaTime);
			}

			//update children
			std::vector< game_object* >::iterator child = mChildren.begin();

			for (; child != mChildren.end(); ++child)
			{
				(*child)->update(pDeltaTime);
			}

			//base class function call
			IUpdate::update(pDeltaTime);
		}
		math::matrix_4 game_object::get_model_matrix()
		{
			return mModel;
		}
		void game_object::render()
		{
			//if ((m_nUpdates % 60) == 0)
			{
				//render children
				std::vector< game_object* >::iterator child = mChildren.begin();

				for (; child != mChildren.end(); ++child)
				{
					(*child)->render();
				}
			}
		}

		component *game_object::get_component(std::string pComponentName)
		{
			for (int i = 0; i < mComponents.size(); i++)
			{
				if (mComponents[i]->get_name() == pComponentName)
				{
					return mComponents[i];
				}
			}

			return NULL;
		}

	}
}