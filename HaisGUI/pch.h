#pragma  once
#include <windows.h>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <map>
#include <hash_map>
#include <list>
#include <vector>
#include <memory>
#include <Shobjidl.h>
#include <thumbcache.h>  

#include <atlimage.h>
#include "config.h"
template<class Interface>
inline void SafeRelease(Interface **ppInterfaceToRelease)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}