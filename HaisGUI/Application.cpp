#include "Application.h"
#include "resource.h"
Application::Application()
{
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;// MAKEINTRESOURCE(IDR_MENU1);
	wcex.lpszClassName = Class;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));

	RegisterClassEx(&wcex);
	_uiengine = new UIEngine(Class, hInstance);

};
Application::~Application()
{
	UnregisterClass(Class, hInstance);
}
Application* Application::Get()
{
	static Application _instance;
	return &_instance;
}
UIEngine* Application::GetUIEngine(){ return _uiengine; };
int Application::Run()
{
	while (true)
	{
		PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
		if (msg.message == WM_QUIT)
			break;
		//while (GetMessage(&msg, NULL, 0, 0))
		//{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		Sleep(20);
		WindowAnimation::Get()->Step(0.02f);
	}
	return msg.wParam;
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	UIEngine* uie = Application::Get()->GetUIEngine();
	UIEngineWindow* thewnd = reinterpret_cast<UIEngineWindow*>(uie->GetWindowByHandle(hWnd));
	if (thewnd != nullptr)
	{
		return thewnd->OnProc(msg, wParam, lParam);
	}
	switch (msg)
	{
		//case WM_CREATE:
		//	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

}