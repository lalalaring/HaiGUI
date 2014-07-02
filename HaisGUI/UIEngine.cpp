#include "UIEngine.h"
UIEngine::UIEngine(wchar_t* classname, HINSTANCE inst)
{
	_class = classname;
	hInstance = inst;
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&dr.pd2dfactory
		);

	if (SUCCEEDED(hr))
	{
		hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&dr.m_pWriteFactory)
			);
	}

	if (SUCCEEDED(hr))
	{
		hr = dr.m_pWriteFactory->CreateTextFormat(
			L"Î¢ÈíÑÅºÚ",
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			60.f,
			L"en-us",
			&dr.m_pWriteTextFormat
			);
	}
}
void UIEngine::CreateButton(UIEngineWindow* wnd, int id)
{
	//wnd->CreateButton(id);
}
bool UIEngine::AttachWindow(UIEngineWindow* wnd)
{
	HWND hWnd = wnd->GetHWND();
	if (hWnd != nullptr)
	{
		for each (auto var in _windowmap)
		{
			if (var.first == hWnd)
				return false;
		};
		wnd->SetDrawer(&dr);
		_windowmap.insert(std::pair<HWND, UIEngineWindow*>(hWnd, wnd));
		return true;
	}
	return false;

}
bool UIEngine::DestachWind()
{
	return false;
}
UIDrawer UIEngine::GetUIDrawer(){ return dr; }
UIEngineWindow* UIEngine::GetWindowByHandle(HWND hWnd)
{
	for each (auto wd in _windowmap)
	{
		if (wd.first == hWnd)
			return wd.second;
	}
	return nullptr;
}