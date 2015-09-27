#pragma once
#include "stdafx.h"
class frame
{
protected:
	//��������� ��� ������ � ������� ������
	BITMAP bm;
	//���������� �������� ���������� ��������� �� ������ ������, ������� ����������� ��� ������ � ��������
	BYTE *mBytes;
	//����� �����, ������� ����� �������� ����� ������������ �����
	HBITMAP picture;

public:
	//WidthBytes - ��������� ������ � 1 ������ �����������, ������ 2
	//BitsPixel - ���������� ����� �� �������, ������ 2
	//Planes - ���������� ������
	frame(const LONG Height, const LONG Width, const LONG WidthBytes, const WORD BitsPixel, const WORD Planes)
		:mBytes(nullptr), picture(nullptr)
	{
		if (WidthBytes % 2 != 0)
			throw FrameExceptions("WidthBytes % 2 != 0");//���� ������ ���������� � ������������ ������ ���, �� ����� ��� ���������� ��� ����� �����
		else
			bm.bmWidthBytes = WidthBytes;
		//���� �������� ������ �����
		bm.bmType = 0;
		bm.bmHeight = Height;
		bm.bmWidth = Width;
		bm.bmBitsPixel = BitsPixel;
		bm.bmPlanes = Planes;
	}
	//���������� ������ - �����!
	//P. S. �������� �����
	frame(const frame &anther) = delete;
	~frame()
	{
		delete mBytes;
	}
	//�������� ������������ ������ � ����� (������� ������� ��������)
	void set_buf(const BYTE *mas, const int size)
	{
		if (size != bm.bmWidth * bm.bmHeight * bm.bmBitsPixel / 8)
		{
			throw FrameExceptions("Bad size of mas for frame");
		}
		delete mBytes;//������� ������ ������
		mBytes = new BYTE[size];
		for (int i = 0; i < size; i++)
		{
			mBytes[i] = mas[i];
		}
	}
	//������� ���� � ��������� ������ (�� �������� ��� ��������!)
	void show_picture(CStatic &PictureControl)
	{
		//������� ������ �� ������, �������������� ����� �����������
		bm.bmBits = mBytes;
		picture = CreateBitmapIndirect(&bm);
		if (!picture)
			throw FrameExceptions("����� �� ���������");
		PictureControl.SetBitmap(picture);
	}
	//������������� �������� ������� � ���������� ������������
	virtual void set_pixel(const int x, const int y, const int value)
	{
		throw FrameExceptions("����� ����� ����������� �������");
	};
};

