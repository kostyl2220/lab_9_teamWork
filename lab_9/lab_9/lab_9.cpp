// lab_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <conio.h>

const int MAX_LEN = 50;

struct Furniture {
	char name[MAX_LEN];
	char typeMain[MAX_LEN];
	char typeAdd[MAX_LEN];
	char matherial[MAX_LEN];
	char color[MAX_LEN];
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

struct List{
	Furniture data;
	List *next;
};

const int COUNT = 10;

int fillCollection(Furniture *head){
	strcpy(head[0].name,"Victoria");
	strcpy(head[0].typeMain, "Chair");
	strcpy(head[0].typeAdd, " bar");
	strcpy(head[0].matherial, "Wood");
	strcpy(head[0].color, "Black");
	head[0].price = 500;
	head[0].countOfProduct = 16;
	head[0].spec.chair.colorUpholstery = "Red";
	head[0].spec.chair.typeBack = "Huge";
	head[0].spec.chair.typeSeat = "Huge";

	strcpy(head[1].name, "Conqueror");
	strcpy(head[1].typeMain, "Table");
	strcpy(head[1].typeAdd, " computer");
	strcpy(head[1].matherial, "Wood");
	strcpy(head[1].color, "Drak brown");
	head[1].price = 2200;
	head[1].countOfProduct = 7;
	head[1].spec.table.size = 600;
	head[1].spec.table.typeTable = "Rectangle";

	strcpy(head[2].name, "Casual");
	strcpy(head[2].typeMain, "Chair");
	strcpy(head[2].typeAdd, " kitchen");
	strcpy(head[2].matherial, "Steel");
	strcpy(head[2].color, "Gray");
	head[2].price = 160;
	head[2].countOfProduct = 38;
	head[2].spec.chair.colorUpholstery = "None";
	head[2].spec.chair.typeBack = "Little";
	head[2].spec.chair.typeSeat = "Usual";

	strcpy(head[3].name, "Softness");
	strcpy(head[3].typeMain, "Chair");
	strcpy(head[3].typeAdd, " work");
	strcpy(head[3].matherial, "Plastic and scin");
	strcpy(head[3].color, "Black");
	head[3].price = 780;
	head[3].countOfProduct = 3;
	head[3].spec.chair.colorUpholstery = "Brown";
	head[3].spec.chair.typeBack = "Soft";
	head[3].spec.chair.typeSeat = "Soft";

	return 4;
}

void writeToBinaryFile(const char *path, Furniture *furn, int count) {
	FILE *f = fopen(path, "wb");
	fwrite(furn, sizeof(Furniture), count, f);
	fclose(f);
}

int ReadFromBinaryFile(const char *path, Furniture *furn) {
	FILE *f = fopen(path, "rb");
	int i = 0;
	while (!feof(f)){
		fread(furn + i++, sizeof(Furniture), 1, f);
	}
	fclose(f);
	return i - 1;
}

void outCollection(Furniture *furn, int count) {
	for (int i = 0; i < count; ++i) {
		printf("Name: %s\nType: %s%s\nMatherial: %s\nColor: %s\nPrice: %d\nCount of product: %d\n\n",
			furn[i].name, furn[i].typeMain, furn[i].typeAdd, furn[i].matherial, furn[i].color, furn[i].price, furn[i].countOfProduct);
		if (strcmp(furn[i].typeMain, "Chair") == 0) {
			printf("Type of back: %s\nType of seat: %s\nColor of Upholstery: %s\n__________________________________________________\n", 
				furn[i].spec.chair.typeBack, furn[i].spec.chair.typeSeat, furn[i].spec.chair.colorUpholstery);
		}
		if (strcmp(furn[i].typeMain, "Table") == 0) {
			printf("Type of table: %s\nSize of table: %d\n__________________________________________________\n",
				furn[i].spec.table.typeTable, furn[i].spec.table.size);
		}
	}
}

void mainMenu(Furniture *furn){
	int count = 0;
	while (true) {
		printf("Menu:\n");
		printf("\t1.Fill collection\n");
		printf("\t2.Print collection\n");
		printf("\t3.Add element to collection\n");
		printf("\t4.Delete element of collection\n");
		printf("\t5.Editing element of collection\n");
		printf("\t6.First task\n");
		printf("\t7.Second task\n");
		printf("\t8.Third task\n");
		printf("\t9.Read from file\n");
		printf("\t0.Write to file\n");
		printf("\tq.Exit\n");
		char ch = _getch();
		system("cls");
		switch (ch)
		{
		case '1':
			count = fillCollection(furn);
			break;
		case '2':
			outCollection(furn, count);
			break;
		case '9':
			count = ReadFromBinaryFile("input.dat", furn);
			break;
		case '0':
			writeToBinaryFile("input.dat", furn, count);
			break;
		case 'q':
			return;
		default:
			return;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Furniture furn[COUNT];
	mainMenu(furn);
	system("pause");
	return 0;
}

