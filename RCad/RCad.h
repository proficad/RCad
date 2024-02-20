// RCad.h : main header file for the RCad application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// MyApp:
// See RCad.cpp for the implementation of this class
//

class MyApp : public CBCGPWinApp
{
public:
	MyApp();

	// Override from CBCGPWorkspace
	virtual void PreLoadState();

protected:

	CMultiDocTemplate* m_pDocTemplate;
public:

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	afx_msg void OnFileNewFrame();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern MyApp theApp;
