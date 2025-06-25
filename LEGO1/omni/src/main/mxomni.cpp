#include "mxomni.h"

#include "mxactionnotificationparam.h"
#include "mxatom.h"
#include "mxautolock.h"
#include "mxdsmultiaction.h"
#include "mxeventmanager.h"
#include "mxmisc.h"
#include "mxnotificationmanager.h"
#include "mxobjectfactory.h"
#include "mxomnicreateparam.h"
#include "mxpresenter.h"
#include "mxsoundmanager.h"
#include "mxstreamer.h"
#include "mxticklemanager.h"
#include "mxtimer.h"
#include "mxvariabletable.h"
#include "mxvideomanager.h"

#include <SDL3/SDL_filesystem.h>
#include <SDL3/SDL_log.h>

MxString g_hdPath = "";
MxString g_cdPath = "E:";
MxBool g_use3dSound = FALSE;
MxOmni* MxOmni::g_instance = NULL;

vector<MxString> MxOmni::g_hdFiles;
vector<MxString> MxOmni::g_cdFiles;

// FUNCTION: LEGO1 0x100aef10
MxOmni::MxOmni()
{
	Init();
}

// ... (rest of file unchanged until Init)

void MxOmni::Init()
{
#if defined(_3DS) || defined(__3DS__)
	m_windowHandle = nullptr;
#else
	m_windowHandle = NULL;
#endif
	m_objectFactory = NULL;
	m_variableTable = NULL;
	m_tickleManager = NULL;
	m_notificationManager = NULL;
	m_videoManager = NULL;
	m_soundManager = NULL;
	m_eventManager = NULL;
	m_timer = NULL;
	m_streamer = NULL;
	m_atomSet = NULL;
	m_paused = FALSE;
}

// ... (rest of file unchanged until Create)

MxResult MxOmni::Create(MxOmniCreateParam& p_param)
{
	MxResult result = FAILURE;

	if (!(m_atomSet = new MxAtomSet())) {
		goto done;
	}
	done:
	m_mediaPath = p_param.GetMediaPath();
#if defined(_3DS) || defined(__3DS__)
	m_windowHandle = p_param.GetWindowHandle(); // SDL_Window*
	return 0;
#else
	m_windowHandle = p_param.GetWindowHandle(); // HWND
#endif
}

	// ... rest of function unchanged ...
// (No further changes needed for m_windowHandle use)