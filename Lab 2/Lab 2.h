
// Lab 2.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CLab2App:
// � ���������� ������� ������ ��. Lab 2.cpp
//

class CLab2App : public CWinApp
{
public:
	CLab2App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CLab2App theApp;