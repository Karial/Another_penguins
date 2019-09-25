#pragma once

#include "string"
#include "AbstractView.h"

class AbstractController {
	virtual ~AbstractController() = default;
	virtual void SetView(AbstractView* view) = 0;

	virtual void AddPenguin(std::string& peng) = 0;
	virtual void DeletePenguin() = 0;
	virtual void CompareStacks() = 0;
};
