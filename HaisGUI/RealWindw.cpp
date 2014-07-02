#include "RealWindow.h"
const UINT WM_GRAPH_EVENT = WM_APP + 1;
bool RealWindow::Create(HWND parent, wchar_t* title, wchar_t* Class)
{
	hWnd = CreateWindowEx(0/*WS_EX_LAYERED*//* | WS_EX_NOACTIVATE*//*|WS_EX_TOPMOST*/,
		Class,
		title,
		WS_CHILD | WS_VISIBLE,
		200,
		100,
		300,
		200,
		parent,
		NULL,
		GetModuleHandle(0),
		NULL
		);
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	HRESULT hr;
	m_pPlayer = new DShowPlayer(hWnd);
	hr = m_pPlayer->SetEventWindow(hWnd, WM_GRAPH_EVENT);
	hr = m_pPlayer->OpenFile(L"C:\\Users\\Public\\Videos\\Sample Videos\\Ò°Éú¶¯Îï.wmv");
	RECT rcWindow;
	RECT rcControl;

	// Find the client area of the application.
	GetClientRect(hWnd, &rcWindow);
	m_pPlayer->UpdateVideoWindow(&rcWindow);
	hr = m_pPlayer->Play();
	return true;
}