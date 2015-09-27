#pragma once
#include <string>//ну просто так, вдруг потребуется

//Базовый класс иерархии наших исключений (можно использовать для вывода информации!)
class Exceptions
{
	std::string _msg;
public:
	Exceptions(const std::string &msg)
		:_msg(msg)
	{
	}
};

//специализирует исключения при работе с кадрами
class FrameExceptions :Exceptions
{
public:
	FrameExceptions(const std::string &msg) :Exceptions(msg){};
};



