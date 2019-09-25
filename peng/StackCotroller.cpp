#include "StackController.h"

StackController::~StackController() {
	delete *_view;
	delete* _s;
	delete* _ideal;
}

void StackController::SetView(StackView* view) {
	_view = view;
}

void StackController::AddPenguin(std::string& peng) {
	_s->Push(peng);
	_view->AddPenguin(peng);
}

void StackController::DeletePenguin() {
	_s->Pop();
	_view->DeletePenguin();
}

bool StackController::CompareStacks() {
	return (_s *) == (*_ideal);
}