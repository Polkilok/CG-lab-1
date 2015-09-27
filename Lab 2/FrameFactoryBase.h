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
	//���� ����
	virtual frame* get_frame(){ return nullptr; };
	//�������� ���� �������, �. �. ������ ��� ������� get_frame
	virtual void retire_frame(frame* fr)
	{
		delete fr;
	};
};

