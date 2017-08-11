#include "ALLoc.hpp"

void Test();

int main()
{
	Test();

	system("pause");
	return 0;
}

void Test()
{
	Simple_Alloc<int, _Alloc> simple;

	simple.Allocate(sizeof(int));

	simple.Allocate(sizeof(int)*19);

	simple.Allocate(sizeof(int)*1);
}