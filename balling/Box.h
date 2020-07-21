#pragma once
#include "stdafx.h"

class Box
{
public:
	CPoint m_pt; // 박스 위치
	int m_boxMove; // 박스 애니메이션 idx
	int m_dust; // 먼지 애니메이션 idx
	int m_dustTime; // 먼지 애니메이션 타임

	Box();
	~Box();

};