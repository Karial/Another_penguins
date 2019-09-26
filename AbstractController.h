#pragma once

#include "string"
#include "AbstractView.h"

class AbstractController {
public:
	virtual ~AbstractController() = default;
//	virtual void SetView(AbstractView* view) = 0;

	virtual void AddPenguin() = 0;
	virtual void DeletePenguin() = 0;
	virtual void CompareStacks() = 0;
};
