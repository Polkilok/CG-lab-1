
// Lab 2Dlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� CLab2Dlg
class CLab2Dlg : public CDialogEx
{
// ��������
public:
	CLab2Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_LAB2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedpaint();
	// ����� ��� ������ �����-�� ��������� ��������� � ������
	CString lb_msg;
	//���� ��������� �����������
	CStatic picture_control;
	//� ��� �������, ��� ������������ ���������� ��������� ������
	FrameFactoryBase *ffactory;
};
