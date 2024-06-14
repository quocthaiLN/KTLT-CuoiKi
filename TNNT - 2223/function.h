#pragma once


#define _CTR_SECURE_NO_WARININGS 
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <math.h>
using namespace std;

int countDigit(int N);
char* toBitString(int N);


struct node
{
	int data;
	node* next;
};

struct list
{
	node* pHead;
};

bool isSymmetric(list& l);
list initList();
void addHead(list& l, int data);
void addLast(list& l, int data);
void inputList(list& l);
void outputList(list l);
int sizeList(list l);
node* getNode(int data);





