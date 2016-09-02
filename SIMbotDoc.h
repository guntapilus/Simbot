// SIMbotDoc.h : interface of the CSIMbotDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIMBOTDOC_H__E6C07EE6_9EC1_4E54_BC96_3ECDBBEE5AC3__INCLUDED_)
#define AFX_SIMBOTDOC_H__E6C07EE6_9EC1_4E54_BC96_3ECDBBEE5AC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSIMbotDoc : public CDocument
{
protected: // create from serialization only
	CSIMbotDoc();
	DECLARE_DYNCREATE(CSIMbotDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIMbotDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSIMbotDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSIMbotDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMBOTDOC_H__E6C07EE6_9EC1_4E54_BC96_3ECDBBEE5AC3__INCLUDED_)
