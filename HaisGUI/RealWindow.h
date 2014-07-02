#include "pch.h"
#include "DShowPlayer.h"
class HGUI_API RealWindow
{
public:
	std::wstring name = L"";

	virtual bool Create(HWND parent, wchar_t* title = L"DefaultWindow", wchar_t* Class = L"HaisGUIClass");
	virtual void Draw()
	{
		RECT rt;
		GetClientRect(hWnd,&rt);
		//DrawText(GetDC(hWnd), L"込込込込込込込込", 8, &rt, DT_SINGLELINE);
		if (m_pPlayer->State() != STATE_CLOSED && m_pPlayer->HasVideo())
		{
			// The player has video, so ask the player to repaint. 
			m_pPlayer->Repaint(GetDC(hWnd));
		}
		//DrawText(GetDC(hWnd), L"込込込込込込込込", 8, &rt, DT_SINGLELINE);
	}
	virtual HWND GetHWND(){ return hWnd;  }
protected:
	HWND hWnd;
	DShowPlayer* m_pPlayer;
private:
};