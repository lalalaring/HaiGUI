#pragma once
#include "Controls.h"


class HGUI_API Button :public Controls
{
public:
	Button() = default;
	Button(Rect rect)
	{
		_rect = rect;
	}
	virtual void Draw(POINT offset, UIDrawer* dr) override;
protected:
private:
};