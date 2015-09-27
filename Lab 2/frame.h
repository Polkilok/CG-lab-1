#pragma once
#include "stdafx.h"
class frame
{
protected:
	//параметры для работы с битовой картой
	BITMAP bm;
	//специально отдельно вынесенный указатель на массив байтов, который потребуется для работы с рисунком
	BYTE *mBytes;
	//хендл пикчи, которая будет созданна перед отображением кадра
	HBITMAP picture;

public:
	//WidthBytes - количесво байтов в 1 строке изображения, кратно 2
	//BitsPixel - количесвто битов на пиксель, степнь 2
	//Planes - количество планов
	frame(const LONG Height, const LONG Width, const LONG WidthBytes, const WORD BitsPixel, const WORD Planes)
		:mBytes(nullptr), picture(nullptr)
	{
		if (WidthBytes % 2 != 0)
			throw FrameExceptions("WidthBytes % 2 != 0");//Хотя кидать исключения в конструкторе плохой тон, но здесь это необходимо для ловли багов
		else
			bm.bmWidthBytes = WidthBytes;
		//Этот параметр всегда такой
		bm.bmType = 0;
		bm.bmHeight = Height;
		bm.bmWidth = Width;
		bm.bmBitsPixel = BitsPixel;
		bm.bmPlanes = Planes;
	}
	//Копировать фреймы - плохо!
	//P. S. временно плохо
	frame(const frame &anther) = delete;
	~frame()
	{
		delete mBytes;
	}
	//копирует предлеженный массив в буфер (заменяя прошлые значения)
	void set_buf(const BYTE *mas, const int size)
	{
		if (size != bm.bmWidth * bm.bmHeight * bm.bmBitsPixel / 8)
		{
			throw FrameExceptions("Bad size of mas for frame");
		}
		delete mBytes;//удаляем старый массив
		mBytes = new BYTE[size];
		for (int i = 0; i < size; i++)
		{
			mBytes[i] = mas[i];
		}
	}
	//выводит кадр в указанный объект (не забудьте его обновить!)
	void show_picture(CStatic &PictureControl)
	{
		//втыкаем ссылку на массив, представляющий собой изображение
		bm.bmBits = mBytes;
		picture = CreateBitmapIndirect(&bm);
		if (!picture)
			throw FrameExceptions("Пикча не создалась");
		PictureControl.SetBitmap(picture);
	}
	//устанавливает значение пикселя с указанными координатами
	virtual void set_pixel(const int x, const int y, const int value)
	{
		throw FrameExceptions("Вызов чисто виртуальной функции");
	};
};

