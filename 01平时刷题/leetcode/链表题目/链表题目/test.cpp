
#include <iostream>
//typedef unsigned long uintptr_t;
uintptr_t NXStrHash(const void *data)
{
	uintptr_t hash = 0;
	unsigned char* s = (unsigned char*)data;
	if (s)
		for (; ;)
		{
			if (*s == '\0') break;
			hash ^= (uintptr_t)*s++;
			if (*s == '\0') break;
			hash ^= (uintptr_t)*s++ << 8;
			if (*s == '\0') break;
			hash ^= (uintptr_t)*s++ << 16;
			if (*s == '\0') break;
			hash ^= (uintptr_t)*s++ << 24;
		}
	return hash;
}

int main(int argc, char* argv[])
{
	uintptr_t hashValue = NXStrHash("ab");
	printf("%ld\nn", hashValue);
}