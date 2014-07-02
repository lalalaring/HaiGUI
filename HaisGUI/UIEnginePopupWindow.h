#include "UIEngineWindow.h"

class HGUI_API UIEnginePopupWindow :public UIEngineWindow
{
public:
	void PreCreate()
	{
		wndstyle = WS_POPUP;
	}
protected:
private:
};