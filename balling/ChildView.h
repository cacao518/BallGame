// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include "atltypes.h"
#include "Ball.h"
#include "Box.h"


// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void BoxAction(int w);
	void TireAction();

	int Rand; // �ڽ� ���� ���� 
	bool tireOnoff; // Ÿ�̾� ���� ����
	int boxGen; // �ڽ� ���� �ð�
	int mapX; // �ٴ� ���
	int mapX2; // �� ���

	Ball ball;
	Box box[3];
};

