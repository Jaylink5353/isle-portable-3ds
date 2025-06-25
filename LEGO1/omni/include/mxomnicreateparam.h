#ifndef MXOMNICREATEPARAM_H
#define MXOMNICREATEPARAM_H

#include "lego1_export.h"
#include "mxparam.h"
#include "mxvideoparam.h"
#include <SDL3/SDL_video.h>
#ifdef MINIWIN
#include "miniwin/windows.h"
#else
#include <windows.h>
#endif

class MxOmniCreateParam : public MxParam {
	public:
	#if defined(_3DS) || defined(__3DS__)
		MxOmniCreateParam(const char* p_path, SDL_Window* p_windowHandle, MxVideoParam& p_videoParam, MxOmniCreateFlags p_flags);
		SDL_Window* GetWindowHandle() const { return m_windowHandle; }
	#else
		MxOmniCreateParam(const char* p_path, HWND p_windowHandle, MxVideoParam& p_videoParam, MxOmniCreateFlags p_flags);
		HWND GetWindowHandle() const { return m_windowHandle; }
	#endif
		const char* GetMediaPath() const { return m_mediaPath.GetData(); } // or .c_str() if using std::string
	
	protected:
	MxVideoParam m_videoParam;
    MxOmniCreateFlags m_createFlags;
	#if defined(_3DS) || defined(__3DS__)
		SDL_Window* m_windowHandle;
	#else
		HWND m_windowHandle;
	#endif
		MxString m_mediaPath; // or std::string
		// Other members...
	};
	#endif