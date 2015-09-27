#pragma once
#include "frame.h"

//представляет собой монохромный (ЧБ, без градаций) кадр
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
		//некоторое смещение
		int dimens = x*bm.bmWidth + y;//для линейного представления
		BYTE &buf = mBytes[dimens / 8];
		dimens = 7 - dimens % 8;//ну и остаток, показывающий, какой именно бит надо установить
		BYTE mask = ((BYTE)0x1 << dimens) ^ (BYTE) 0xff;//сначало удалим старое значение
		buf &= mask;
		//а теперь поставим новое
		buf |= ((BYTE)value << dimens);
	}
};

