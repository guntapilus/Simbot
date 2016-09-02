// SIMbot.h : main header file for the SIMBOT application
//

#if !defined(AFX_SIMBOT_H__C93A37BC_90E4_4F31_B24A_B19316F3B0CD__INCLUDED_)
#define AFX_SIMBOT_H__C93A37BC_90E4_4F31_B24A_B19316F3B0CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSIMbotApp:
// See SIMbot.cpp for the implementation of this class
//

class CSIMbotApp : public CWinApp
{
public:
	CSIMbotApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIMbotApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSIMbotApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMBOT_H__C93A37BC_90E4_4F31_B24A_B19316F3B0CD__INCLUDED_)
