#pragma once
#ifndef ERROR_MANAGER_HPP
#define ERROR_MANAGER_HPP

#include <iostream>
#include <Windows.h>

struct error_manager
{
	int display_error_message_box(std::string pFileName, std::string pFileLine, std::string pErrorMessage, std::string pRawErrorMessage);
};

#endif