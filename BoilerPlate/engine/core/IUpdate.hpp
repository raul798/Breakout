#pragma once
#ifndef _IUPDATE_HPP_
#define _IUPDATE_HPP_

namespace engine
{
	namespace core
	{
		class IUpdate
		{
		public:
			IUpdate() : mUpdates(0) {}
			virtual ~IUpdate() = default;

			//public functions
			void virtual update(double pDeltaTime) { mUpdates++; };
		protected:
			//members
			int	mUpdates;
		};
	}
}

#endif 