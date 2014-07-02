#pragma  once
#include "pch.h"
typedef struct UIDrawer
{
	ID2D1Factory* pd2dfactory = nullptr;
	IDWriteFactory* m_pWriteFactory = nullptr;
	IDWriteTextFormat* m_pWriteTextFormat = nullptr;
	ID2D1HwndRenderTarget* m_pRenderTarget = nullptr;
	ID2D1SolidColorBrush* m_pCornflowerBlueBrush = nullptr;
}UIDrawer;

typedef struct UIRenderTarget
{
	ID2D1HwndRenderTarget* m_pRenderTarget = nullptr;
}UIRenderTarget;