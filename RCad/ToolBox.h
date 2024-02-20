// ToolBox.h: interface for the CToolBoxBar class.
//
/////////////////////////////////////////////////////////////////////////////

#pragma once


class CToolBoxBarEx : public CBCGPToolBoxEx
{
// Construction
public:
	CToolBoxBarEx();


// Overrides

// Implementation
public:
	virtual ~CToolBoxBarEx();

	// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
