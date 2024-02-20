// workspace2.h : interface of the CWorkSpaceBar2 class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CWorkSpaceBar2 : public CBCGPDialogBar
{
public:
	CWorkSpaceBar2();

// Dialog Data
	//{{AFX_DATA(CWorkSpaceBar2)
	enum { IDD = IDD_DIALOGBAR };
	CBCGPListBox	m_wndList;
	//}}AFX_DATA

// Attributes
protected:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkSpaceBar2)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWorkSpaceBar2();

// Generated message map functions
protected:
	afx_msg LRESULT HandleInitDialog(WPARAM, LPARAM);
	afx_msg void OnUpdateCheckBox(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
