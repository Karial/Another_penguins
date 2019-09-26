#include "stdafx.h"
#include "StackView.h"

void StackView::SetDlg(HWND hDlg) {
	_hDlg = hDlg;
}

void StackView::SetController(AbstractController* controller) {
	_controller = controller;
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

bool StackView::HandleEvent(WPARAM wParam) {
	if (LOWORD(wParam) == IDC_PUSH) {
		_controller->AddPenguin();
	}
	if (LOWORD(wParam) == IDC_POP) {
		_controller->DeletePenguin();
	}
	if (LOWORD(wParam) == IDC_EQUAL) {
		_controller->CompareStacks();
	}
	if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
	{
		EndDialog(_hDlg, LOWORD(wParam));
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}