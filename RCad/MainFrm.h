// MainFrm.h : interface of the CMainFrame class
//


#pragma once
#include "WorkSpaceBar.h"
#include "WorkSpaceBar2.h"
#include "OutputBar.h"
#include "PropertiesViewBar.h"
#include "ToolBox.h"

class CMainFrame : public CBCGPFrameWnd
{

protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CBCGPStatusBar			m_wndStatusBar;
	CBCGPMenuBar			m_wndMenuBar;
	CBCGPToolBar			m_wndToolBar;
	CWorkSpaceBar			m_wndWorkSpace;
	CWorkSpaceBar2			m_wndWorkSpace2;
	COutputBar				m_wndOutput;
	CBCGPPropBar			m_wndPropGrid;
	CToolBoxBarEx			m_wndToolBox;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFileClose();
	afx_msg LRESULT OnToolbarReset(WPARAM,LPARAM);
	afx_msg void OnToolBox();
	afx_msg LRESULT OnDPIChanged(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()

};
