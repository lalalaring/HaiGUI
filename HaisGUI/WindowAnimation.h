#include "pch.h"

enum class WAnimationType
{
	UNKNOWN,
	FadeIn,
	FadeOut

};
class HGUI_API Animation
{
public:
	HWND hwnd = 0;
	WAnimationType type = WAnimationType::UNKNOWN;
	float time = 0.0f;
	POINT from;// { 0, 0 };
	POINT to;// {0, 0};
	int status = 0; //0 stop 1 run 2 finished
	float timepassed = 0.0f;
	//////////////////////////////////////////////////////////////////////////
	float opt = 1.0f;

	void Step(float timedelta);
private:
	void Update(float timedelta);

};
class HGUI_API WindowAnimation
{
public:
	static WindowAnimation* Get();
	void Create(wchar_t* name, Animation* ani);
	void Start(wchar_t* name);
	void Step(float timedelta);
	int GetStatus(wchar_t* name);
	void Stop(wchar_t* name);
	void Destory(wchar_t* name);
protected:
private:
	WindowAnimation()
	{

	}
	std::hash_map<wchar_t*, Animation*> _animlist;
};