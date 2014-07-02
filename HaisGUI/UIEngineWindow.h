#pragma  once
#include "pch.h"
//#include "Button.h"
//#include "Panel.h"
#include "UIDrawer.h"
#include "WindowAnimation.h"
//#include "RealWindow.h"
class HGUI_API UIEngineWindow
{
public:
	void PreCreate();
	HWND GetHWND();
	bool Create(wchar_t* title = L"DefaultWindow", wchar_t* Class = L"HaisGUIClass");

	void Destory();

	void SetDrawer(UIDrawer* drawer);
	//////////////////////////////////////////////////////////////////////////
	void Maximized();
	void Minimized();
	void Normalimized();
	void Resize(int x,int y ,int w,int h);
	//////////////////////////////////////////////////////////////////////////
	void OnPaint();
	//class cmp
	//{
	//public:
	//	bool operator () (const Panel* a, const Panel* b) { return b->index > a->index; }
	//};
	//bool AddPanel(Panel* pn)
	//{
	//	for each (auto var in _panels)
	//	{
	//		if (var->name == pn->name)
	//			return false;
	//	};
	//	_panels.push_back(pn);
	//	_panels.sort(cmp());
	//	pn->BindTarget(m_pRenderTarget);
	//	
	//}
//	bool AddRealWindow(RealWindow* rw)
	//{
	//	//rw = new RealWindow();
	//	//rw->Create(hWnd);
	//	for each (auto var in _panels)
	//	{
	//		if (var->name == rw->name)
	//			return false;
	//	};
	//	_rwlist.push_back(rw);
	//	//_panels.sort(cmp());
	//	//rw->BindTarget(m_pRenderTarget);
	//	return true;
	//}
//	void SetPanelIndex(Panel* pn,int idx)
	//{
	//	pn->index = idx;
	//	_panels.sort(cmp());
	//}
	void SetBgColor();//color
	void SetBgBitmap();//BitMap  alpha/color key color key
	//////////////////////////////////////////////////////////////////////////
	LRESULT OnProc(UINT msg, WPARAM wParam, LPARAM lParam);
protected:
	UIDrawer* dr=nullptr;
//	std::list<Panel*> _panels;
	ID2D1DCRenderTarget* m_pRenderTarget = nullptr;
	HINSTANCE hInstance = GetModuleHandle(0);
	DWORD wndstyle = WS_OVERLAPPEDWINDOW;/*WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN;*/
	HWND hWnd = 0;
	MSG msg;
	WNDCLASSEX wcex;
	BLENDFUNCTION pb_;
	HDC dc;// = GetDC(hWnd);
	//////////////////////////////////////////////////////////////////////////
	//TEST
//	std::list<RealWindow*> _rwlist;

};