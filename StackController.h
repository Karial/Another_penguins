#pragma once

#include "WindowsProject1.h"
#include "AbstractController.h"
#include "Stack.h"
#include "StackView.h"

class StackController : public AbstractController {
public:
	StackController();
	void SetView(StackView* view);
	void SetStack(Stack* s);
	void SetCompareStack(Stack* ideal);

	void AddPenguin(std::string& peng) override;
	void DeletePenguin() override;
	void CompareStacks() override;
	void Size() override;
	void ResetIterator() override;
	virtual void Next() override;
	virtual void Prev() override;
private:
	StackView* _view;
	Stack* _s;
	StackIterator* _it;
	Stack* _ideal;
};