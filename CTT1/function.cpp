#include "function.h"

void inputList(list& l)
{
	int n;
	cin >> n;
	l = initList();
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		addLast(l, value);
	}
}
node* getNode(int value)
{
	node* p = new node;
	if (p == NULL)
	{
		return NULL;
	}
	p->key = value;
	p->next = NULL;
	return p;
}
void printList(list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->next;
	}
}
void addHead(list& l, int value)
{
	node* p = getNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->next = l.pHead;
		l.pHead = p;
	}
}
int sizeList(list l)
{
	int cnt = 0;
	node* p = l.pHead;
	while (p != NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

list initList()
{
	list l;
	l.pHead = l.pTail = NULL;
	return l;
}

void addLast(list& l, int value)
{
	node* p = getNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->next = p;
		l.pTail = p;
	}
}


bool checkList(node* head, int &distance ,bool(*condition)(int, int, int))
{
	if (head->next->next == NULL)
	{
		distance = head->key - head->next->key;
		return true;
	}
	else
	{
		return checkList(head->next, distance, condition) && condition(head->key, head->next->key, distance);
		//Để distance check kia đằng sau để sau khi chạy đến cuối mới quay lại
	}
}
bool tangDeu(int val1, int val2, int distance)
{
	if (val1 - val2 == distance && val1 < val2) return true;
	else return false;
}
bool giamDeu(int val1, int val2, int distance)
{
	if (val1 - val2 == distance && val1 > val2) return true;
	else return false;
}


int Tn(int x, int p, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x % p;
	}
	else
	{
		return (2 * x * Tn(x, p, n - 1) % p) - (Tn(x, p, n - 2) % p);
	}
}
