
// Lab 2Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CLab2Dlg
class CLab2Dlg : public CDialogEx
{
// Создание
public:
	CLab2Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_LAB2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedpaint();
	// метка для вывода киких-то текстовых сообщений о работе
	CString lb_msg;
	//сюда выводятся изображения
	CStatic picture_control;
	//а эта фабрика, она обеспечивает нормальную генерацию кадров
	FrameFactoryBase *ffactory;
};
