// SIMbotView.cpp : implementation of the CSIMbotView class
//

#include "stdafx.h"
#include "SIMbot.h"
#include <cmath>
#include <math.h>
#include <ctime>

#include "SIMbotDoc.h"
#include "SIMbotView.h"

#include "Simulation.h"
Simulation* sim;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define  IDT_TIMER  WM_USER + 200 
bool ShowGraphic=true;

/////////////////////////////////////////////////////////////////////////////
// CSIMbotView

IMPLEMENT_DYNCREATE(CSIMbotView, CView)

BEGIN_MESSAGE_MAP(CSIMbotView, CView)
	//{{AFX_MSG_MAP(CSIMbotView)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP_TEST, &CSIMbotView::OnHelpTest)
	ON_COMMAND(ID_HELP_TEST_DEC, &CSIMbotView::OnHelpTestDec)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSIMbotView construction/destruction

CSIMbotView::CSIMbotView()
{
	// TODO: add construction code here
	srand((unsigned)time(NULL)); 
	sim = new Simulation();
}

CSIMbotView::~CSIMbotView()
{
	delete sim;
}

BOOL CSIMbotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSIMbotView drawing

void CSIMbotView::OnDraw(CDC* pDC)
{
	CSIMbotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DrawMaze(pDC);
	//draw robot
	//draw food

	//draw info pane
}

/////////////////////////////////////////////////////////////////////////////
// CSIMbotView diagnostics

#ifdef _DEBUG
void CSIMbotView::AssertValid() const
{
	CView::AssertValid();
}

void CSIMbotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSIMbotDoc* CSIMbotView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSIMbotDoc)));
	return (CSIMbotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSIMbotView message handlers


void CSIMbotView::DrawMaze(CDC* pDC)
{
	//map boundary
	pDC->Rectangle(sim->mapBoundaryXlow, sim->mapBoundaryYlow, sim->mapBoundaryXhigh, sim->mapBoundaryYhigh);
	//food
	//pDC->FillRect(CRect(Fx-10,Fy-10,Fx+10,Fy+10),&CBrush(RGB(0,255,0)));
}

void CSIMbotView::DrawRobot(CDC* pDC, int x,int y, int degree)
{
	//robot body
	pDC->Ellipse(x - 10, y - 10, x + 10, y + 10);
	//robot direction
	pDC->MoveTo(x, y);
	pDC->LineTo(x + (int)(10 * cos(degree*PI / 180)), y + (int)(10 * sin(degree*PI / 180)));
	pDC->FillRect(CRect(x + (int)(7 * cos(degree*PI / 180)) - 2, y + (int)(7 * sin(degree*PI / 180)) - 2, x + (int)(7 * cos(degree*PI / 180)) + 2, y + (int)(7 * sin(degree*PI / 180)) + 2), &CBrush(RGB(255, 0, 0)));
	//robot sensor line
/*	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(50*sin(degree*PI/180)),y+(int)(50*cos(degree*PI/180)));
	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(50*sin((degree+90)*PI/180)),y+(int)(50*cos((degree+90)*PI/180)));
	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(50*sin((degree-90)*PI/180)),y+(int)(50*cos((degree-90)*PI/180)));
	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(50*sin((degree+180)*PI/180)),y+(int)(50*cos((degree+180)*PI/180)));
	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(50*sin((degree+45)*PI/180)),y+(int)(50*cos((degree+45)*PI/180)));
	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(50*sin((degree+135)*PI/180)),y+(int)(50*cos((degree+135)*PI/180)));
	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(50*sin((degree-45)*PI/180)),y+(int)(50*cos((degree-45)*PI/180)));
	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(50*sin((degree-135)*PI/180)),y+(int)(50*cos((degree-135)*PI/180)));*/
	//pDC->Ellipse(x+(int)(7*cos(degree*PI/180))-3,y+(int)(7*sin(degree*PI/180))-3,x+(int)(7*cos(degree*PI/180))+3,y+(int)(7*sin(degree*PI/180))+3);
}
void CSIMbotView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CView::OnMouseMove(nFlags, point);
}
void CSIMbotView::OnTimer(UINT nIDEvent) 
{
    // Exection robot program by steping the simulation frame
	sim->frameAdvance();
	if (ShowGraphic) Invalidate();
	CView::OnTimer(nIDEvent);
}

void CSIMbotView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
    // set the speed of simulation running here...
    TimerVal = SetTimer (IDT_TIMER, 50, NULL);  // Starting the Timer
    if (TimerVal == 0)
    {
        AfxMessageBox("Unable to obtain timer");
    }
}

void CSIMbotView::OnHelpTest()
{
	/*Fy += 50;
	if (Fy < 30)  Fy = 30;
	if (Fy > 390) Fy = 390;*/
}

void CSIMbotView::OnHelpTestDec()
{
	/*Fy -= 50;
	if (Fy < 30)  Fy = 30;
	if (Fy > 390) Fy = 390;*/
}
