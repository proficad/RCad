// workspace2.cpp : implementation of the CWorkSpaceBar2 class
//

#include "stdafx.h"
#include "RCad.h"
#include "WorkSpaceBar2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceBar2

BEGIN_MESSAGE_MAP(CWorkSpaceBar2, CBCGPDialogBar)
	ON_UPDATE_COMMAND_UI(IDC_CHECK_DLGBAR, &CWorkSpaceBar2::OnUpdateCheckBox)
	ON_MESSAGE(WM_INITDIALOG, &CWorkSpaceBar2::HandleInitDialog)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceBar2 construction/destruction

CWorkSpaceBar2::CWorkSpaceBar2()
{
	// TODO: add one-time construction code here
	EnableVisualManagerStyle();
	EnableLayout();
}

CWorkSpaceBar2::~CWorkSpaceBar2()
{
}

void CWorkSpaceBar2::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialogBar::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CWorkSpaceBar2)
	DDX_Control(pDX, IDC_LIST_DLGBAR, m_wndList);
	//}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceBar2 message handlers

LRESULT CWorkSpaceBar2::HandleInitDialog(WPARAM wParam, LPARAM lParam)
{
	CBCGPDialogBar::HandleInitDialog(wParam, lParam);

	m_wndList.AddString(_T("Item 1"));
	m_wndList.AddString(_T("Item 2"));
	m_wndList.AddString(_T("Item 3"));
	m_wndList.m_bVisualManagerStyle = TRUE;

	CBCGPStaticLayout* pLayout = (CBCGPStaticLayout*)GetLayout();
	if (pLayout != NULL)
	{
		pLayout->AddAnchor(IDC_STATIC_DLGBAR, CBCGPStaticLayout::e_MoveTypeNone, CBCGPStaticLayout::e_SizeTypeHorz);
		pLayout->AddAnchor(IDC_LIST_DLGBAR, CBCGPStaticLayout::e_MoveTypeNone, CBCGPStaticLayout::e_SizeTypeBoth);
		pLayout->AddAnchor(IDC_CHECK_DLGBAR, CBCGPStaticLayout::e_MoveTypeVert, CBCGPStaticLayout::e_SizeTypeHorz);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CWorkSpaceBar2::OnUpdateCheckBox(CCmdUI* pCmdUI)
{
}
