#include "error_manager.hpp"

namespace engine
{
	namespace utilities
	{
		int error_manager::display_error_message_box(std::string pFileName, std::string pFileLine, std::string pErrorMessage, std::string pRawErrorMessage)
		{
			std::string complete_message = "File name: " + pFileName + "\nFile Line: " + pFileLine + "\n" + pErrorMessage
				+ "\nUsing OpenGL 3.30 and GLSL 330 core";

			LPCSTR display_message = complete_message.c_str();

			#ifdef _WIN32

			int msgboxID = MessageBoxA(NULL, display_message, pRawErrorMessage.c_str(), MB_ICONWARNING | MB_OK);

			#elif defined _unix_ || defined APPLE

			std::cerr << complete_message;

			#endif

			return msgboxID;
		}
	}
}