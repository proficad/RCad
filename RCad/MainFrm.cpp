// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "RCad.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CBCGPFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CBCGPFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_CLOSE, &CMainFrame::OnFileClose)
	ON_REGISTERED_MESSAGE(BCGM_RESETTOOLBAR, &CMainFrame::OnToolbarReset)
	ON_COMMAND(ID_TOOLBOX, &CMainFrame::OnToolBox)
	ON_MESSAGE(WM_DPICHANGED, &CMainFrame::OnDPIChanged)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	SetDockingBarsIconList(IDB_WORKSPACE);

	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBCGPFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	CBCGPToolBar::EnableQuickCustomization();

	// Menu will not take the focus on activation:
	CBCGPPopupMenu::SetForceMenuFocus(FALSE);

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("Failed to create menubar\n");
		return -1;      // fail to create
	}

	m_wndMenuBar.SetBarStyle(m_wndMenuBar.GetBarStyle() | CBRS_SIZE_DYNAMIC);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME, 0, 0, FALSE, 0, 0, IDB_TOOLBAR_HC))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}


	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	const int nPaneSize = globalUtils.ScaleByDPI(200, this);

	if (!m_wndWorkSpace.Create(_T("View 1"), this, CRect(0, 0, nPaneSize, nPaneSize),
		TRUE, ID_VIEW_WORKSPACE,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create Workspace bar\n");
		return -1;      // fail to create
	}

	m_wndWorkSpace.SetIconIndex(0);

	if (!m_wndWorkSpace2.Create(_T("View 2"),
		this, TRUE, MAKEINTRESOURCE(IDD_DIALOGBAR),
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI,
		ID_VIEW_WORKSPACE2))
	{
		TRACE0("Failed to create Workspace bar 2\n");
		return -1;      // fail to create
	}

	m_wndWorkSpace2.SetIconIndex(1);


	const int nOutputPaneSize = globalUtils.ScaleByDPI(150, this);

	if (!m_wndOutput.Create(_T("Output"), this, CSize(nOutputPaneSize, nOutputPaneSize),
		TRUE /* Has gripper */, ID_VIEW_OUTPUT,
		WS_CHILD | WS_VISIBLE | CBRS_BOTTOM))
	{
		TRACE0("Failed to create output bar\n");
		return -1;      // fail to create
	}
	m_wndOutput.SetIconIndex(2);

	if (!m_wndPropGrid.Create(_T("Properties"), this, CRect(0, 0, nPaneSize, nPaneSize),
		TRUE,
		ID_VIEW_PROPERTIES,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_RIGHT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create Properties Bar\n");
		return FALSE;		// fail to create
	}

	m_wndPropGrid.SetIconIndex(3);


	if (!m_wndToolBox.Create(_T("ToolBox"), this, CRect(0, 0, nPaneSize, 2 * nPaneSize), TRUE, ID_TOOLBOX,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_RIGHT | CBRS_BCGP_CLOSE | CBRS_BCGP_FLOAT))
	{
		TRACE0("Failed to create ToolBox Bar\n");
		return FALSE;      // fail to create
	}

	m_wndToolBox.SetIconIndex(6);

	CString strMainToolbarTitle;
	strMainToolbarTitle.LoadString(IDS_MAIN_TOOLBAR);
	m_wndToolBar.SetWindowText(strMainToolbarTitle);

	// TODO: delete these three lines if you don't want the toolbar to be dockable
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndWorkSpace.EnableDocking(CBRS_ALIGN_ANY);
	m_wndWorkSpace2.EnableDocking(CBRS_ALIGN_ANY);
	m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
	m_wndPropGrid.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBox.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	EnableAutoHideBars(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndMenuBar);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndWorkSpace);
	m_wndWorkSpace2.AttachToTabWnd(&m_wndWorkSpace, BCGP_DM_STANDARD, FALSE, NULL);
	DockControlBar(&m_wndOutput);
	DockControlBar(&m_wndPropGrid);
	DockControlBar(&m_wndToolBox);
	m_wndToolBox.SetAutoHideMode(TRUE, CBRS_ALIGN_RIGHT);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CBCGPFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}


// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CBCGPFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CBCGPFrameWnd::Dump(dc);
}

#endif //_DEBUG

// CMainFrame message handlers

BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
{
	// base class does the real work

	if (!CBCGPFrameWnd::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}

	CWinApp* pApp = AfxGetApp();
	if (pApp->m_pMainWnd == NULL)
		pApp->m_pMainWnd = this;

	return TRUE;
}

void CMainFrame::OnFileClose()
{
   DestroyWindow();
}

LRESULT CMainFrame::OnToolbarReset(WPARAM /*wp*/,LPARAM)
{
	// TODO: reset toolbar with id = (UINT) wp to its initial state:
	//
	// UINT uiToolBarId = (UINT) wp;
	// if (uiToolBarId == IDR_MAINFRAME)
	// {
	//		do something with m_wndToolBar
	// }

	return 0;
}

void CMainFrame::OnToolBox()
{
	int nPage = -1;
	int nTool = m_wndToolBox.GetLastClickedTool(nPage);

	const MSG* pMsg = CWnd::GetCurrentMessage();

	if (pMsg->lParam != (LPARAM)m_wndToolBox.GetSafeHwnd())
	{
		m_wndToolBox.ShowControlBar(!m_wndToolBox.IsVisible(), FALSE, TRUE);
		return;
	}

	TRACE(_T("Toolbox item clicked page = %d, item = %d\n"), nPage, nTool);
}



LRESULT CMainFrame::OnDPIChanged(WPARAM wp, LPARAM lp)
{
	LRESULT lRes = CBCGPFrameWnd::OnDPIChanged(wp, lp);

	return lRes;
}
