#pragma once
#include "stdafx.h"

class Box
{
public:
	CPoint m_pt; // �ڽ� ��ġ
	int m_boxMove; // �ڽ� �ִϸ��̼� idx
	int m_dust; // ���� �ִϸ��̼� idx
	int m_dustTime; // ���� �ִϸ��̼� Ÿ��

	Box();
	~Box();

};