#pragma once

#include "WindowsProject1.h"
#include "AbstractView.h"
#include "AbstractController.h"
#include "string"

class StackView : public AbstractView {
public:
	StackView() = default;

	void SetDlg(HWND hDlg);
	void SetController(AbstractController* controller);
	AbstractController* GetController();
	HWND GetDlg();
	void AddPenguin(std::string& name) override;
	void DeletePenguin(int ind) override;
	void CompareStacks(bool are_equal) override;
	void ShowSize(int size) override;
	bool HandleEvent(WPARAM wParam) override;
	void ResetIterator();
	void ChangeIteratorEdit(const std::string& str) const;

private:
	HWND _hDlg;
	AbstractController* _controller;
};
