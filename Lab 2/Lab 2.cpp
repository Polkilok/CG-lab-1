
// Lab 2.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "Lab 2.h"
#include "Lab 2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab2App

BEGIN_MESSAGE_MAP(CLab2App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// �������� CLab2App

CLab2App::CLab2App()
{
	// ��������� ���������� ������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}


// ������������ ������ CLab2App

CLab2App theApp;


// ������������� CLab2App

BOOL CLab2App::InitInstance()
{
	// InitCommonControlsEx() ��������� ��� Windows XP, ���� ��������
	// ���������� ���������� ComCtl32.dll ������ 6 ��� ����� ������� ������ ��� ���������
	// ������ �����������.  � ��������� ������ ����� ��������� ���� ��� �������� ������ ����.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �������� ���� �������� ��� ��������� ���� ����� ������� ����������, ������� ���������� ������������
	// � ����� ����������.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ������� ��������� ��������, � ������, ���� ���������� ���� ��������
	// ������������� ������ �������� ��� �����-���� ��� �������� ����������.
	CShellManager *pShellManager = new CShellManager;

	// ��������� ����������� ���������� "������������ Windows" ��� ��������� ��������� ���������� MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ���������
	// ���������� �������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	SetRegistryKey(_T("��������� ����������, ��������� � ������� ������� ����������"));

	CLab2Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ������� ��� ��� ��������� �������� ����������� ����
		//  � ������� ������ "��"
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ������� ��� ��� ��������� �������� ����������� ����
		//  � ������� ������ "������"
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "��������������. �� ������� ������� ���������� ����, ������� ������ ���������� ���������� ���������.\n");
		TRACE(traceAppMsg, 0, "��������������. ��� ������������� ��������� ���������� MFC ��� ����������� ���� ���������� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// ������� ��������� ��������, ��������� ����.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ��������� ���������� ���� �������, ���������� �������� FALSE, ����� ����� ���� ����� ��
	//  ���������� ������ ������� ���������� ��������� ����������.
	return FALSE;
}

