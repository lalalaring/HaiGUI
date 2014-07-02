#pragma once
#include "Controls.h"


class HGUI_API Label :public Controls
{
public:
	Label() = default;
	Label(Rect rect)
	{
		_rect = rect;
	}
	virtual void Draw(POINT offset, UIDrawer* dr) override;
protected:
private:
};