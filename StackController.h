#pragma once

#include "WindowsProject1.h"
#include "AbstractController.h"
#include "Stack.h"
#include "StackView.h"

class StackController : public AbstractController {
public:
	StackController() = default;
	void SetView(StackView* view);
	void SetStack(Stack* s);
	void SetCompareStack(Stack* ideal);

	void AddPenguin() override;
	void DeletePenguin() override;
	void CompareStacks() override;
private:
	StackView* _view;
	Stack* _s;
	Stack* _ideal;
};