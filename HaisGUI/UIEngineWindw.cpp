#include "UIEngineWindow.h"


void UIEngineWindow::PreCreate(){}
HWND UIEngineWindow::GetHWND(){ return hWnd; };
bool UIEngineWindow::Create(wchar_t* title, wchar_t* Class)
{
	pb_.AlphaFormat = 1;
	pb_.BlendOp = AC_SRC_OVER;
	pb_.BlendFlags = 0;
	pb_.SourceConstantAlpha = 0xFF;

	hWnd = CreateWindowEx(WS_EX_LAYERED/* | WS_EX_NOACTIVATE*//*|WS_EX_TOPMOST*/,
		Class,
		title,
		wndstyle,
		200,
		100,
		800 + GetSystemMetrics(SM_CXFIXEDFRAME) * 2,
		600 + GetSystemMetrics(SM_CXFIXEDFRAME) * 2 + GetSystemMetrics(SM_CYMENU) + GetSystemMetrics(SM_CYCAPTION),
		NULL,
		NULL,
		hInstance,
		NULL
		);
	SetLayeredWindowAttributes(hWnd, RGB(255, 255, 255), 255, LWA_ALPHA);
	//SetLayeredWindowAttributes(hWnd, RGB(255,255,255), 0, LWA_COLORKEY);
	//UpdateLayeredWindow(hWnd, dc, NULL, NULL, hMemDC, NULL, RGB(255, 0, 255), &pb_, ULW_COLORKEY);
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	SetTimer(hWnd, 1, 30, NULL);
	PostMessage(hWnd, WM_PAINT, 0, 0);

	//TEST
	//Animation* ani = new Animation();
	//ani->type = WAnimationType::FadeOut;
	//ani->time = 2;
	//ani->hwnd = hWnd;
	//WindowAnimation::Get()->Create(L"sss", ani);
	//WindowAnimation::Get()->Start(L"sss");
	//Animation* ani1 = new Animation();
	//ani1->type = WAnimationType::FadeIn;
	//ani1->time = 2;
	//ani1->opt = 0;
	//ani1->hwnd = hWnd;
	//WindowAnimation::Get()->Create(L"ttt", ani1);

	//HWND hWndProgram = NULL;
	//HWND hWndShellDLL = NULL;
	//hWndProgram = FindWindow(L"Progman", L"Program Manager");
	//if (hWndProgram != NULL)
	//{
	//	hWndShellDLL = FindWindowEx(hWndProgram, NULL, L"SHELLDLL_DefView", NULL);
	//}

	//if (hWndShellDLL != NULL)
	//{
	//	SetWindowLong(hWnd, GWL_HWNDPARENT, (LONG)hWndShellDLL);
	//}
	//SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 0, 0,
	//	SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
	//WindowAnimation::Get()->Start(L"ttt");
	if (hWnd != 0)
	{
		return true;
	}
	return false;
}
void UIEngineWindow::Destory()
{

}
void UIEngineWindow::SetDrawer(UIDrawer* drawer)
{
	dr = drawer;
	RECT rc;
	GetClientRect(hWnd, &rc);
	dc = GetDC(hWnd);
	//HDC hMemDC = CreateCompatibleDC(dc);
	D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);
	//HRESULT hr = dr->pd2dfactory->CreateHwndRenderTarget(
	//	D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT, D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED)),
	//	D2D1::HwndRenderTargetProperties(hWnd, size),
	//	&m_pRenderTarget);
	D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
		D2D1_RENDER_TARGET_TYPE_DEFAULT,
		D2D1::PixelFormat(
		DXGI_FORMAT_B8G8R8A8_UNORM,
		D2D1_ALPHA_MODE_PREMULTIPLIED),
		0,
		0,
		D2D1_RENDER_TARGET_USAGE_NONE,
		D2D1_FEATURE_LEVEL_DEFAULT
		);
	//hBitMap = ::CreateCompatibleBitmap(dc, rc.right - rc.left, rc.bottom - rc.top);//创建兼容位图 
	HRESULT hr = dr->pd2dfactory->CreateDCRenderTarget(&props, &m_pRenderTarget);
	/*HDC dc = GetDC(hWnd);*/
	// Bind the DC to the DC render target.
	hr = m_pRenderTarget->BindDC(dc, &rc);
}
//////////////////////////////////////////////////////////////////////////
void UIEngineWindow::Maximized()
{

	PostMessage(hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
}
void UIEngineWindow::Minimized()
{
	PostMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
void UIEngineWindow::Normalimized()
{

	PostMessage(hWnd, WM_SYSCOMMAND, SC_RESTORE, 0);
}
void UIEngineWindow::Resize(int x,int y,int w, int h)
{
	MoveWindow(hWnd, x, y, w + GetSystemMetrics(SM_CXFIXEDFRAME) * 2, h + GetSystemMetrics(SM_CXFIXEDFRAME) * 2 + GetSystemMetrics(SM_CYMENU) + GetSystemMetrics(SM_CYCAPTION),true);
}
//////////////////////////////////////////////////////////////////////////
void UIEngineWindow::OnPaint()
{


	m_pRenderTarget->BeginDraw();

	m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Magenta, 0.f));

	//for each (auto var in _panels)
	//{
	//	var->Draw(dr);
	//}

	m_pRenderTarget->EndDraw();
	//	for each (auto var in _rwlist)
	//{
	//	var->Draw();
	//}
}

void UIEngineWindow::SetBgColor()
{

}
void UIEngineWindow::SetBgBitmap()
{

}
//////////////////////////////////////////////////////////////////////////
LRESULT UIEngineWindow::OnProc(UINT msg, WPARAM wParam, LPARAM lParam)
{
	POINT pos;
	//std::list<Panel*>::reverse_iterator iter;
	//Panel* temp;
	RECT rtClient;

	GetClientRect(hWnd, &rtClient);
	POINT ptSrc = { 0, 0 };
	POINT ptPos = { rtClient.left, rtClient.top };
	SIZE szSize = { rtClient.right - rtClient.left, rtClient.bottom - rtClient.top };
	BLENDFUNCTION   blend = { AC_SRC_OVER, 0, 250, AC_SRC_ALPHA };
	bool bt;
	switch (msg)
	{
	case WM_SIZE:
	{
		if (m_pRenderTarget)
		{

		D2D1_SIZE_U size;
		size.width = LOWORD(lParam);
		size.height = HIWORD(lParam);
		//m_pRenderTarget->Resize(size);
		}
	}

	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			//InvalidateRect(hWnd, &rtClient, true);
			//PostMessage(hWnd, WM_PAINT, 0, 0);
			//RECT rtClient;
			//GetClientRect(hWnd, &rtClient);

			//HDC hDC = GetDC(hWnd);
			//HDC hMemDC = CreateCompatibleDC(hDC);
			//HBITMAP hOldBmp = (HBITMAP)SelectObject(hMemDC, hBitmap);

			//POINT ptSrc = { 0, 0 };
			//POINT ptPos = { rtClient.left, rtClient.top };
			//SIZE szSize = { rtClient.right - rtClient.left, rtClient.bottom - rtClient.top };
			//BLENDFUNCTION   blend = { AC_SRC_OVER, 0, 250, AC_SRC_ALPHA };
			//UpdateLayeredWindow(hWnd, hDC, &ptPos, &szSize, hMemDC, &ptSrc, RGB(255, 0, 0), &blend, ULW_ALPHA | ULW_COLORKEY);
			//if (WindowAnimation::Get()->GetStatus(L"sss") == 2)
			//{
			//	WindowAnimation::Get()->Stop(L"sss");
			//	WindowAnimation::Get()->Start(L"ttt");
			//	Normalimized();
			//}
			//if (WindowAnimation::Get()->GetStatus(L"ttt") == 2)
			//	PostQuitMessage(0);
			break;
		}
		break;
	case WM_MOVE:
	case WM_DISPLAYCHANGE:
	case  WM_PAINT:
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);



  
		//hOldMap = (HBITMAP)::SelectObject(hMemDC, hBitMap);//将位图选入DC，并保存返回值  
		OnPaint();
		//DrawText(hMemDC, L"你好啊搜搜索算法f", 20, &rtClient, DT_LEFT);
		
		//::BitBlt(hDCMem, 0, 0, rtClient.right - rtClient.left, rtClient.bottom - rtClient.top, dc, 0, 0, SRCCOPY);//将屏幕DC的图象复制到内存DC中   

		
		//image.Attach(hBitMap);
		//image.Save(_T("c://B.jpg"));//如果文件后缀为.bmp，则保存为为bmp格式  
		//image.Detach();
		//::BitBlt(dc, 0, 0, rtClient.right - rtClient.left, rtClient.bottom - rtClient.top, hMemDC, 0, 0, SRCCOPY);//将屏幕DC的图象复制到内存DC中   
		//::SelectObject(hMemDC, hOldMap);//选入上次的返回值 
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		PostMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, lParam);
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_LBUTTONDBLCLK:
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
	case WM_MOUSEHOVER:
	case WM_MOUSELEAVE:
	case WM_MOUSEMOVE:
		GetCursorPos(&pos);
		ScreenToClient(hWnd, &pos);
		//for (iter = _panels.rbegin(); iter != _panels.rend();)
		//{
		//	temp = *iter;
		//	if ((temp->_rect._x <= pos.x) && (temp->_rect._y <= pos.y) &&
		//		(temp->_rect._x + temp->_rect._w >= pos.x) && (temp->_rect._y + temp->_rect._h >= pos.y))
		//	{
		//		return temp->OnProc(msg, wParam, lParam);
		//	}
		//	iter++;
		//}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}