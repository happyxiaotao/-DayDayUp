#pragma once

//���ò��鼯�����Թ�
#include "disjsets.h"

struct Pointer
{
	Pointer(int x = 0, int y = 0)
		: _x(x)
		, _y(y)
	{}
	int _x;
	int _y;
};

class Maxe
{
public:
	Maze(int size)
private:
	Pointer enter;
	Pointer out;
	int _size;
};

