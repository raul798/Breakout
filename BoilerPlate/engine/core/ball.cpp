#include "ball.hpp"

namespace engine
{
	namespace core
	{
		ball::ball()
		{
			mIsAttachToPaddle = true;
		}

		bool ball::get_AttchToPaddle()
		{
			return mIsAttachToPaddle;
		}

		void ball::change_AttchToPaddle()
		{
			if (mIsAttachToPaddle == true)
			{
				mIsAttachToPaddle = false;
			}
		}
	}
}
