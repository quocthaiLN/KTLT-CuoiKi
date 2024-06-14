#pragma once

#include <iostream>
using namespace std;

struct node
{
	int key;
	node* next;
};

struct list
{
	node* pHead;
};



void inputList(list& l);
list initList();
node* getNode(int value);
void printList(list l);
void addHead(list& l, int value);
void addLast(list& l, int value);
int sizeList(list l);
node* getKthNodeFormTail(list l, int k);

int** allocatedPascalTriangel(int N);
int** createPascalTriangel(int N);
void printPascalTriangel(int** PascalTriangel, int N);

//Tam giác Pascal là nửa ma trận vuông với phần tử đầu tiên và phần tử cuối cùng ở mỗi hàng là 1,
//một phận tử được tính bằng : M(a, b) = M(a - 1, b - 1) + M(a - 1, b);

//Câu 4 + 5 giống đề TNNT





