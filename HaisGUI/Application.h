#include "pch.h"
#include "UIEngine.h"

LRESULT HGUI_API WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
class HGUI_API Application final
{
public:
	static Application* Get();
	UIEngine* GetUIEngine();
	int Run();
protected:
private:
	Application();
	~Application();
	UIEngine* _uiengine;
	MSG msg;
	WNDCLASSEX wcex;
	DWORD wndstyle = WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN;
	HINSTANCE hInstance = GetModuleHandle(0);
	wchar_t* Class = L"HaisGUIClass";
};
