#pragma once
#include "frame.h"

//������������ ����� ����������� (��, ��� ��������) ����
class FrameMonochrome :
	public frame
{
public:

	FrameMonochrome(const LONG Height, const LONG Width)
		:frame(Height, Width, Width/8, 1, 1)
	{
	}

	~FrameMonochrome()
	{
	}
	void set_pixel(const int x, const int y, const int value)
	{
		//��������� ��������
		int dimens = x*bm.bmWidth + y;//��� ��������� �������������
		BYTE &buf = mBytes[dimens / 8];
		dimens = 7 - dimens % 8;//�� � �������, ������������, ����� ������ ��� ���� ����������
		BYTE mask = ((BYTE)0x1 << dimens) ^ (BYTE) 0xff;//������� ������ ������ ��������
		buf &= mask;
		//� ������ �������� �����
		buf |= ((BYTE)value << dimens);
	}
};

