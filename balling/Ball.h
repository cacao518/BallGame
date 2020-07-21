#pragma once
#include "stdafx.h"

class Ball
{
public:
	CRect m_rect;
	CPoint m_pt; // 타이어 위치 값
	int m_seta; // 타이어의 세타 값
	int m_move;// 타이어의 x축 이동 (1 오른쪽 이동, 2 타이어는 멈춤, 맵은 이동)
	int m_down; // 타이어의 y축 이동 (1 밑으로 떨어짐, 2 위로 솟구침, 0 정지)
	int m_flag; // 타이어 클릭 가능 여부
	int m_excel; // 타이어 가속도
	int m_jump; // 타이어 점프력 
	int m_tire; // 타이어 이미지 idx
	int m_tireTime;// 타이어 애니메이션 타임

	Ball();
	~Ball();

};
