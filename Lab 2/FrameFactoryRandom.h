#pragma once
#include "FrameFactoryBase.h"
#include "FrameMonochrome.h"
class FrameFactoryRandom :
	public FrameFactoryBase
{
private:
	LONG _width;
	LONG _height;
public:

	FrameFactoryRandom(const LONG Height, const LONG Width)
		:_width(Width), _height(Height)
	{
	}
	~FrameFactoryRandom()
	{
	}
	virtual frame* get_frame()
	{
		frame *answer = new FrameMonochrome(_height, _width);
		answer->init_empty_buf();
		srand(std::chrono::system_clock::now().time_since_epoch().count());
		for (int i = 0; i < _height; ++i)
			for (int j = 0; j < _width; ++j)
				answer->set_pixel(i, j, (double)rand() / RAND_MAX * 2);
		return answer;
	}
};

