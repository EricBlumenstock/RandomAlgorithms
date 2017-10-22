// lndmsvcDlg.h : header file
//

#if !defined(AFX_LNDMSVCDLG_H__12BD351E_4E47_11D2_9258_004005A0998B__INCLUDED_)
#define AFX_LNDMSVCDLG_H__12BD351E_4E47_11D2_9258_004005A0998B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "lindmsvc.h"

/////////////////////////////////////////////////////////////////////////////
// CLndmsvcDlg dialog

class CLndmsvcDlg : public CDialog
{
// Construction
public:
	CLndmsvcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLndmsvcDlg)
	enum { IDD = IDD_LNDMSVC_DIALOG };
	float	m_fObjective;
	float	m_fX;
	float	m_fY;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLndmsvcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLndmsvcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSolve();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LNDMSVCDLG_H__12BD351E_4E47_11D2_9258_004005A0998B__INCLUDED_)
