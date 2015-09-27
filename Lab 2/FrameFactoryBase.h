#pragma once
#include "frame.h"
class FrameFactoryBase
{
public:

	FrameFactoryBase()
	{
	}

	~FrameFactoryBase()
	{
	}
	//дает кадр
	virtual frame* get_frame(){ return nullptr; };
	//забирает кадр обратно, д. б. вызван для каждого get_frame
	virtual void retire_frame(frame* fr)
	{
		delete fr;
	};
};

