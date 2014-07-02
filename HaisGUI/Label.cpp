#include "Label.h"

void Label::Draw(POINT offset, UIDrawer* dr)
{
	ID2D1SolidColorBrush * pForegroundBrush;

	m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red, 1.f), &pForegroundBrush);
	wchar_t text[] = L"Label";

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