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

bool compareLists(list l1, list l2)
{
	if (sizeList(l1) != sizeList(l2))
	{
		return false;
	}

	node* p1 = l1.pHead, *p2 = l2.pHead;
	while (p1 != NULL)
	{
		if (p1->data != p2->data)
		{
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;


}

bool isSymmetric(list& l)
{
	int size = sizeList(l);
	if (l.pHead == NULL || l.pHead->next == NULL)
	{
		return false;
	}

	list check1 = initList();
	node* p = l.pHead;
	for (int i = 0; i < size / 2; i++)
	{
			addLast(check1, p->data);
			p = p->next;
	}
	if (size % 2 == 1)
	{
		p = p->next;
	}	
	
	list check2 = initList();
	while (p != NULL)
	{
		addLast(check2, p->data);
		p = p->next;
	}

	return compareLists(check1, check2);

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