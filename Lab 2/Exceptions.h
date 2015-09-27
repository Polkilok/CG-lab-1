#pragma once
#include <string>//�� ������ ���, ����� �����������

//������� ����� �������� ����� ���������� (����� ������������ ��� ������ ����������!)
class Exceptions
{
	std::string _msg;
public:
	Exceptions(const std::string &msg)
		:_msg(msg)
	{
	}
};

//�������������� ���������� ��� ������ � �������
class FrameExceptions :Exceptions
{
public:
	FrameExceptions(const std::string &msg) :Exceptions(msg){};
};



