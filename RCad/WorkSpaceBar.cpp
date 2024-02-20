// workspace.cpp : implementation of the CWorkSpaceBar class
//

#include "stdafx.h"
#include "RCad.h"
#include "WorkSpaceBar.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceBar

BEGIN_MESSAGE_MAP(CWorkSpaceBar, CBCGPDockingControlBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceBar construction/destruction

CWorkSpaceBar::CWorkSpaceBar()
{
	// TODO: add one-time construction code here

}

CWorkSpaceBar::~CWorkSpaceBar()
{
}


/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceBar message handlers

int CWorkSpaceBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBCGPDockingControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Create tree control:
	const DWORD dwViewStyle =	WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS;

	m_wndTree.m_bVisualManagerStyle = TRUE;

	if (!m_wndTree.Create(dwViewStyle, rectDummy, this, 1))
	{
		TRACE0("Failed to create workspace view\n");
		return -1;      // fail to create
	}

	// Setup tree content:
	HTREEITEM hRoot = m_wndTree.InsertItem(_T("Root 1"));
	m_wndTree.InsertItem(_T("Item 1"), hRoot);
	m_wndTree.InsertItem(_T("Item 2"), hRoot);

	m_wndTree.Expand(hRoot, TVE_EXPAND);

	return 0;
}

void CWorkSpaceBar::OnSize(UINT nType, int cx, int cy)
{
	CBCGPDockingControlBar::OnSize(nType, cx, cy);

	// Tree control should cover a whole client area:
	m_wndTree.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
}
