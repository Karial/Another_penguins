#include "stdafx.h"
#include "StackController.h"

void StackController::SetView(StackView* view) {
	_view = view;
}

void StackController::SetStack(Stack* s) {
	_s = s;
}

void StackController::SetCompareStack(Stack* ideal) {
	_ideal = ideal;
}

void StackController::AddPenguin() {
	char buf[100];
	GetDlgItemText(_view->GetDlg(), IDC_PUSH_INPUT, buf, 100);
	SetWindowText(GetDlgItem(_view->GetDlg(), IDC_PUSH_INPUT), "");
	std::string str = std::string(buf);
	_s->Push(str);
	_view->AddPenguin(str);
}

void StackController::DeletePenguin() {
	_s->Pop();
	_view->DeletePenguin(_s->Size());
}

void StackController::CompareStacks() {
	_view->CompareStacks((*_s) == (*_ideal));
}