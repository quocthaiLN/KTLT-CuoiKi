#include "function.h"


char* addString(char* s1, char* s2)
{
	int a = atoi(s1), b = atoi(s2), c = a + b, cnt = countDigit(c);
	char* ans = new char[cnt + 1];
	_itoa(c, ans, 10);
	ans[cnt] = '\0';
	return ans;
}

int countDigit(int N)
{
	int cnt = 0;
	while (N != 0)
	{
		cnt++;
		N /= 10;
	}
	return cnt;
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

void mergeLists(list x, list y, list& z)
{
	node* px = x.pHead, *py = y.pHead;
	while (px != NULL && py != NULL)
	{
		if (px->data < py->data)
		{
			addLast(z, px->data);
			px = px->next;
		}
		else
		{
			addLast(z, py->data);
			py = py->next;
		}
	}
		if (px == NULL && py != NULL)
		{
			while (py != NULL)
			{
				addLast(z, py->data);
				py = py->next;
			}
		}
		else if(py == NULL && px != NULL)
		{
			while(px!= NULL)
			{
				addLast(z, px->data);
				px = px->next;
		}
	}
}


nodeSV* getNodeSV(sinhVien data)
{
	nodeSV* p = new nodeSV;
	if (p == NULL)
	{
		return NULL;
	}
	p->data.ten = new char[maxNameLen];
	p->data.maSo = new char[maxMaSoLen];
	strcpy(p->data.ten, data.ten);
	strcpy(p->data.maSo, data.maSo);
	p->data.maSo = data.maSo;
	p->data.dtb = data.dtb;
	p->pNext = NULL;
	return p;
}

listSV initListSV()
{
	listSV l;
	l.pHead = l.pTail = NULL;
	return l;
}
void addLastListSV(listSV& l, sinhVien data)
{
	nodeSV* p = getNodeSV(data);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void inputListSV(listSV& l)
{
	int n;
	cout << "n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "SV " << i << ": " << endl;
		sinhVien data;
		data.ten = new char[maxNameLen];
		data.maSo = new char[maxMaSoLen];
		cout << "Ten: ";
		cin.ignore();
		cin.getline(data.ten, maxNameLen);
		cout << "Ma so: ";
		cin >> data.maSo;
		cout << "DTB: ";
		cin >> data.dtb;
		addLastListSV(l, data);
	}
}
void outputListSV(listSV l)
{
	nodeSV* p = l.pHead;
	int i = 0;
	while (p != NULL)
	{
		cout << "SV " << i << ": " << p->data.ten << " " << p->data.maSo << " " << p->data.dtb << endl;;
		p = p->pNext;
		i++;
	}
}

void writeFile(listSV l, const char* fileName)
{
	ofstream ofs;
	ofs.open(fileName, ios::binary);
	if (ofs.is_open() == false)
	{
		cout << "Mo file that bai!\n";
		return;
	}
	nodeSV* p = l.pHead;

	while (p != NULL)
	{
		ofs.write((char*)&p->data, sizeof(sinhVien));
		p = p->pNext;
	}

	ofs.close();


}
void readFile(listSV& l, const char* fileName)
{
	ifstream ifs;
	ifs.open(fileName, ios::binary);
	if (ifs.is_open() == false)
	{
		cout << "Mo file that bai!\n";
		return;
	}

	sinhVien data;
	data.ten = new char[maxNameLen];
	data.maSo = new char[maxMaSoLen];
	while (ifs.read((char*)&data, sizeof(sinhVien)))
	{
		addLastListSV(l, data);
	}


	ifs.close();


}