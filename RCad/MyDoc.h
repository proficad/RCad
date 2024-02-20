// MyDoc.h : interface of the MyDoc class
//


#pragma once


class MyDoc : public CDocument
{
protected: // create from serialization only
	MyDoc();
	DECLARE_DYNCREATE(MyDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~MyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


