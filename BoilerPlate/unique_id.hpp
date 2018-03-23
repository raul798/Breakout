#pragma once
#ifndef _UNIQUEID_HPP_
#define _UNIQUEID_HPP_

namespace engine
{
	namespace core
	{
		class unique_id
		{
		public:
			//constructors
			unique_id();
			unique_id(const unique_id &pOrig);

			//operators
			unique_id& operator=(const unique_id &pOrig);

			//members
			int mId;

		protected:
			static int mNextID;
		};

	}
}

#endif