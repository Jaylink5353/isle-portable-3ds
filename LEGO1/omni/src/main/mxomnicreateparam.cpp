#include "mxomnicreateparam.h"
#include "decomp.h"

DECOMP_SIZE_ASSERT(MxOmniCreateParam, 0x40)

#if defined(_3DS) || defined(__3DS__)
// 3DS version: use SDL_Window* for the window handle
MxOmniCreateParam::MxOmniCreateParam(
	const char* p_mediaPath,
	SDL_Window* p_windowHandle,
	MxVideoParam& p_vparam,
	MxOmniCreateFlags p_flags
)
{
	this->m_mediaPath = p_mediaPath;
	this->m_windowHandle = p_windowHandle;
	this->m_videoParam = p_vparam;
	this->m_createFlags = p_flags;
}
#else
// Windows version: use HWND for the window handle
MxOmniCreateParam::MxOmniCreateParam(
	const char* p_mediaPath,
	HWND p_windowHandle,
	MxVideoParam& p_vparam,
	MxOmniCreateFlags p_flags
)
{
	this->m_mediaPath = p_mediaPath;
	this->m_windowHandle = p_windowHandle;
	this->m_videoParam = p_vparam;
	this->m_createFlags = p_flags;
}
#endif