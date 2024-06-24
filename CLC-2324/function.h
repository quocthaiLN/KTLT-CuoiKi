#pragma once

#include <iostream>
using namespace std;

struct node
{
	char c;
	node* pNext;
};

node* getNode(char c);
void addLast(node*& head, char c);
void input(node*& head);
void output(node* head);
int sizeList(node* head);
char* toString(node* head);

/* Ý tưởng của bài này là sử dụng thuật toán quay lui (backtracking)
để in ra các tập hợp với số lượng phần tử yêu cầu*/
// bool mask[] : mảng kiểu boolean này dùng để dánh dấu các phần tử có đang được sử dụng hay không.
//void generate(const char* directors[], int N, int K, bool mask[], int start = 0);



//bool mask[];
//extern int idx, i;
//void generate(const char* dircector[], int N, int K);









