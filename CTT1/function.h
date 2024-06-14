#pragma once
#include <math.h>
#include <iostream>
using namespace std;

//Câu 1, câu 2 khó có khả năng cho thi khi thầy Dũng không đề cập
//Câu 3:

struct node
{
	int key;
	node* next;
};

struct list
{
	node* pHead, * pTail;
};

void inputList(list& l);
list initList();
node* getNode(int value);
void printList(list l);
void addHead(list& l, int value);
void addLast(list& l, int value);
int sizeList(list l);

bool checkList(node* head, int &distance,bool(*condition)(int, int, int));
bool tangDeu(int val1, int val2, int distance);
bool giamDeu(int val1, int val2, int distance);
int Tn(int x, int p, int n);


