// balling.h : balling ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CballingApp:
// �� Ŭ������ ������ ���ؼ��� balling.cpp�� �����Ͻʽÿ�.
//

class CballingApp : public CWinApp
{
public:
	CballingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CballingApp theApp;