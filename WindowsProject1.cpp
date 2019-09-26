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

Stack s1;
Stack s2;
StackView view;
StackController controller;

// Обработчик сообщений для окна.
INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	view.SetDlg(hDlg);
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	//Sanya, Narodok, Miha, Shnek, Petr, Serge, Svyat, Vlad, Leha
	case WM_INITDIALOG:
		s2.Push("Sanya");
		s2.Push("Narodok");
		s2.Push("Miha");
		s2.Push("Shnek");
		s2.Push("Petr");
		s2.Push("Serge");
		s2.Push("Svyat");
		s2.Push("Vlad");
		s2.Push("Leha");
		controller.SetView(&view);
		controller.SetStack(&s1);
		controller.SetCompareStack(&s2);
		view.SetController(&controller);
		return (INT_PTR)TRUE;
		break;

	case WM_COMMAND:
		view.HandleEvent(wParam);
		break;
	}
	return (INT_PTR)FALSE;
}
