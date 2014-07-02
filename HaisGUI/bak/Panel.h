#pragma once
#include "pch.h"
#include "Label.h"
class HGUI_API Panel
{
public:
	int index = 0;
	std::wstring name = L"";
	Rect _rect;
	bool indexable = false;
	Panel() = default;
	Panel(Rect rect)
	{
		_rect = rect;
	}
	virtual void MoveTo(Rect rect)
	{
		_rect = rect;
	}

	virtual void Draw(UIDrawer* dr)
	{
		ID2D1SolidColorBrush * pForegroundBrush;

		m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue, 1.f), &pForegroundBrush);
		wchar_t text[] = L"00:00:00:00:00";

		m_pRenderTarget->DrawTextW(
			text,
			wcslen(text),
			dr->m_pWriteTextFormat,
			D2D1::RectF(_rect._x, _rect._y, _rect._w, _rect._h),
			pForegroundBrush,
			D2D1_DRAW_TEXT_OPTIONS_CLIP,
			DWRITE_MEASURING_MODE_NATURAL);
		SafeRelease(&pForegroundBrush);
		POINT offset;
		offset.x = _rect._x;
		offset.y = _rect._y;
		for each (auto var in _controls)
		{
			var.second->Draw(offset,dr);
		}
	}
	virtual bool CreateButton(int id, Rect rect = Rect(0, 0, 300, 200))
	{
		for each (auto var in _controls)
		{
			if (var.first == id)
				return false;
		};
		Button* bt = new Button(rect);
		bt->BindTarget(m_pRenderTarget);
		_controls.insert(std::pair<int, Controls*>(id, bt));
		return true;
	}
	virtual bool CreateLabel(int id, Rect rect = Rect(0, 0, 300, 200))
	{
		for each (auto var in _controls)
		{
			if (var.first == id)
				return false;
		};
		Label* bt = new Label(rect);
		bt->BindTarget(m_pRenderTarget);
		_controls.insert(std::pair<int, Controls*>(id, bt));
		return true;
	}
	virtual Controls* GetControlsByID(int id)
	{
		for each (auto var in _controls)
		{
			if (var.first == id)
				return var.second;
			

		};
		return nullptr;
	}
	virtual void BindTarget(ID2D1DCRenderTarget* tg)
	{
		m_pRenderTarget = tg;
	}
	virtual LRESULT OnProc(UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN:
		{
			//MessageBox(NULL, L"Panel1", L"sss", MB_OK);
		
		}
			break;
		return TRUE;
		}
	}
protected:
	ID2D1DCRenderTarget* m_pRenderTarget = nullptr;
	std::map<int, Controls*> _controls;
};
class HGUI_API TestPanel :public Panel
{
public:
	TestPanel() = default;
	TestPanel(Rect rect)
	{
		_rect = rect;
	}
	void Draw(UIDrawer* dr) override
	{
		ID2D1SolidColorBrush * pddoregroundBrush;

		m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White, 1.f), &pddoregroundBrush);
		wchar_t text[] = L"Panel2";

		m_pRenderTarget->DrawTextW(
			text,
			wcslen(text),
			dr->m_pWriteTextFormat,
			D2D1::RectF(_rect._x, _rect._y, _rect._w, _rect._h),
			pddoregroundBrush,
			D2D1_DRAW_TEXT_OPTIONS_NONE,
			DWRITE_MEASURING_MODE_NATURAL);
		SafeRelease(&pddoregroundBrush);
	}
	LRESULT OnProc(UINT msg, WPARAM wParam, LPARAM lParam) override
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN:
		{
			//MessageBox(NULL, L"Panel2", L"sss", MB_OK);
		}
			break;

			//default:
			//	return DefWindowProc(hWnd, msg, wParam, lParam);
			return TRUE;
		}
	}
protected:
private:
};