// QCommonView.h : interface of the QCommonView class
//


#pragma once


class QCommonView : public CBCGPScrollView
{
protected: // create from serialization only
	QCommonView();
	DECLARE_DYNCREATE(QCommonView)

// Attributes
public:
	MyDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~QCommonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	afx_msg void OnFilePrintPreview();
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in QCommonView.cpp
inline MyDoc* QCommonView::GetDocument() const
	{ return reinterpret_cast<MyDoc*>(m_pDocument); }
#endif

