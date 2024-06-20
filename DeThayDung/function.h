#pragma once

#include <math.h>
#include <iostream>
using namespace std;
//Bài nay sử dụng phương pháp backtracking để tìm
//ý tưởng:
//Sử dụng một hàm để tìm bội số max
// sử dụng hàm còn lại dựa vào bội số đó để tìm
//input
//mảng giá tri-số phần tử-giá trị càn tính tổng-vị trí bắt đầu tính tổng-biến đếm giá trị-biến dếm max-tổng
//hàm này có tác dụng để dếm coi bộ số bao nhiêu là nhiều nht ví dụ ở đề thì có 2 bội số là 2 và 3 thì 3 là max
void findCountMax(int price[], int n, int m, int start, int& count, int& countMax, int& s)
{
	//nếu tổng lại bằng với giá trị m ban đầu thì chuyển nếu count> count max thì chuyển qua
	if (s == m)
	{
		if (count > countMax)
		{
			countMax = count;
		}
		return;
	}
	for (int i = start; i < n; i++)
	{
		if (price[i] + s <= m)
		{
			s = s + price[i];
			count++;
			findCountMax(price, n, m, i + 1, count, countMax, s);
			//backtracking
			s = s - price[i];
			count--;
		}
	}
}
//input mảng giá trị-số phần tử-giá trị cần tính tổng-vị trí bắt đầu tính tổng-biến đém-biến đếm max-biển tổng-mảng để lưu kế quả-số phần tử
void findNumber(int price[], int n, int m, int start, int& count, int& countMax, int& s, int result[100], int& nResult)
{
	//dựa vào count max ở hàm trên đưa xuống thì nếu count==count max là để tìm cho bội số lớn nhất
	//và dk s==m là khi tổng bằng thì mới in ra
	if (count == countMax && s == m)
	{
		//in các bội số
		cout << "{";
		for (int i = 0; i < nResult; i++)
		{
			cout << result[i];
			if (i != nResult - 1)
			{
				cout << ",";
			}
		}
		cout << "}";
		cout << endl;
		return;
	}
	for (int i = start; i < n; i++)
	{
		if (price[i] + s <= m)
		{
			s = s + price[i];
			count++;
			result[nResult] = i;
			nResult++;
			findNumber(price, n, m, i + 1, count, countMax, s, result, nResult);
			//backtracking
			s = s - price[i];
			count--;
			nResult--;
		}
	}
}
void print(int price[], int n, int m)
{
	int count = 0;
	int countMax = 0;
	int s = 0;
	findCountMax(price, n, m, 0, count, countMax, s);
	count = 0;
	s = 0;
	int result[100];
	int nResult = 0;
	findNumber(price, n, m, 0, count, countMax, s, result, nResult);
}

int** AllocMatrix(int m, int a, int b, int c);
int** CreateMatrix(int m, int a, int b, int c);
void OutputMatrix(int** matrix, int m, int a, int b, int c);



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
int countPrime(node* pHead);
bool isPrime(int x);

//Câu 5:
//-Hàm testing có chức năng hoán đổi giá trị của 2 giá trị a và b;
//-Bước đầu khai báo x = 5, y = 10
//-Hoán đổi giá trị của x và y --> x = 10, y = 5
//-Xuất x = 10
//-Giảm y đi 2 --> x = 10, y = 3
//-Khai báo con trỏ z trỏ vào vùng nhớ lưu giá trị y
//-z++ dịch chuyển con trỏ sang 4 byte 
//-Xuất y = 3 và giảm y đi 1 --> y = 2 
//-Xuất *z là giá trị rác
//-Dịch chuyển z về trước 4 byte --> z trỏ và vùng nhớ lưu giá trị y, xuất địa chỉ của z đang lưu tức
//địa chỉ ô nhớ chứa giá trị y

//Bài toán mua đồ












