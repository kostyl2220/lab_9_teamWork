// lab_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

const int MAX_LEN = 50;

struct sizes{
	int height;
	int lenght;
	int width;
};

struct Furniture { //terrble homunkyl structure with union that consists structure in structure. 
	char name[MAX_LEN];  //name of item
	char typeMain[MAX_LEN]; //main type table or Chair (It's for choosing union fields)
	char typeAdd[MAX_LEN];  //additional field (kitchen or work or bar item)
	char matherial[MAX_LEN];	//matherial that was used making it. Be sure that your table wasn't made in China with using unnatural elements.
	char color[MAX_LEN]; //color of your item. Let's work without pink colors, ok?
	int price;  //it's price of item
	int amountOfProduct;  //count (amount) of product that is on stock
	union {
		struct {  //structure for chair
			char typeBack[MAX_LEN];  //type of back of chair
			char typeSeat[MAX_LEN];  //type of seat of chair
			char colorUpholstery[MAX_LEN];  // color of that... I am tired to write. If third guy of our team read's it. Come to me, I'll give you a candle. Ginger princess, you is the best <3 :*
		} chair;
		struct //structure for table
		{
			char typeTable[MAX_LEN];  //type of table (I used direct in my task)
			sizes size;  //sizes described before homunkyl
		} table;
	} spec;
};

struct List{  //we can delete it, but I can't kill my child
	Furniture data;
	List *next;
};

const int COUNT = 10;

void mainMenu(Furniture*); //all prototypes placed in right sequence 
int fillCollection(Furniture*);  //all of them placed under main
void outCollection(Furniture*, int);  //find yours enpty
void addElement(Furniture*, int&);  //end fill it
void deleteElement(Furniture*, int&);  //for Nastya I will coment all system commands
void editElement(Furniture*, int);
void firstTask(Furniture*, int);
void secondTask(Furniture*, int);
void thirdTask(Furniture*, int);
int ReadFromBinaryFile(Furniture *furn);
void writeToBinaryFile(const char*, Furniture *furn, int count);
void outElement(Furniture*, int);
bool empty(int);


//_____________________________________MAIN METHOD______________________________________


int _tmain(int argc, _TCHAR* argv[])  //short main method
{
	Furniture furn[COUNT]; //Lets leave all jokes about "short" :(
	mainMenu(furn);
	system("pause");//and my English																					  //COMENTED SYSTEM
	return 0;//I hope, nobody died while I was writing it.
}


//_____________________________________________ADDITIONAL METHODS_____________________________


void mainMenu(Furniture *furn){ //menu with points
	int count = 0;
	while (true) {
		printf("\nMenu:\n");
		printf("\t1.Fill collection\n");
		printf("\t2.Print collection\n");
		printf("\t3.Add element to collection\n"); //TODO...
		printf("\t4.Delete element of collection\n");//TODO...
		printf("\t5.Editing element of collection\n");//TODO-
		printf("\t6.First task\n");
		printf("\t7.Second task\n");//TODO
		printf("\t8.Third task\n");  //TODODODOOOOOOO... TODODODO (it's song) you should do 5 tasks above
		printf("\t9.Read from file\n");
		printf("\t0.Write to file\n");
		printf("\tq.Exit\n");
		char ch = _getch();	
		system("cls");																				  //COMENTED SYSTEM
		switch (ch)
		{
		case '1':
			count = fillCollection(furn);  //and add your cases there
			break;
		case '2':
			if (!empty(count)) outCollection(furn, count); //with your methods
			break;
		case '3':
			addElement(furn, count);
			break;
		case '4':
			if (!empty(count)) deleteElement(furn, count);
			break;
		case '5':
			if (!empty(count)) editElement(furn, count);
			break;
		case '6':
			if (!empty(count)) firstTask(furn, count);
			break;
		case '7':
			if (!empty(count)) secondTask(furn, count);
			break;
		case '8':
			if (!empty(count)) thirdTask(furn, count); //Good like
			break;
		case '9':
			count = ReadFromBinaryFile(furn);//and organise prototypes (Forgot this word)
			break;
		case '0':
			if (!empty(count)) writeToBinaryFile(NULL, furn, count);//pleeeease
			break;
		default:
			printf("End of work\n\n");
			writeToBinaryFile("result.dat", furn, count);
			return;
		}
	}
}

int fillCollection(Furniture *head){ //method for filling collection, my own examples if you, Nastya, cause I sure that Valentin won't read it,
	//want to scange some names, you are welcome, but don't touch one table, we must have it for my task.
	//add new items for your one

	strcpy(head[0].name, "Victoria");
	strcpy(head[0].typeMain, "Chair");
	strcpy(head[0].typeAdd, "bar");
	strcpy(head[0].matherial, "Wood");
	strcpy(head[0].color, "Black");
	head[0].price = 500;
	head[0].amountOfProduct = 16;
	strcpy(head[0].spec.chair.colorUpholstery, "Red"); //F
	strcpy(head[0].spec.chair.typeBack, "Huge");
	strcpy(head[0].spec.chair.typeSeat, "Huge");

	strcpy(head[1].name, "Conqueror");//I
	strcpy(head[1].typeMain, "Table");
	strcpy(head[1].typeAdd, "computer");
	strcpy(head[1].matherial, "Wood");
	strcpy(head[1].color, "Dark brown");
	head[1].price = 2200;
	head[1].amountOfProduct = 7;
	head[1].spec.table.size.height = 88;//L
	head[1].spec.table.size.width = 70;
	head[1].spec.table.size.lenght = 170;
	strcpy(head[1].spec.table.typeTable, "Direct");

	strcpy(head[2].name, "Casual");
	strcpy(head[2].typeMain, "Chair");//L
	strcpy(head[2].typeAdd, "kitchen");
	strcpy(head[2].matherial, "Steel");
	strcpy(head[2].color, "Gray");
	head[2].price = 160;
	head[2].amountOfProduct = 38;
	strcpy(head[2].spec.chair.colorUpholstery, "None");
	strcpy(head[2].spec.chair.typeBack, "Little");
	strcpy(head[2].spec.chair.typeSeat, "Usual");//I

	strcpy(head[3].name, "Softness");
	strcpy(head[3].typeMain, "Chair");
	strcpy(head[3].typeAdd, "work");
	strcpy(head[3].matherial, "Plastic and skin");//N
	strcpy(head[3].color, "Black");
	head[3].price = 300;
	head[3].amountOfProduct = 3;
	strcpy(head[3].spec.chair.colorUpholstery, "Red");
	strcpy(head[3].spec.chair.typeBack, "Soft");
	strcpy(head[3].spec.chair.typeSeat, "Soft");

	return 4;//G
}

void outCollection(Furniture *furn, int count) { // out collection
	printf("Collection:\n\n");
	for (int i = 0; i < count; ++i) {
		outElement(furn, i);
	}
}

void addElement(Furniture* furn, int &count) {
	if (count < MAX_LEN) {
		cout << "Input features of product you want to add.\n";

		char name_new[MAX_LEN];
		cout << "name: ";
		cin >> name_new;
		strcpy(furn[count].name, name_new);

		char main_new[MAX_LEN];
		cout << "Chair or Table? : ";
		cin >> main_new;
		strcpy(furn[count].typeMain, main_new);

		char type_new[MAX_LEN];
		cout << "type: ";
		cin >> type_new;
		strcpy(furn[count].typeAdd, type_new);

		char matherial_new[MAX_LEN];
		cout << "material: ";
		cin >> matherial_new;
		strcpy(furn[count].matherial, matherial_new);

		char color_new[MAX_LEN];
		cout << "color: ";
		cin >> color_new;
		strcpy(furn[count].color, color_new);

		int price_new;
		cout << "price: ";
		cin >> price_new;
		furn[count].price = price_new;

		int amount_new;
		cout << "amount: ";
		cin >> amount_new;
		furn[count].amountOfProduct = amount_new;

		if (!strcmp(main_new, "Chair")) {

			char color2_new[MAX_LEN];
			cout << "color of Upholstery: ";
			cin >> color2_new;
			strcpy(furn[count].spec.chair.colorUpholstery, color2_new);

			char back_new[MAX_LEN];
			cout << "type of back: ";
			cin >> back_new;
			strcpy(furn[count].spec.chair.typeBack, back_new);

			char seat_new[MAX_LEN];
			cout << "type of seat: ";
			cin >> seat_new;
			strcpy(furn[count].spec.chair.typeSeat, seat_new);

		}

		else {
			char tableType_new[MAX_LEN];
			cout << "type of Table: ";
			cin >> tableType_new;
			strcpy(furn[count].spec.table.typeTable, tableType_new);
		}

		count++;
	}

	else {
		cout << "\nThere is no space anymore. \n";
	}
	system("pause");
	system("cls");

}

void deleteElement(Furniture* furn, int &count) {
	int num;
	printf("What element would you like to remove?");
	scanf("%d", &num);
	num--;
	count--;
	for (int i = num; i < count; ++i) {
		furn[i] = furn[i + 1];
	}
}

void editElement(Furniture* furn, int count) {
	int element;
	outCollection(furn, count);
	printf("\nEnter the number of element that you want to edit: ");
	scanf("%d", &element);
	--element;
	system("cls");																				  //COMENTED SYSTEM
	if ((element >= 0) && (element < count))
	{
		outElement(furn, element);
		printf("Enter Name: ");
		scanf("%s", &furn[element].name);
		printf("Enter Chair or Table: ");
		scanf("%s", &furn[element].typeMain);
		printf("Enter Type: ");
		scanf("%s", &furn[element].typeAdd);
		printf("Enter Matherial: ");
		scanf("%s", &furn[element].matherial);
		printf("Enter Color: ");
		scanf("%s", &furn[element].color);
		printf("Enter Price: ");
		scanf("%d", &furn[element].price);
		printf("Enter Count of product: ");
		scanf("%d", &furn[element].amountOfProduct);
		if (strcmp(furn[element].typeMain, "Chair") == 0) {
			printf("Enter Type of back: ");
			scanf("%s", &furn[element].spec.chair.typeBack);
			printf("Enter Type of seat: ");
			scanf("%s", &furn[element].spec.chair.typeSeat);
			printf("Enter Color of Upholstery: ");
			scanf("%s", &furn[element].spec.chair.colorUpholstery);
		}
		if (strcmp(furn[element].typeMain, "Table") == 0) {
			printf("Enter Type of table: ");
			scanf("%s", &furn[element].spec.table.typeTable);
			printf("Enter Size of table: \n");
			printf("Enter Height: ");
			scanf("%d", &furn[element].spec.table.size.height);
			printf("Enter Width: ");
			scanf("%d", &furn[element].spec.table.size.width);
			printf("Enter Lenght: ");
			scanf("%d", &furn[element].spec.table.size.lenght);
		}
	}
	else {
		printf("You entered incorrect count\n");
		system("pause");
	}
	system("cls");																				  //COMENTED SYSTEM
}

void firstTask(Furniture *furn, int count) {
	outCollection(furn, count);
	printf("\nFirst task.\n\n");
	printf("Enter the type of chair: ");
	char type[MAX_LEN];
	int count_chairs = 0;
	int price_chairs = 0;
	gets_s(type);
	for (int i = 0; i < count; ++i) {
		if ((strcmp(furn[i].typeMain, "Chair") == 0) &&
			(strcmp(furn[i].typeAdd, type) == 0)) {
			count_chairs += furn[i].amountOfProduct;
			price_chairs += furn[i].price;
		}
	}
	printf("Count of %s chairs is: %d\n", type, count_chairs);
	printf("Price of %s chairs is: %d\n", type, price_chairs);
}

void secondTask(Furniture* furn, int count){
	printf("Second task.\n\n");
	for (int i = 0; i < count; ++i) {
		if (!strcmp(furn[i].typeMain, "Chair") &&
			!strcmp(furn[i].spec.chair.typeBack, "Soft") &&
			!strcmp(furn[i].spec.chair.typeSeat, "Soft") &&
			!strcmp(furn[i].spec.chair.colorUpholstery, "Red") &&
			furn[i].price >= 100 && furn[i].price <= 500) {
			outElement(furn, i);
		}
	}
	printf("\n");
	system("pause");
	system("cls");
}

void thirdTask(Furniture *furn, int count){ //My task, I dont want to discuss it
	printf("Third task.\n");  // or want
	printf("Enter the name of new file: ");
	char path[MAX_LEN]; //hihi
	gets_s(path);
	strcat(path, ".dat");  //enter the name of file
	printf("\n");
	outCollection(furn, count);  //out collection to choose proper size of table
	printf("\nEnter the size of needing tables (height, width, lenght):\n"); //choose proper size of table
	sizes size;
	scanf("%d%d%d", &size.height, &size.width, &size.lenght);

	FILE *f = fopen(path, "wb"); //opening
	for (int i = 0; i < count; ++i) {
		if ((strcmp(furn[i].typeMain, "Table") == 0) && //HUUUUUUUUUUUU
			(strcmp(furn[i].spec.table.typeTable, "Direct") == 0) && //GEEEEEEEEE
			(strcmp(furn[i].typeAdd, "computer") == 0) &&
			furn[i].spec.table.size.height == size.height &&  //Condition
			furn[i].spec.table.size.width == size.width &&
			furn[i].spec.table.size.lenght == size.lenght) { //dont read it
			fwrite(furn + i, sizeof(Furniture), 1, f); //write one element to file
		}
	}
	fclose(f); //close file
}

int ReadFromBinaryFile(Furniture *furn) {  //for reading
	printf("Enter the name of file: ");  // four 
	char path[MAX_LEN];					//lines
	gets_s(path);							//to enter
	strcat(path, ".dat");				//the name

	FILE *f = fopen(path, "rb");  //opening
	int i = 0;
	while (!feof(f)){  //while not end
		fread(furn + i++, sizeof(Furniture), 1, f);  //read
	}
	fclose(f); //close
	system("cls");																				  //COMENTED SYSTEM
	return i - 1;  //return the size with little feature. Dont ask. It works
}

void writeToBinaryFile(const char* path, Furniture *furn, int count) {  //method to write data to new BINARY (Wooooow!!!! Fantastic!!1) file
	if (path == NULL) {
		printf("Enter the name of file: ");  // four 
		char path2[MAX_LEN];					//lines
		gets_s(path2);							//to enter
		strcat(path2, ".dat");				//the name
		path = path2;
	}
	FILE *f = fopen(path, "wb");	//opening
	fwrite(furn, sizeof(Furniture), count, f);  //writing
	fclose(f); //closing
	system("cls");																				  //COMENTED SYSTEM
}  //fantastic, right?


void outElement(Furniture* furn, int i) {
	printf("Name: %s\nType: %s %s\nMatherial: %s\nColor: %s\nPrice: %d\nCount of product: %d\n\n",
		furn[i].name, furn[i].typeMain, furn[i].typeAdd, furn[i].matherial, furn[i].color, furn[i].price, furn[i].amountOfProduct); //for both items the same
	if (strcmp(furn[i].typeMain, "Chair") == 0) {
		printf("Type of back: %s\nType of seat: %s\nColor of Upholstery: %s\n__________________________________________________\n",   //if item is a CHAIR
			furn[i].spec.chair.typeBack, furn[i].spec.chair.typeSeat, furn[i].spec.chair.colorUpholstery);
	}
	if (strcmp(furn[i].typeMain, "Table") == 0) {
		printf("Type of table: %s\nSize of table:\n\tHeight: %d\n\tWidth: %d\n\tLenght: %d\n__________________________________________________\n", //if item is a TABLE
			furn[i].spec.table.typeTable, furn[i].spec.table.size.height, furn[i].spec.table.size.width, furn[i].spec.table.size.lenght);
	}
}

bool empty(int count){
	if (count == 0) {
		printf("Collection is empty, please fill it before using\n");
		system("pause");																				  //COMENTED SYSTEM
		system("cls");																				  //COMENTED SYSTEM
		return true;
	}
	return false;
}

