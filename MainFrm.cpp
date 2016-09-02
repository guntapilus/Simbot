// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "SIMbot.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern bool ShowGraphic;
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_COMMAND(ID_DISPLAY, OnDisplay)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_DISPLAY, &CMainFrame::OnUpdateDisplay)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.cx = 900;
	cs.cy = 600;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnDisplay() 
{
	// TODO: Add your command handler code here
	CWnd* pMain = AfxGetMainWnd();
	ShowGraphic = ! ShowGraphic;
	CMenu *pMenu = GetMenu();

	UINT id = pMenu->GetMenuItemID(1);

	if (!ShowGraphic) pMenu->ModifyMenu(id, MF_BYCOMMAND, id, "UnFreeze Display");
	else pMenu->ModifyMenu(id, MF_BYCOMMAND, id, "Freeze Display");

	pMain->DrawMenuBar();	
}

void CMainFrame::OnUpdateDisplay(CCmdUI *pCmdUI)
{
	
}
