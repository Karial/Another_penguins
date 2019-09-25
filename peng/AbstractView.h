#pragma once

#include <windows.h>
#include "Stack.h"

class AbstractView {

	virtual ~AbstractView() = default;

	virtual void AddPenguin(std::string& name) = 0;
	virtual void DeletePenguin(std::string& name) = 0;
	virtual bool CompareStack() = 0;
};