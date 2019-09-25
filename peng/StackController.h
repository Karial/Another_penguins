#pragma once

#include "AbstractController.h"
#include "Stack.h"
#include "StackController.cpp"

class StackController : public AbstractController {
	~StackController();
	void SetView(StackView* view) overload;
	
	void AddPenguin(std::string& peng) overload;
	void DeletePenguin() overload;
	bool CompareStacks() overload;

	StackView* _view;
	Stack* _s;
	Stack* _ideal;
};