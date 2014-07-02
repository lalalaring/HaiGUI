#include "pch.h"
#include "UIEngineWindow.h"
#include "UIDrawer.h"
//#include "Button.h"
class HGUI_API UIEngine final
{
public:
	UIEngine() = delete;
	UIEngine(wchar_t* classname, HINSTANCE inst);
	~UIEngine(){}

	void CreateButton(UIEngineWindow* wnd, int id);

	bool AttachWindow(UIEngineWindow* wnd);
	bool DestachWind();
	UIDrawer GetUIDrawer();
	UIEngineWindow* GetWindowByHandle(HWND hWnd);

protected:
private:
	UIDrawer dr;
	std::map<HWND,UIEngineWindow*> _windowmap;
	wchar_t* _class;// = L"HaisGUIClass";
	HINSTANCE hInstance;
};