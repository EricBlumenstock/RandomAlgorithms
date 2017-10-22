// lndmsvcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "lndmsvc.h"
#include "lndmsvcD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLndmsvcDlg dialog

CLndmsvcDlg::CLndmsvcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLndmsvcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLndmsvcDlg)
	m_fObjective = 0.0f;
	m_fX = 0.0f;
	m_fY = 0.0f;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLndmsvcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLndmsvcDlg)
	DDX_Text(pDX, IDC_LNDMSVCX_OBJECTIVE, m_fObjective);
	DDX_Text(pDX, IDC_LNDMSVCX_X, m_fX);
	DDX_Text(pDX, IDC_LNDMSVCX_Y, m_fY);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLndmsvcDlg, CDialog)
	//{{AFX_MSG_MAP(CLndmsvcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnSolve)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLndmsvcDlg message handlers

BOOL CLndmsvcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLndmsvcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLndmsvcDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLndmsvcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLndmsvcDlg::OnSolve() 
{
//---------------------------------------------------------
//
// When the user presses the Solve button we use the 32 bit
// LINDO DLL (LNDDLL32.DLL) to generate and solve the 
// following small LP:
// 
//     Max 20 X + 30 Y
//     S.T.
//         X < 50
//         Y < 60
//         X + 2Y < 120
//     End
//
// Results are posted to the dialog box.
//
//---------------------------------------------------------
//

// Initialize LINDO by calling ILINDO and INIT.  
   ILINDO();
   INIT();

// Capture any standard output in a file:

// First, open a file
   char *cKfname = "LINDO.OUT";
   long lUnit = 60, lFname = 9, lInOrOut = 0, 
    lNotFmt = 0, lLutrmi = 0, lLutrmo = 0;
   LUNOPN( &lUnit, &lFname, &cKfname, &lInOrOut,
    &lNotFmt, &lLutrmi, &lLutrmo);

// Now, tell LINDO to divert all standard 
//  output to this unit
   CAPOUT( &lUnit);

// Put LINDO in TERSE mode
   long lTerse = 0;
   QUIET( &lTerse);
      
// Define the rows
   long i;
   long lIdir = -1, lIdrow, lTruble;
   float fRhs = 0.f;
   float fConstraintRhs[3]={50.f,60.f,120.f};

// Define objective row
   DEFROW( &lIdir, &fRhs, &lIdrow, &lTruble);

// Define constraint rows
   lIdir = 1;
   for ( i = 2; i <= 4; i++)
   {
      DEFROW( &lIdir, &fConstraintRhs[ i - 2], 
       &lIdrow, &lTruble);
   }

// Define our two columns
   char *cNameX = "X       ";   
   char *cNameY = "Y       ";   
   long lNonz = 3;
   float fValX[] = { 20.f, 1.f, 1.f};
   float fValY[] = { 30.f, 1.f, 2.f};
   long lIroX[] = { 1, 2, 4};
   long lIroY[] = { 1, 3, 4};

// Call APPCOL to send LINDO column X
   APPCOL( &cNameX, &lNonz, fValX, lIroX, &lTruble);

// Call APPCOL to send LINDO column Y
   APPCOL( &cNameY, &lNonz, fValY, lIroY, &lTruble);

// Call GO to optimize the model
   long lLIMGO = 0, lISTAT;
   GO( &lLIMGO, &lISTAT);

// Get the solution from LINDO

// Get the objective value
   float fDual;
   i = 1;
   REPROW( &i, &m_fObjective, &fDual);

// Get the value of X
   REPVAR( &i, &m_fX, &fDual);

// Get the value of Y
   i = 2;
   REPVAR( &i, &m_fY, &fDual);

// Post solution values in dialog box
   UpdateData( FALSE);

// Shut LINDO down
   LSEXIT();

// All done
   return;
}
