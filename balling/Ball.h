#pragma once
#include "stdafx.h"

class Ball
{
public:
	CRect m_rect;
	CPoint m_pt; // Ÿ�̾� ��ġ ��
	int m_seta; // Ÿ�̾��� ��Ÿ ��
	int m_move;// Ÿ�̾��� x�� �̵� (1 ������ �̵�, 2 Ÿ�̾�� ����, ���� �̵�)
	int m_down; // Ÿ�̾��� y�� �̵� (1 ������ ������, 2 ���� �ڱ�ħ, 0 ����)
	int m_flag; // Ÿ�̾� Ŭ�� ���� ����
	int m_excel; // Ÿ�̾� ���ӵ�
	int m_jump; // Ÿ�̾� ������ 
	int m_tire; // Ÿ�̾� �̹��� idx
	int m_tireTime;// Ÿ�̾� �ִϸ��̼� Ÿ��

	Ball();
	~Ball();

};
