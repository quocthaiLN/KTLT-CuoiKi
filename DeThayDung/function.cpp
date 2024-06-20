#include "function.h"

int** AllocMatrix(int m, int a, int b, int c)
{
	int** matrix = new int*[m];
	int cnt = 0;
	while (1)
	{
		matrix[cnt] = new int[a];
		cnt++;
		if (cnt >= m)
		{
			break;
		}

		matrix[cnt] = new int[b];
		cnt++;
		if (cnt >= m)
		{
			break;
		}

		matrix[cnt] = new int[c];
		cnt++;
		if (cnt >= m)
		{
			break;
		}

	}
	return matrix;
}

int** CreateMatrix(int m, int a, int b, int c)
{
	if (a > m || b > m || c > m)
	{
		return NULL;
	}
	int** matrix = AllocMatrix(m, a, b, c);
	int cnt = 0;
	while (1)
	{
		for (int i = 0; i < a; i++)
		{
			matrix[cnt][i] = pow(-1, cnt + i + 1) * (a - i);
		}
		cnt++;
		if (cnt >= m)
		{
			break;
		}
		for (int i = 0; i < b; i++)
		{
			matrix[cnt][i] = pow(-1, cnt + i + 1) * (b - i);
		}
		cnt++;
		if (cnt >= m)
		{
			break;
		}

		for (int i = 0; i < c; i++)
		{
			matrix[cnt][i] = pow(-1, cnt + i + 1) * (c - i);
		}
		cnt++;
		if (cnt >= m)
		{
			break;
		}
	}
	return matrix;
}

void OutputMatrix(int** matrix, int m, int a, int b, int c)
{
	int cnt = 0;
	while (1)
	{
		for (int i = 0; i < a; i++)
		{
			cout << matrix[cnt][i] << " ";
		}
		cout << endl;
		cnt++;
		if (cnt >= m)
		{
			break;
		}
		for (int i = 0; i < b; i++)
		{
			cout << matrix[cnt][i] << " ";
		}
		cout << endl;
		cnt++;
		if (cnt >= m)
		{
			break;
		}

		for (int i = 0; i < c; i++)
		{
			cout << matrix[cnt][i] << " ";
		}
		cout << endl;
		cnt++;
		if (cnt >= m)
		{
			break;
		}
	}
}


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


int countPrime(node* pHead)
{
	if (pHead == NULL)
	{
		return 0;
	}
	else
	{
		return isPrime(pHead->key) + countPrime(pHead->next);
	}
}

bool isPrime(int x)
{
	if (x == 0 || x == 1)
	{
		return false;
	}
	if (x == 2)
	{
		return true;
	}

	for (int i = 2; i <= x / 2; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
