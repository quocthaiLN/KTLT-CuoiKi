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
		l.pHead = p;
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
	l.pHead = NULL;
	return l;
}

void addLast(list& l, int value)
{
	node* p = getNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		node* q = l.pHead;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}

node* getKthNodeFormTail(list l, int k)
{
	int size = sizeList(l);
	if (l.pHead == NULL || k > size || k <= 0)
	{
		return NULL;
	}
	node* p = l.pHead;
	for (int i = 1;i < size - k + 1; i++)
	{
		p = p->next;
	}
	return p;
}

int** allocatedPascalTriangel(int N)
{
	int** ptr = new int*[N];
	if (ptr == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < N; i++)
	{
		ptr[i] = new int[i + 1];
	}
	return ptr;
}

int** createPascalTriangel(int N)
{
	int** ptr = allocatedPascalTriangel(N);
	for (int i = 0; i < N; i++)
	{
		ptr[i][0] = 1;
		ptr[i][i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			ptr[i][j] = ptr[i - 1][j - 1] + ptr[i - 1][j];
		}
	}
	return ptr;
}

void printPascalTriangel(int** PascalTriangel, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << PascalTriangel[i][j] << " ";
		}
		cout << endl;
	}
}