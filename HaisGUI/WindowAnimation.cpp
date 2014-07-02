#include "WindowAnimation.h"
void Animation::Step(float timedelta)
{
	if (status == 1)
		Update(timedelta);
}

void Animation::Update(float timedelta)
{
	timepassed += timedelta;
	if (type == WAnimationType::FadeOut)
	{
		opt -= (timedelta / time);
		if (opt < 0)
		{
			status = 2;
			return;
		}
		//SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), BYTE(255 * opt), LWA_ALPHA);
	}
	if (type == WAnimationType::FadeIn)
	{
		opt += (timedelta / time);
		if (opt > 1)
		{
			status = 2;
			return;
		}
		//SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), BYTE(255 * opt), LWA_ALPHA);
	}
	if (timepassed > time)
		status = 2;
}
//////////////////////////////////////////////////////////////////////////

WindowAnimation* WindowAnimation::Get()
{
	static WindowAnimation _instance;
	return &_instance;
}
void WindowAnimation::Create(wchar_t* name, Animation* ani)
{
	_animlist[name] = ani;
}
void WindowAnimation::Start(wchar_t* name)
{
	_animlist.find(name)->second->status = 1;
}
void WindowAnimation::Step(float timedelta)
{
	for each (auto var in _animlist)
	{
		var.second->Step(timedelta);
	}
}
int WindowAnimation::GetStatus(wchar_t* name)
{
	return _animlist.find(name)->second->status;
}
void WindowAnimation::Stop(wchar_t* name)
{
	_animlist.find(name)->second->status = 0;
}
void WindowAnimation::Destory(wchar_t* name)
{
	_animlist.erase(name);
}