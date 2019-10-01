#include "stdafx.h"
#include "StackView.h"

void StackView::SetDlg(HWND hDlg) {
	_hDlg = hDlg;
}

void StackView::SetController(AbstractController* controller) {
	_controller = controller;
}

AbstractController* StackView::GetController() {
	return _controller;
}

HWND StackView::GetDlg() {
	return _hDlg;
}

void StackView::AddPenguin(std::string& name) {
	char buf[100];
	strcpy_s(buf, name.c_str());
	SendDlgItemMessage(_hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)buf);
}


void StackView::DeletePenguin(int ind) {
	SendDlgItemMessage(_hDlg, IDC_LIST1, LB_DELETESTRING, ind, 0);
}

void StackView::CompareStacks(bool are_equal) {
	char buf[100];
	if (are_equal) {
		strcpy_s(buf, "Perfect");
	}
	else {
		strcpy_s(buf, "Bullshit");
	}
	SetDlgItemText(_hDlg, IDC_EQUAL_EDIT, buf);
}

void StackView::ShowSize(int size) {
	char buf[100];
	_itoa_s(size, buf,100, 10);
	SetDlgItemText(_hDlg, IDC_EDIT_SIZE, buf);
}

bool StackView::HandleEvent(WPARAM wParam) {
	if (LOWORD(wParam) == IDC_PUSH) {
		_controller->ResetIterator();
		char buf[100];
		GetDlgItemText(_hDlg, IDC_PUSH_INPUT, buf, 100);
		SetWindowText(GetDlgItem(_hDlg, IDC_PUSH_INPUT), "");
		std::string peng = std::string(buf);
		_controller->AddPenguin(peng);
		_controller->ResetIterator();
	}
	if (LOWORD(wParam) == IDC_POP) {
		_controller->DeletePenguin();
		_controller->ResetIterator();
	}
	if (LOWORD(wParam) == IDC_EQUAL) {
		_controller->CompareStacks();
	}
	if (LOWORD(wParam) == IDC_BUTTON_SIZE) {
		_controller->Size();
	}
	if (LOWORD(wParam) == IDC_NEXT) {
		_controller->Next();
	}
	if (LOWORD(wParam) == IDC_PREV) {
		_controller->Prev();
	}
	if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
	{
		EndDialog(_hDlg, LOWORD(wParam));
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}

void StackView::ResetIterator() {
	SetWindowText(GetDlgItem(_hDlg, IDC_ITERATOR), "");
}

void StackView::ChangeIteratorEdit(const std::string& str) const {
	char buf[100];
	strcpy_s(buf, str.c_str());
	SetWindowText(GetDlgItem(_hDlg, IDC_ITERATOR), (LPCSTR)buf);
}