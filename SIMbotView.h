// SIMbotView.h : interface of the CSIMbotView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIMBOTVIEW_H__5D863E3F_3054_4F0E_AE22_46FB636F0F9A__INCLUDED_)
#define AFX_SIMBOTVIEW_H__5D863E3F_3054_4F0E_AE22_46FB636F0F9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PI 3.14159265358979323846

class CSIMbotView : public CView
{

protected: // create from serialization only
	CSIMbotView();
	DECLARE_DYNCREATE(CSIMbotView)

// Attributes
public:
	CSIMbotDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIMbotView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawMaze(CDC* pDC);
	UINT    TimerVal;
	static void DrawRobot(CDC* pDC, int x,int y, int degree);
	virtual ~CSIMbotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// Generated message map functions
protected:
	//{{AFX_MSG(CSIMbotView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHelpTest();
	afx_msg void OnHelpTestDec();
};

#ifndef _DEBUG  // debug version in SIMbotView.cpp
inline CSIMbotDoc* CSIMbotView::GetDocument()
   { return (CSIMbotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMBOTVIEW_H__5D863E3F_3054_4F0E_AE22_46FB636F0F9A__INCLUDED_)
