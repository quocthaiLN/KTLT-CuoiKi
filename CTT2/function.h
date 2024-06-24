#pragma once


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;



//Câu 1: 
//- Lỗi ở các dòng: 7, 10
//- Dòng 7: do ở dòng 5 ta cho nextPtr trỏ vào cũng ô nhớ với firstPtr nên khi ta delete 
//firstPtr thì vùng nhớ đó sẽ bị mất, dẫn đến việc delete 1 vùng nhớ không tồn tại và gây lỗi
//- Dòng 10: ở dòng 8 ta vừa cấp phát lại vùng nhớ cho firstPtr và gán giá trị cho vùng nhớ 
//đó ở dòng kế, nhưng nextPtr của ta vẫn chưa được cấp phát và không trỏ đến vùng nhớ nào cả

//void main() {
//	double* firstPtr = new double;
//	double* nextPtr = new double;
//	*firstPtr = 62;
//	
//	delete firstPtr;
//	
//	firstPtr = new double;
//	*firstPtr = 28;
//	nextPtr = firstPtr;
//	cout << *firstPtr << " " << *nextPtr << endl;
//	delete nextPtr;
//	delete firstPtr;
//}

int countNumCharKDQ(char* str);
int countNumCharDQ(char* str);

struct node
{
	int key;
	node* next;
};

struct list
{
	node* pHead, *pTail;
};



void inputList(list& l);
list initList();
node* getNode(int value);
void printList(list l);
void addHead(list& l, int value);
void addLast(list& l, int value);
int sizeList(list l);

//Câu 3:
//a. 35 50
//b. chương trình không xảy ra lỗi và danh sách bớt đi node cuối, node* tail đc giải phóng

node* getMinNode(node* head, node* tail);
node* getMaxNode(node* head, node* tail);
int countNodeBetweenMinMax(node* head, node* tail);


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

int compareStudentID(char* strID1, char* strID2);
void addStudent(sinhVien data, const char* fileName);
void addSort(listSV& l, sinhVien data);
void writeFile(listSV& l, const char* fileName);
void readFile(listSV& l, const char* fileName);

