// SIMbotDoc.cpp : implementation of the CSIMbotDoc class
//

#include "stdafx.h"
#include "SIMbot.h"

#include "SIMbotDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSIMbotDoc

IMPLEMENT_DYNCREATE(CSIMbotDoc, CDocument)

BEGIN_MESSAGE_MAP(CSIMbotDoc, CDocument)
	//{{AFX_MSG_MAP(CSIMbotDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSIMbotDoc construction/destruction

CSIMbotDoc::CSIMbotDoc()
{
	// TODO: add one-time construction code here

}

CSIMbotDoc::~CSIMbotDoc()
{
}

BOOL CSIMbotDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSIMbotDoc serialization

void CSIMbotDoc::Serialize(CArchive& ar)
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

/////////////////////////////////////////////////////////////////////////////
// CSIMbotDoc diagnostics

#ifdef _DEBUG
void CSIMbotDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSIMbotDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSIMbotDoc commands
