#pragma once
#include "pch.h"
#include "UIDrawer.h"
class HGUI_API Rect
{
public:
	Rect() = default;
	Rect(int x, int y, int w, int h)
	{
		_x = x; _y = y; _w = w; _h = h;
	}
	int _x = 0;
	int _y = 0;
	int _w = 0;
	int _h = 0;

};
class HGUI_API Controls
{
public:
	Controls() = default;
	Controls(Rect rect)
	{
		_rect = rect;
	}
	virtual void MoveTo(Rect rect);

	virtual void Draw(POINT offset, UIDrawer* dr);

	void BindTarget(ID2D1DCRenderTarget* tg);

	void SetText(wchar_t* tex);
protected:
	ID2D1DCRenderTarget* m_pRenderTarget = nullptr;
	Rect _rect;
	wchar_t* text = L"Control";
};