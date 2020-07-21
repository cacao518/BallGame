// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "balling.h"
#include "ChildView.h"
#include "math.h"
#include "Ball.h"
#include "Box.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	mapX = 0;
	boxGen = 0;
	tireOnoff = true;
	mapX2 = 0;
	Rand = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);


	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

	CDC memdc;
	memdc.CreateCompatibleDC(&dc);

	CBitmap MyBmp[12], bmp;
	bmp.CreateCompatibleBitmap(&dc, 950, 640);
	memdc.SelectObject(&bmp);

	CDC backdc[12];
	for(int i=0; i < 7; i++)
	{
		MyBmp[i + 1].LoadBitmapW(IDB_BITMAP1 + i);
		backdc[i + 1].CreateCompatibleDC(&memdc);
		backdc[i + 1].SelectObject(&MyBmp[i + 1]);
	}

	MyBmp[8].LoadBitmapW(IDB_BITMAP8);
	MyBmp[9].LoadBitmapW(IDB_BITMAP9);
	MyBmp[10].LoadBitmapW(IDB_BITMAP10);
	MyBmp[11].LoadBitmapW(IDB_BITMAP11);
	backdc[8].CreateCompatibleDC(&memdc);
	backdc[9].CreateCompatibleDC(&memdc);
	backdc[10].CreateCompatibleDC(&memdc);
	backdc[11].CreateCompatibleDC(&memdc);
	backdc[8].SelectObject(&MyBmp[8]);
	backdc[9].SelectObject(&MyBmp[9]);
	backdc[10].SelectObject(&MyBmp[10]);
	backdc[11].SelectObject(&MyBmp[11]);

	memdc.BitBlt(-mapX2,0,950,457, &backdc[11], 0, 0,SRCCOPY); // �� ���
	memdc.BitBlt(950-mapX2,0,950,457, &backdc[11], 0, 0,SRCCOPY);
	memdc.BitBlt(-mapX,457,950,183, &backdc[2], 0, 0,SRCCOPY); // �ٴ� ���
	memdc.BitBlt(950-mapX,457,950,183, &backdc[2], 0, 0,SRCCOPY);
	
	for(int j = 0; j<3; j++) // �ڽ� �ִ� 3��
	{
		if(box[j].m_boxMove == 1) // �ڽ� ������
		{
			memdc.TransparentBlt(box[j].m_pt.x, box[j].m_pt.y, 147,130, &backdc[6], 0, 0,147,130, RGB(255,0,255));
		}
		else if(box[j].m_boxMove == 2) // �ڽ� ��׷���
		{
			if(box[j].m_dust == 1)
				memdc.TransparentBlt(box[j].m_pt.x, box[j].m_pt.y, 145,125, &backdc[8], 0, 0,145,125, RGB(255,0,255));
			else if(box[j].m_dust == 2)
				memdc.TransparentBlt(box[j].m_pt.x, box[j].m_pt.y, 145,125, &backdc[9], 0, 0,145,125, RGB(255,0,255));
			else if(box[j].m_dust == 3)
				memdc.TransparentBlt(box[j].m_pt.x, box[j].m_pt.y, 145,125, &backdc[10], 0, 0,145,125, RGB(255,0,255));
			memdc.TransparentBlt(box[j].m_pt.x, box[j].m_pt.y, 147,130, &backdc[7], 0, 0,147,130, RGB(255,0,255));
		}
	}
	 
	if(ball.m_tire == 1)
		memdc.TransparentBlt(ball.m_pt.x, ball.m_pt.y, 110,110, &backdc[1], 0, 0,110,110, RGB(255,0,255)); // Ÿ�̾�
	else if(ball.m_tire == 2)
		memdc.TransparentBlt(ball.m_pt.x, ball.m_pt.y, 110,110, &backdc[3], 0, 0,110,110, RGB(255,0,255)); // Ÿ�̾�
	else if(ball.m_tire == 3)
		memdc.TransparentBlt(ball.m_pt.x, ball.m_pt.y, 110,110, &backdc[4], 0, 0,110,110, RGB(255,0,255)); // Ÿ�̾�
	else if(ball.m_tire == 4)
		memdc.TransparentBlt(ball.m_pt.x, ball.m_pt.y, 110,110, &backdc[5], 0, 0,110,110, RGB(255,0,255)); // Ÿ�̾�

	CRect rect;
	GetClientRect(&rect);
	dc.StretchBlt(0,0,rect.Width(), rect.Height(), &memdc, 0,0,950,640, SRCCOPY);

	
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(ball.m_flag == 1)
	{
		TireAction();

		for(int w = 0; w<3; w++)
		{
			BoxAction(w);
		}
	}
	
	Invalidate(false);
	
	CWnd::OnTimer(nIDEvent);
}

void CChildView::BoxAction(int w)
{
	if(box[0].m_boxMove == 0)
		if(box[1].m_boxMove == 0)
			if(box[2].m_boxMove == 0)
				boxGen += 1;

	if(boxGen >= 200) // 200���� 1~3�� �ڽ� ���� ����
	{
		Rand = rand() % 3;
		if(Rand == 0)
		{
			box[0].m_boxMove = 1; // (0 �ڽ� ����, 1 �ڽ� ����, 2 �ڽ� ��׷���)
			box[0].m_pt.y = 455;
			box[0].m_pt.x = 1000;
			boxGen = 0;
		}
		else if(Rand == 1)
		{
			box[0].m_boxMove = 1;
			box[0].m_pt.y = 455;
			box[0].m_pt.x = 1000;
			box[1].m_boxMove = 1;
			box[1].m_pt.y = 455;
			box[1].m_pt.x = 1150;
			boxGen = 0;
		}
		else if(Rand == 2)
		{
			box[0].m_boxMove = 1;
			box[0].m_pt.y = 455;
			box[0].m_pt.x = 1000;
			box[1].m_boxMove = 1;
			box[1].m_pt.y = 455;
			box[1].m_pt.x = 1150;
			box[2].m_boxMove = 1;
			box[2].m_pt.y = 455;
			box[2].m_pt.x = 1300;
			boxGen = 0;
		}
	}

	if(box[w].m_boxMove == 1 || box[w].m_boxMove == 2) // �ڽ��� �ʿ� ���� ��
	{
		box[w].m_pt.x -= 7;
		if(box[w].m_pt.x <= -150) // �ڽ��� �ʿ� ������� ���ֱ�
		{
			box[w].m_boxMove = 0;
		}
		if(box[w].m_boxMove == 1)
		{
			if(ball.m_pt.x > (box[w].m_pt.x-100) && ball.m_pt.x < (box[w].m_pt.x+80)) // �ڽ��� ����� ��
			{
				if(ball.m_pt.y >= box[w].m_pt.y)
				{
					ball.m_flag = 0;
					ball.m_jump = 0;
					ball.m_down = 0;
					ball.m_excel = 0;     // Ÿ�̾ �ڽ��� ������� 
					// �ٴڿ� ���� ���·� ���� �ٷ� ������ �� �ְ� �Ѵ�.
				}
			}
			if(ball.m_pt.x > (box[w].m_pt.x-80) && ball.m_pt.x < (box[w].m_pt.x+80)) // �ڽ��� ����� ��
			{
				if(ball.m_pt.y > 350 && ball.m_pt.y < 400)
				{
					if(ball.m_down == 1)
					{
						ball.m_down = 2;
						ball.m_excel = ball.m_jump;
						box[w].m_boxMove = 2;
						box[w].m_dustTime = 2;
					}
				}
			}
		}
	}
	if(box[w].m_boxMove == 2) // �ڽ� ������ �ִϸ��̼�
	{
		box[w].m_dustTime += 1;
		if(box[w].m_dustTime>=2)
			box[w].m_dust = 1;
		if(box[w].m_dustTime>=6)
			box[w].m_dust = 2;
		if(box[w].m_dustTime>=10)
			box[w].m_dust = 3;
		if(box[w].m_dustTime>=14)
			box[w].m_dust = 0;
	}
}

void CChildView :: TireAction()
{
	if(ball.m_move == 1)
	{
		ball.m_pt.x += 7;
		if(ball.m_pt.x >= 400)
		{
			ball.m_move = 2;
		}
	}
	if(ball.m_pt.y >= 455) // ���� �΋H
	{
		if(ball.m_jump <= 0)
		{
			ball.m_jump = 0;
			ball.m_down = 0;
			ball.m_excel = 0;
		}
		else
		{
			ball.m_down = 2;
			ball.m_excel = ball.m_jump; // ������
		}
	}
	if(ball.m_down == 1) // ������
	{
		ball.m_excel += 2;
		ball.m_pt.y += ball.m_excel;
	}
	else if(ball.m_down == 2) // �ö�
	{
		ball.m_excel -= 1.5;
		ball.m_pt.y -= ball.m_excel;

		if(ball.m_excel <= 0) // �ִ���� �ö�
		{
			ball.m_down = 1;
			ball.m_jump -= 8;
		}
	}
	if(ball.m_move == 2) // Ÿ�̾ ����� ���� ��
	{
		mapX += 7;
		mapX2 += 4;
		if (mapX >= 950)
		{
			mapX = 0;
		}
		if (mapX2 >= 950)
		{
			mapX2 = 0;
		}
	}

	if(tireOnoff == 1) // Ÿ�̾� ������ ��
	{
		ball.m_tireTime += 1;
		if(ball.m_tireTime>=2)
			ball.m_tire = 1;
		if(ball.m_tireTime>=4)
			ball.m_tire = 2;
		if(ball.m_tireTime>=6)
			ball.m_tire = 3;
		if(ball.m_tireTime>=8)
			ball.m_tire = 4;
		if(ball.m_tireTime>=10)
			ball.m_tireTime = 1; // Ÿ�̾� ������
	}
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if(ball.m_flag == 0)
	{
		SetTimer(1, 15, NULL);
		ball.m_flag = 1;
	}
	if(ball.m_flag == 1)
	{
		if(ball.m_move == 2)
		{
			if(ball.m_jump == 0)
			{
				ball.m_jump += 32;
			}
		}
	}

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if(ball.m_flag == 1)
	{
		if(ball.m_move == 2)
		{
			ball.m_excel += 30;
			ball.m_down = 1;
		}
	}
	CWnd::OnRButtonDown(nFlags, point);
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	GetClientRect(&ball.m_rect);


	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}