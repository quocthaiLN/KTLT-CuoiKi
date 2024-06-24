#include "function.h"

node* getNode(char c)
{
	node* p = new node;
	if (p == NULL)
	{
		return NULL;
	}
	p->c = c;
	p->pNext = NULL;
	return p;
}

void addLast(node*& head, char c)
{
	node* p = getNode(c);
	if (head == NULL)
	{
		head = p;
		return;
	}
	
	node* q = head;
	while (q->pNext != NULL)
	{
		q = q->pNext;
	}
	q->pNext = p;
}
void input(node*& head)
{
	int n; 
	cout << "n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char x;
		cin >> x;
		addLast(head, x);
	}
}
void output(node* head)
{
	node* p = head;
	while (p != NULL)
	{
		cout << p->c;
		p = p->pNext;
	}

}
int sizeList(node* head)
{
	int size = 0;
	node* p = head;
	while (p != NULL)
	{
		size++;
		p = p->pNext;
	}
	return size;

}
char* toString(node* head)
{
	char* ans = new char[sizeList(head) + 1];
	node* p = head;
	int i = 0;
	while (p != NULL)
	{
		ans[i] = p->c;
		i++;
		p = p->pNext;
	}
	ans[sizeList(head)] = '\0';
	return ans;
}




//void generate(const char* directors[], int N, int K, bool mask[], int start)
//{
//	if (K == 0) { // Nếu K bằng 0 tức là đã đủ số phần tử cho 1 tập hợp con.
//		for (int i = 0; i < N; ++i) {
//			if (mask[i]) { // Nêú phần tử này đánh dấu đang được sử dụng thì in ra.
//				cout << directors[i] << " ";
//			}
//		}
//		cout << endl;
//	}
//	else {
//		for (int i = start; i < N; ++i) {
//			mask[i] = true; // Đánh dấu phần tử đang được sử dụng.
//			generate(directors, N, K - 1, mask, i + 1); // Gọi đệ quy tại đây.
//			mask[i] = false; // Quay lui tại đây.
//		}
//	}
//}
//bool mask[100] = { 0 };
//int start = 0, idx = 0;
//void generate(const char* dircector[], int N, int K)
//{
//	if (idx == K - 1)
//	{
//		for (int i = 0; i < K; i++)
//		{
//			if (mask[i] == true)
//			{
//				cout << dircector[i] << " ";
//			}
//		}
//		cout << endl;
//	}
//	else
//	{
//		for (int j = start; j < N; j++)
//		{
//			mask[j] = true;
//			idx++;
//			start = j + 1;
//			generate(dircector, N, K);
//			mask[j] = false;
//		}
//	}
//}


