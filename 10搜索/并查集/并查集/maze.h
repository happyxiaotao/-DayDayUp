#pragma once

//利用并查集生成迷宫
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

