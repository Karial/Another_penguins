#pragma once

#include <windows.h>
#include "Stack.h"

class AbstractView {
public:
	virtual ~AbstractView() = default;

	virtual void AddPenguin(std::string& name) = 0;
	virtual void DeletePenguin(int ind) = 0;
	virtual void CompareStacks(bool are_equal) = 0;
	virtual bool HandleEvent(WPARAM wParam) = 0;
};