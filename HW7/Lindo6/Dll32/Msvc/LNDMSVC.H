// lndmsvc.h : main header file for the LNDMSVC application
//

#if !defined(AFX_LNDMSVC_H__12BD351C_4E47_11D2_9258_004005A0998B__INCLUDED_)
#define AFX_LNDMSVC_H__12BD351C_4E47_11D2_9258_004005A0998B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLndmsvcApp:
// See lndmsvc.cpp for the implementation of this class
//

class CLndmsvcApp : public CWinApp
{
public:
	CLndmsvcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLndmsvcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLndmsvcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LNDMSVC_H__12BD351C_4E47_11D2_9258_004005A0998B__INCLUDED_)
