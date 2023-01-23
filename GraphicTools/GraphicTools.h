// GraphicTools.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CGraphicToolsApp:
// See GraphicTools.cpp for the implementation of this class
//

class CGraphicToolsApp : public CWinApp
{
public:
	CGraphicToolsApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGraphicToolsApp theApp;