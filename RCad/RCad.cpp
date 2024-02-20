// RCad.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "RCad.h"
#include "MainFrm.h"

#include "MyDoc.h"
#include "QCommonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

// MyApp

BEGIN_MESSAGE_MAP(MyApp, CBCGPWinApp)
	ON_COMMAND(ID_APP_ABOUT, &MyApp::OnAppAbout)
	ON_COMMAND(ID_FILE_NEW_FRAME, &MyApp::OnFileNewFrame)
	ON_COMMAND(ID_FILE_NEW, &MyApp::OnFileNew)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_OPEN, &CBCGPWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CBCGPWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// MyApp construction

MyApp::MyApp()
{

	// Support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;

	CBCGPVisualManagerVS2012::m_bAutoGrayscaleImages = FALSE;

	SetApplicationLookMenu(ID_VIEW_APPLOOK, BCGP_THEMES_LIST_WIN_NATIVE | BCGP_THEMES_LIST_SCENIC | BCGP_THEMES_LIST_OFFICE_2007 | BCGP_THEMES_LIST_OFFICE_2010 | BCGP_THEMES_LIST_VS_2010 | BCGP_THEMES_LIST_OFFICE_2013 | BCGP_THEMES_LIST_VS_2013 | BCGP_THEMES_LIST_OFFICE_2016 | BCGP_THEMES_LIST_VS_2019 | BCGP_THEMES_LIST_OFFICE_2022);

	// Enable VS 2019 look (Dark theme)
	SetVisualTheme(BCGP_VISUAL_THEME_VS_2019_DARK);

	CBCGPToolbarOptions toolbarOptions;

	toolbarOptions.m_nViewToolbarsMenuEntryID = ID_VIEW_TOOLBARS;
	toolbarOptions.m_nCustomizeCommandID = ID_VIEW_CUSTOMIZE;
	toolbarOptions.m_strCustomizeCommandLabel = _T("Customize...");
	toolbarOptions.m_nUserToolbarCommandIDFirst = uiFirstUserToolBarId;
	toolbarOptions.m_nUserToolbarCommandIDLast = uiLastUserToolBarId;
	toolbarOptions.m_strToolbarCustomIconsPath = _T(".\\UserImages.png");

	SetToolbarOptions(toolbarOptions);

	m_bDPIAwareTooltips = TRUE;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only MyApp object

MyApp theApp;
CBCGPOccManager theOccManager;


// MyApp initialization

BOOL MyApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CBCGPWinApp::InitInstance();

	// Remove this line if you don't need themed product dialogs:
	globalData.m_bUseVisualManagerInBuiltInDialogs = TRUE;
	globalData.m_bIsDlgWsCaptionStyle = TRUE;
	globalData.m_bIsMiniFrameWsCaptionStyle = TRUE;
	globalData.m_FrameCornerType = globalData.m_DlgCornerType = globalData.m_PopupMenuCornerType = BCGP_DWMWCP_ROUND;
	globalData.m_MiniFrameCornerType = BCGP_DWMWCP_ROUNDSMALL;
	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer(&theOccManager);

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: you should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("BCGP AppWizard-Generated Applications"));
	LoadStdProfileSettings(16);  // Load standard INI file options (including MRU)

	SetRegistryBase(_T("Settings"));

	// Initialize all Managers for usage. They are automatically constructed
	// if not yet present
	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(MyDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(QCommonView));
	if (!pDocTemplate)
		return FALSE;
	m_pDocTemplate = pDocTemplate;
	AddDocTemplate(pDocTemplate);


	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// call DragAcceptFiles only if there's a suffix
	//  In an SDI app, this should occur after ProcessShellCommand
	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();
	return TRUE;
}

// MyApp message handlers

int MyApp::ExitInstance()
{
	return CBCGPWinApp::ExitInstance();
}

// CAboutDlg dialog used for App About

class CAboutDlg : public CBCGPDialog
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
	CBCGPURLLinkButton m_btnURL;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CBCGPDialog(IDD_ABOUTBOX)
{
	EnableVisualManagerStyle(TRUE, TRUE);
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMPANY_URL, m_btnURL);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CBCGPDialog)
END_MESSAGE_MAP()

// App command to run the dialog
void MyApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// MyApp message handlers

void MyApp::OnFileNewFrame()
{
	ASSERT(m_pDocTemplate != NULL);

	CDocument* pDoc = NULL;
	CFrameWnd* pFrame = NULL;

	// Create a new instance of the document referenced
	// by the m_pDocTemplate member.
	pDoc = m_pDocTemplate->CreateNewDocument();
	if (pDoc != NULL)
	{
		// If creation worked, use create a new frame for
		// that document.
		pFrame = m_pDocTemplate->CreateNewFrame(pDoc, NULL);
		if (pFrame != NULL)
		{
			// Set the title, and initialize the document.
			// If document initialization fails, clean-up
			// the frame window and document.

			m_pDocTemplate->SetDefaultTitle(pDoc);
			if (!pDoc->OnNewDocument())
			{
				pFrame->DestroyWindow();
				pFrame = NULL;
			}
			else
			{
				// Otherwise, update the frame
				m_pDocTemplate->InitialUpdateFrame(pFrame, pDoc, TRUE);
			}
		}
	}

	// If we failed, clean up the document and show a
	// message to the user.

	if (pFrame == NULL || pDoc == NULL)
	{
		delete pDoc;
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
	}
}

void MyApp::OnFileNew()
{
	CDocument* pDoc = NULL;
	CFrameWnd* pFrame;
	pFrame = DYNAMIC_DOWNCAST(CFrameWnd, CWnd::GetActiveWindow());

	if (pFrame != NULL)
		pDoc = pFrame->GetActiveDocument();

	if (pFrame == NULL || pDoc == NULL)
	{
		// if it's the first document, create as normal
		CBCGPWinApp::OnFileNew();
	}
	else
	{
		// Otherwise, see if we have to save modified, then
		// ask the document to reinitialize itself.
		if (!pDoc->SaveModified())
			return;

		CDocTemplate* pTemplate = pDoc->GetDocTemplate();
		ASSERT(pTemplate != NULL);

		pTemplate->SetDefaultTitle(pDoc);
		pDoc->OnNewDocument();
	}
}

void MyApp::PreLoadState()
{
	GetContextMenuManager()->AddMenu(_T("My menu"), IDR_CONTEXT_MENU);

	// TODO: add another context menus here
}
