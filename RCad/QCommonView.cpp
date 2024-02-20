// QCommonView.cpp : implementation of the QCommonView class
//

#include "stdafx.h"
#include "RCad.h"

#include "MyDoc.h"
#include "QCommonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// QCommonView

IMPLEMENT_DYNCREATE(QCommonView, CBCGPScrollView)

BEGIN_MESSAGE_MAP(QCommonView, CBCGPScrollView)
	ON_WM_CONTEXTMENU()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CBCGPScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &QCommonView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CBCGPScrollView::OnFilePrint)
	ON_MESSAGE(WM_PRINTCLIENT, &QCommonView::OnPrintClient)
END_MESSAGE_MAP()

// QCommonView construction/destruction

QCommonView::QCommonView()
{
	// TODO: add construction code here

}

QCommonView::~QCommonView()
{
}

BOOL QCommonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CBCGPScrollView::PreCreateWindow(cs);
}

// QCommonView drawing

void QCommonView::OnDraw(CDC* /*pDC*/)
{
	MyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

void QCommonView::OnInitialUpdate()
{
	CBCGPScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// QCommonView printing

void QCommonView::OnFilePrintPreview()
{
	BCGPPrintPreview (this);
}

BOOL QCommonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return BCGPPreparePrinting(this, pInfo);
}

void QCommonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void QCommonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// QCommonView diagnostics

#ifdef _DEBUG
void QCommonView::AssertValid() const
{
	CBCGPScrollView::AssertValid();
}

void QCommonView::Dump(CDumpContext& dc) const
{
	CBCGPScrollView::Dump(dc);
}

MyDoc* QCommonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MyDoc)));
	return (MyDoc*)m_pDocument;
}
#endif //_DEBUG


// QCommonView message handlers

LRESULT QCommonView::OnPrintClient(WPARAM wp, LPARAM lp)
{
	if ((lp & PRF_CLIENT) == PRF_CLIENT)
	{
		CDC* pDC = CDC::FromHandle((HDC)wp);
		ASSERT_VALID(pDC);

		OnDraw(pDC);
	}

	return 0;
}


void QCommonView::OnContextMenu(CWnd*, CPoint point)
{
	if (CBCGPPopupMenu::GetSafeActivePopupMenu() != NULL)
	{
		return;
	}

	theApp.ShowPopupMenu(IDR_CONTEXT_MENU, point, this);
}
