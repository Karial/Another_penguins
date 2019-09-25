// peng.cpp : Определяет точку входа для приложения.


#include "stdafx.h"
#include "peng.h"
#include "Stack.h"
#include <stdio.h>
#include <string>
#include "View.h"

INT_PTR CALLBACK Controller(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Controller);
}

// Обработчик сообщений для окна.
INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Stack s1;
	static Stack s2;
	static View view(hDlg, &s1, IDC_LIST1);
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
        return (INT_PTR)TRUE;

    case WM_COMMAND:
		if (LOWORD(wParam) == IDC_PUSH) {
			char buf[100];
			GetDlgItemText(hDlg, IDC_PUSH_INPUT, buf, 100);
			SetWindowText(GetDlgItem(hDlg, IDC_PUSH_INPUT), "");
			s1.Push(std::string(buf));
			view.Update();
		}
		if (LOWORD(wParam) == IDC_POP) {
			s1.Pop();
			view.Update();
		}
		if (LOWORD(wParam) == IDC_EQUAL) {
			char buf[100];
			if (s1 == s2) {
				strcpy_s(buf, "Perfect");
			}
			else {
				strcpy_s(buf, "Bullshit");
			}
			SetDlgItemText(hDlg, IDC_EQUAL_EDIT, buf);
		}
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
