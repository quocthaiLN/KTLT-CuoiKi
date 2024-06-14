#include "function.h"


int countDigit(int N)
{
	int cnt = 0;
	while (pow(2, cnt) <= N)
	{
		cnt++;
	}
	return cnt;
}




char* toBitString(int N)
{
	int numDigits = countDigit(N) + 1, i = 0;
	char* str = new char[numDigits];
	str[numDigits - 1] = '\0';
	while (N > 0)
	{
		if (N % 2 == 1)
		{
			str[numDigits - 2 - i] = '1';
		}
		else
		{
			str[numDigits - 2 - i] = '0';
		}
		i++;
		N /= 2;
	}

	return str;
}

void addHead(list& l, int data)
{
	node* p = getNode(data);
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

bool isSymmetric(list& l)
{
	int size = sizeList(l);
	if (l.pHead == NULL || l.pHead->next == NULL)
	{
		return false;
	}

	list l1 = initList();

	node* p = l.pHead;
	for (int i = 0; i < size / 2; i++)
	{
		addHead(l1, p->data);
		p = p->next;
		
	}
	if (size % 2 == 1)
	{
		p = p->next;
	}

	node* q = l1.pHead;
	while (q != NULL)
	{
		if (q->data != p->data)
		{
			return false;
		}
		q = q->next;
		p = p->next;
	}

	return true;
}



list initList()
{
	list l;
	l.pHead = NULL;
	return l;
}
void addLast(list& l, int data)
{
	node* p = getNode(data);
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
void inputList(list& l)
{
	int n;
	cout << "n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		addLast(l, data);
	}
}
void outputList(list l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	else
	{
		node* p = l.pHead;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}

	}
}
int sizeList(list l)
{
	int cnt = 0;
	if (l.pHead == NULL)
	{
		return 0;
	}
	else
	{
		node* p = l.pHead;
		while (p != NULL)
		{
			cnt++;
			p = p->next;
		}

	}
	return cnt;
}
node* getNode(int data)
{
	node* p = new node;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->data = data;
		p->next = NULL;
	}
	return p;
}

//Câu 3 - Liên qua đến lập trình động, thuật toán tham lam, Câu 4 - Chưa làm đã biết khó - quá khó