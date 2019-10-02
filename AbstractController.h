#pragma once

#include "string"
#include "AbstractView.h"

class AbstractController {
public:
	virtual ~AbstractController() = default;
	virtual void AddPenguin(std::string& peng) = 0;
	virtual void DeletePenguin() = 0;
	virtual void CompareStacks() = 0;
	virtual void Size() = 0;
	virtual void ResetIterator() = 0;
	virtual void Next() = 0;
	virtual void Prev() = 0;
	virtual void RandomCrowd() = 0;
	virtual void StackVisit() = 0;
	virtual void CrowdVisit() = 0;
};
