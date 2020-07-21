// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once
#include "atltypes.h"
#include "Ball.h"
#include "Box.h"


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
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

	int Rand; // 박스 랜덤 생성 
	bool tireOnoff; // 타이어 정지 여부
	int boxGen; // 박스 리젠 시간
	int mapX; // 바닥 배경
	int mapX2; // 뒷 배경

	Ball ball;
	Box box[3];
};

