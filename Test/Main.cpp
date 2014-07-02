#include <windows.h>
//#include "UIEngine.h"
#include "config.h"
#include "Application.h"
#include "UIEnginePopupWindow.h"
#include "Panel.h"
#include "DShowPlayer.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	UIEngine* uie = Application::Get()->GetUIEngine();
	UIEnginePopupWindow* wd = new UIEnginePopupWindow();
	wd->PreCreate();
	wd->Create();
	//Panel* pp = new Panel(Rect(100, 65, 400, 200));
	//pp->name = L"pp";
	//pp->indexable = true;
	//TestPanel* tp = new TestPanel(Rect(120, 50, 400, 200));
	//tp->name = L"TT";
	//pp->indexable = true;
	//uie->AttachWindow(wd);
	//wd->CreateButton(1);
	//wd->GetControlsByID(1)->MoveTo(Rect(100, 100, 800, 200));
	//UIEnginePopupWindow* wd1 = new UIEnginePopupWindow();
	//wd1->Create();
	//uie->AttachWindow(wd1);
	//wd1->CreateButton(1);
	//wd1->GetControlsByID(1)->MoveTo(Rect(200, 100, 800, 200));

	/*wd->AddPanel(pp);
	wd->AddPanel(tp);

	pp->CreateButton(1);
	pp->CreateLabel(2);
	pp->GetControlsByID(2)->SetText(L"ccc");*/
	RealWindow* rw = new RealWindow();
	rw->Create(wd->GetHWND());
	wd->AddRealWindow(rw);

	return Application::Get()->Run();
}