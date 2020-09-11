#pragma once
#pragma once
#include <iostream>
using namespace std;
#define HASHDEL (void*) -1
struct Object
{
	void** data;
	//void** tempArr;
	Object(int, int(*)(void*));
	int size;
	int N;
	int(*getKey)(void*);
	bool insert(void*);
	int searchInd(int key);
	void* search(int key);
	void* deleteByKey(int key);
	bool deleteByValue(void*);
	void scan(void(*f)(void*));
	void checkSize(Object*);
};
static void* DEL = (void*)HASHDEL;
Object create(int size, int(*getkey)(void*));
#undef HASHDEL