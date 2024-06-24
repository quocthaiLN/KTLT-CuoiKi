#pragma once



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

char* addString(char* s1, char* s2);
int countDigit(int N);

struct node
{
	int data;
	node* next;
};

struct list
{
	node* pHead;
};

node* getNode(int data);
int sizeList(list l);
void outputList(list l);
void inputList(list& l);
void addLast(list& l, int data);

list initList();
void addHead(list& l, int data);

void mergeLists(list x, list y, list& z);

#define maxNameLen 51
#define maxMaSoLen 9

struct sinhVien
{
	char* maSo;
	char* ten;
	double dtb;
};

struct nodeSV
{
	sinhVien data;
	nodeSV* pNext;
};

struct listSV
{
	nodeSV* pHead, * pTail;
};

nodeSV* getNodeSV(sinhVien data);
listSV initListSV();
void addLastListSV(listSV& l, sinhVien data);
void inputListSV(listSV& l);
void outputListSV(listSV l);

void writeFile(listSV l, const char* fileName);
void readFile(listSV& l, const char* fileName);










