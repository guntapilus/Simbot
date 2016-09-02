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
	pDC->Rectangle(mapBoundaryX[0], mapBoundaryY[0], mapBoundaryX[1], mapBoundaryY[1]);
	//food
	pDC->FillRect(CRect(Fx-10,Fy-10,Fx+10,Fy+10),&CBrush(RGB(0,255,0)));
}

void CSIMbotView::DrawRobot(CDC* pDC, int x,int y, int degree)
{
	pDC->Ellipse(x-10,y-10,x+10,y+10);
	pDC->MoveTo(x,y);
	pDC->LineTo(x+(int)(10*cos(degree*PI/180)),y+(int)(10*sin(degree*PI/180)));
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
	pDC->FillRect(CRect(x+(int)(7*cos(degree*PI/180))-2,y+(int)(7*sin(degree*PI/180))-2,x+(int)(7*cos(degree*PI/180))+2,y+(int)(7*sin(degree*PI/180))+2),&CBrush(RGB(255,0,0)));
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

void aRobot::SetDirection(int degree)
{	
	direction = degree;
	direction = direction % 360;
}

void aRobot::TurnLeft()
{
	direction -= 5;
	direction = (direction + 360) % 360;
}

void aRobot::TurnRight()
{
	direction += 5;
	direction = (direction + 360) % 360;
}


bool aRobot::MoveForward()
{
	int x=pos_x, y=pos_y;
	x +=(int)(2*cos(direction*PI/180));
	y +=(int)(2*sin(direction*PI/180));
	if (CheckWall(x,y)) {
		pos_x = x;
		pos_y = y;
		return true;
	}
	else return false;
}

bool aRobot::MoveBackward()
{
	int x=pos_x, y=pos_y;
	x -=(int)(2*cos(direction*PI/180));
	y -=(int)(2*sin(direction*PI/180));
	if (CheckWall(x,y)) {
		pos_x = x;
		pos_y = y;
		return true;
	}
	else return false;
}

bool aRobot::CheckWall(int x, int y)
{
	if ((x>= mapBoundaryX [0]+10) && (x<= mapBoundaryX[1]-10) && (y>= mapBoundaryY[0]+10) && (y<= mapBoundaryY[1]-10))	//map boundary
	{
		//check other robot
		for (int i = 0; i < robotCount; i++)
		{
			if (i != id)
			{
				int dist_x = x - otherRobot[i].pos_x;
				dist_x *= dist_x;
				int dist_y = y - otherRobot[i].pos_y;
				dist_y *= dist_y;
				int dist = (int)sqrt(dist_x + dist_y);
				if (dist < 20)	//count both our robot and the other robot
				{
					Collision = true;
					return false;
				}
			}
		}
		Collision=false;
		return true;
	}
	Collision=true;
	return false;
}

bool aRobot::CheckSensor(int x, int y)
{
	if ((x>= mapBoundaryX[0]) && (x<= mapBoundaryX[1]) && (y>= mapBoundaryY[0]) && (y<= mapBoundaryY[1]))	//map boundary
	{
		//check other robot
		for (int i = 0; i < robotCount; i++)
		{
			if (i != id)
			{
				int dist_x = x - otherRobot[i].pos_x;
				dist_x *= dist_x;
				int dist_y = y - otherRobot[i].pos_y;
				dist_y *= dist_y;
				int dist = (int) sqrt(dist_x+dist_y);
				if(dist < 10)	//only the other robot's radius
					return false;
			}
		}
		return true;
	}
	return false;
}

void aRobot::ScanSensors()
{
	int x,y;
	x=pos_x;
	y=pos_y;
	
	for (int n=0;n<8;n++)	//for all direction
	{
		int value=0;
		for (int i=12;i<=50;i+=2)	//keep looking outward
		{
			x=pos_x+(int)(i*cos((direction+n*45)*PI/180));
			y=pos_y+(int)(i*sin((direction+n*45)*PI/180));
			
			if (!CheckSensor(x,y)) 
				break;
			value += 2;
		}
		IR[n]=value*5/2;
	}
}




void aRobot::Turn(int Degree)
{
	direction += Degree;
	direction %= 360;
}

bool aRobot::Move(int Pixel)
{
	int x=pos_x, y=pos_y;
	x +=(int)(Pixel*cos(direction*PI/180));
	y +=(int)(Pixel*sin(direction*PI/180));
	if (CheckWall(x,y)) {
		pos_x = x;
		pos_y = y;
		return true;
	}
	else return false;
}

int aRobot::Smell()
{
    int food_x = Fx; // your food x position 
    int food_y = Fy;

	int dx = food_x - pos_x;
	int dy = food_y - pos_y;
	int d = (int)(atan((double)dy/dx)*180/PI);
	if (dx>=0)
		return (d - direction + 720)%360;
	else 
		return (180 - direction + d + 720)%360;
}
#define NUMRULE 5
void aRobot::Execution()
{
	double rule[NUMRULE];
	double turn[NUMRULE];
	double move[NUMRULE];

	ScanSensors();
	irfront = IR[0];
	irfront_right = IR[1];
	irfront_left = IR[7];
	irtail_right = IR[3];
	irtail_left = IR[5];
	irright = IR[2];
	irleft = IR[6];

	rule[0] = Ffar();									turn[0] = 0;	move[0] = 10;
	rule[1] = Ffar()* Lfar() * Rfar();					turn[1] = 0; 	move[1] = 10;
	rule[2] = smellleft()*Ffar()*Lfar();				turn[2] = -30;	move[2] = 5;
	rule[3] = smellright()*Ffar()*Rfar();				turn[3] = 40;	move[3] = 5;
	rule[4] = 1 - Ffar();								turn[4] = 50;	move[4] = 0;
	//rule[1] = smellleft()* Ffar()* Lfar() * Rfar();  	turn[1] = -40;	move[1]=0;
	//rule[2] = smellright()* Ffar()* Lfar() * Rfar();    turn[2] = 30; 	move[2]=0;

     double answerturn=0.0,answermove=0.0;
     for (int i=0;i<NUMRULE;i++)
	 {
	    answerturn += turn[i]*rule[i];
  	    answermove += move[i]*rule[i];
	 }
	Turn((int)answerturn);
	Move((int)answermove);

}

double aRobot:: Ffar() 
{
	 if (irfront <= 10) return (0.0);
	 else if (irfront >= 90) return(1.0);
	 else return (double)(irfront-10)/80;
}

double aRobot:: Lfar() 
{
	 if (irleft <= 10) return (0.0);
	 else if (irleft >= 90) return(1.0);
	 else return (double)(irleft-10)/80;
}

double aRobot:: Rfar() 
{
	 if (irright <= 10) return (0.0);
	 else if (irright >= 90) return(1.0);
	 else return (double)(irright-10)/80;
}

double aRobot:: smellright()
{
	int target = Smell();
	if(target>180)target = target-360;
	if(target>=45)return(1.0);
	else if(target <=0)return(0.0);
	else return (double)target/45;
}

double aRobot:: smellleft()
{
	int target = Smell();
	if(target>180)target = target-360;
	if(target<=-45)return(1.0);
	else if(target >=0)return(0.0);
	else return (double)(-1*target)/45;
}

void CSIMbotView::OnHelpTest()
{
	Fy += 50;
	if (Fy < 30)  Fy = 30;
	if (Fy > 390) Fy = 390;
}

void CSIMbotView::OnHelpTestDec()
{
	Fy -= 50;
	if (Fy < 30)  Fy = 30;
	if (Fy > 390) Fy = 390;
}
