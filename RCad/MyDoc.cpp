// MyDoc.cpp : implementation of the MyDoc class
//

#include "stdafx.h"
#include "RCad.h"

#include "MyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// MyDoc

IMPLEMENT_DYNCREATE(MyDoc, CDocument)

BEGIN_MESSAGE_MAP(MyDoc, CDocument)
END_MESSAGE_MAP()


// MyDoc construction/destruction

MyDoc::MyDoc()
{
	// TODO: add one-time construction code here

}

MyDoc::~MyDoc()
{
}

BOOL MyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// MyDoc serialization

void MyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// MyDoc diagnostics

#ifdef _DEBUG
void MyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void MyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// MyDoc commands
