//
// ToolBox.cpp: implementation of the CToolBoxBar class.
//

#include "stdafx.h"
#include "ToolBox.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PAGE1_LABELS _T("Item 1\nItem 2")
#define PAGE2_LABELS _T("Item 1\nItem 2")

#define SEARCH_PROMPT			_T("Search Toolbox (Ctrl+F)")
#define OUT_OF_FILTER_MESSAGE	_T("No results found")


/////////////////////////////////////////////////////////////////////////////
// CToolBoxBarEx

BEGIN_MESSAGE_MAP(CToolBoxBarEx, CBCGPToolBoxEx)
	ON_WM_CREATE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToolBoxBarEx construction/destruction

CToolBoxBarEx::CToolBoxBarEx()
{
}

CToolBoxBarEx::~CToolBoxBarEx()
{
}

/////////////////////////////////////////////////////////////////////////////
// CToolBoxBarEx message handlers

int CToolBoxBarEx::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBCGPToolBoxEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	EnableSearchBox(TRUE, SEARCH_PROMPT, OUT_OF_FILTER_MESSAGE, TRUE);

	AddToolsPage(_T("Page 1"), IDB_TOOLS_PAGE1, 16, PAGE1_LABELS);
	AddToolsPage(_T("Page 2"), IDB_TOOLS_PAGE2, 16, PAGE2_LABELS);

	SetActivePage(0);

	return 0;
}
