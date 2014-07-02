#pragma  once
#define HGUI_USEDLL
#define HGUI_EXPORT
#ifdef HGUI_USEDLL
#ifdef HGUI_EXPORT
#define HGUI_API _declspec(dllexport)
#else
#define HGUI_API _declspec(dllimport)
#endif // HGUI_EXPORT

#endif // HGUI_USEDLL
