#pragma once

#include "WindowsProject1.h"
#include "AbstractView.h"
#include "AbstractController.h"
#include "string"

class StackView : public AbstractView {
public:
	StackView() {
		_hDlg = nullptr;
	};

	void SetDlg(HWND hDlg);
	void SetController(AbstractController* controller);
	HWND GetDlg();
	void AddPenguin(std::string& name) override;
	void DeletePenguin(int ind) override;
	void CompareStacks(bool are_equal) override;
	bool HandleEvent(WPARAM wParam) override;

private:
	HWND _hDlg;
	AbstractController* _controller;
};
