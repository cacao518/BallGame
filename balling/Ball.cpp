#pragma once
#include "stdafx.h"
#include "Ball.h"


Ball::Ball()
{
	m_pt = 0; // 타이어의 좌표 값
	m_seta = 0; // 타이어의 세타 값
	m_move = 1; // 타이어의 x축 이동 (1 오른쪽 이동, 2 타이어는 멈춤, 맵은 이동)
	m_down = 1; // 타이어의 y축 이동 (1 밑으로 떨어짐, 2 위로 솟구침, 0 정지)
	m_flag = 0; // 타이어 클릭 가능 여부
	m_excel = 1; // 타이어 가속도
	m_jump = 30; // 타이어 점프력 
	m_tire = 1; // 타이어 이미지 idx
	m_pt.y = 1; // 타이어 y 값
	m_tireTime = 0; // 타이어 애니메이션 타임
};

Ball::~Ball()
{

};