#include "Controls.h"
void Controls::MoveTo(Rect rect)
{
	_rect = rect;
}
void Controls::Draw(POINT offset, UIDrawer* dr)
{
	ID2D1SolidColorBrush * pForegroundBrush;

	m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red, 1.f), &pForegroundBrush);


	m_pRenderTarget->DrawTextW(
		text,
		wcslen(text),
		dr->m_pWriteTextFormat,
		D2D1::RectF(offset.x + _rect._x, offset.y + _rect._y, _rect._w, _rect._h),
		pForegroundBrush,
		D2D1_DRAW_TEXT_OPTIONS_CLIP,
		DWRITE_MEASURING_MODE_NATURAL);
	SafeRelease(&pForegroundBrush);
}
void Controls::BindTarget(ID2D1DCRenderTarget* tg)
{
	m_pRenderTarget = tg;
}
void Controls::SetText(wchar_t* tex)
{
	text = tex;
}