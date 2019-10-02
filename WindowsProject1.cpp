// peng.cpp : Определяет точку входа для приложения.


#include "stdafx.h"
#include "WindowsProject1.h"
#include "Stack.h"
#include <stdio.h>
#include <string>
#include "StackView.h"
#include "StackController.h"

INT_PTR CALLBACK Controller(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Controller);
}

/*Stack s1;
Stack s2;
StackView view;
StackController controller;*/

// Обработчик сообщений для окна.
INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static StackView view;
	static StackController controller;
	view.SetDlg(hDlg);
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	//Sanya, Narodok, Miha, Shnek, Petr, Serge, Svyat, Vlad, Leha
	case WM_INITDIALOG:
		view.SetController(&controller);
		controller.SetView(&view);
		return (INT_PTR)TRUE;
		break;

	case WM_COMMAND:
		view.HandleEvent(wParam);
		break;
	}
	return (INT_PTR)FALSE;
}
