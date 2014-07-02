#include "pch.h"


class HGUI_API ShellHelper
{
public:
	bool GetThumbnail(wchar_t* filename)
	{
		//IShellItem *psi;
		//HRESULT  hr = SHCreateItemFromParsingName(filename, NULL, IID_PPV_ARGS(&psi));
		//IThumbnailProvider *pThumbProvider;
		//hr = psi->BindToHandler(NULL, GUID{}, IID_PPV_ARGS(&pThumbProvider));
		//WTS_ALPHATYPE wtsAlpha;
		//hr = pThumbProvider->GetThumbnail(nSize, &g_hThumbnail, &wtsAlpha);
		//CreateBindCtx(0, &m_pBindContext);
		//HRESULT hr = SHCreateItemFromParsingName(
		//	filename,
		//	m_pBindContext,
		//	IID_PPV_ARGS(&pShellItemImageFactory)
		//	);
		//hr = pShellItemImageFactory->GetImage(iconSize, 0x0, &iconImage);
		//BITMAPINFO bi = { 0 };
		//bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);

		//// Get the bitmap info header.
		//if (0 == GetDIBits(
		//	memoryDC,   // hdc
		//	iconImage,  // hbmp
		//	0,          // uStartScan
		//	0,          // cScanLines
		//	NULL,       // lpvBits
		//	&bi,
		//	DIB_RGB_COLORS
		//	))
		//{
		//	hr = E_FAIL;
		//	
		//}
		//if (0 == GetDIBits(
		//	memoryDC,
		//	iconImage,
		//	0,
		//	-bi.bmiHeader.biHeight,
		//	pBits,
		//	&bi,
		//	DIB_RGB_COLORS))
		//{
		//	hr = E_FAIL;
		//	break;
		//}

		//// Now we copy the buffer into video memory.
		//hr = m_pBitmapAtlas->CopyFromMemory(
		//	&m_pFiles[i].placement,
		//	pBits,
		//	bi.bmiHeader.biSizeImage / -bi.bmiHeader.biHeight
		//	);

		//if (FAILED(hr))
		//{
		//	break;
		//}
	}
	void Render()
	{
		//m_pRT->DrawBitmap(
		//	m_pBitmapAtlas,
		//	D2D1::RectF(
		//	0,
		//	interpolatedPosition,
		//	static_cast<FLOAT>(msc_iconSize),
		//	interpolatedPosition + static_cast<FLOAT>(msc_iconSize)),
		//	opacity,
		//	D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		//	D2D1::RectF(
		//	(FLOAT)m_pFiles[i].placement.left,
		//	(FLOAT)m_pFiles[i].placement.top,
		//	(FLOAT)m_pFiles[i].placement.right,
		//	(FLOAT)m_pFiles[i].placement.bottom)
		//	);
	}
protected:
private:
	IShellItemImageFactory *pShellItemImageFactory = NULL;
	IBindCtx *m_pBindContext;
};
"