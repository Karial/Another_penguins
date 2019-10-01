#include "stdafx.h"
#include "StackController.h"

StackController::StackController() {
	_s = new Stack();
	_ideal = new Stack();
	_ideal->Push("Sanya");
	_ideal->Push("Narodok");
	_ideal->Push("Miha");
	_ideal->Push("Shnek");
	_ideal->Push("Petr");
	_ideal->Push("Serge");
	_ideal->Push("Svyat");
	_ideal->Push("Vlad");
	_ideal->Push("Leha");
	_it = new StackIterator(*_s, -1);
}

void StackController::SetView(StackView* view) {
	_view = view;
}

void StackController::SetStack(Stack* s) {
	_s = s;
}

void StackController::SetCompareStack(Stack* ideal) {
	_ideal = ideal;
}

void StackController::AddPenguin(std::string& peng) {
	_s->Push(peng);
	_view->AddPenguin(peng);
}

void StackController::DeletePenguin() {
	_s->Pop();
	_view->DeletePenguin(_s->Size());
}

void StackController::CompareStacks() {
	_view->CompareStacks((*_s) == (*_ideal));
}

void StackController::Size() {
	_view->ShowSize(_s->Size());
}

void StackController::ResetIterator() {
	_it->Copy(_s->begin());
	if (_it->IsValid()) {
		_view->ChangeIteratorEdit(_it->Val());
	}
	else {
		_view->ResetIterator();
	}
}

void StackController::Next() {
	if (_it->HasNext()) {
		_it->Next();
		_view->ChangeIteratorEdit(_it->Val());
	}
}

void StackController::Prev() {
	if (_it->HasPrev()) {
		_it->Prev();
		_view->ChangeIteratorEdit(_it->Val());
	}
}