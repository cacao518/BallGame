#pragma once
#include "stdafx.h"
#include "Ball.h"


Ball::Ball()
{
	m_pt = 0; // Ÿ�̾��� ��ǥ ��
	m_seta = 0; // Ÿ�̾��� ��Ÿ ��
	m_move = 1; // Ÿ�̾��� x�� �̵� (1 ������ �̵�, 2 Ÿ�̾�� ����, ���� �̵�)
	m_down = 1; // Ÿ�̾��� y�� �̵� (1 ������ ������, 2 ���� �ڱ�ħ, 0 ����)
	m_flag = 0; // Ÿ�̾� Ŭ�� ���� ����
	m_excel = 1; // Ÿ�̾� ���ӵ�
	m_jump = 30; // Ÿ�̾� ������ 
	m_tire = 1; // Ÿ�̾� �̹��� idx
	m_pt.y = 1; // Ÿ�̾� y ��
	m_tireTime = 0; // Ÿ�̾� �ִϸ��̼� Ÿ��
};

Ball::~Ball()
{

};