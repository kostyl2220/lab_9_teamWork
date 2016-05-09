// lab_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Furniture {
	char *name;
	char *typeMain;
	char *typeAdd;
	char *matherial;
	char *color;
	int price;
	int countOfProduct;
	union {
		struct {
			char *typeBack;
			char *typeSeat;
			char *colorUpholstery;
		} chair;
		struct
		{
			char *typeTable;
			int size;
		} table;
	} spec;
};

union hallo {
	int a;
	double b;
};

int _tmain(int argc, _TCHAR* argv[])
{

	system("pause");
	return 0;
}

