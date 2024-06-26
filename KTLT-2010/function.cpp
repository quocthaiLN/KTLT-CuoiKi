#include "function.h"


list initList()
{
	list l;
	l.pHead = l.pTail = NULL;
	return l;
}
node* getNode(sinhVien info)
{
	node* p = new node;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->info.name = _strdup(info.name);
		p->info.className = _strdup(info.className);
		p->info.birthyear = info.birthyear;
		p->info.gpa = info.gpa;
		p->info.id = info.id;
		p->pNext = NULL;
	}
	return p;
}
sinhVien inputSV()
{
	sinhVien sv;
	sv.name = new char[MAXNAMELEN];
	sv.className = new char[MAXNAMECLASSLEN];
	cout << "ID: ";
	cin >> sv.id;
	cout << "Name: ";
	cin.ignore();
	cin.getline(sv.name, MAXNAMELEN);
	cout << "Class name: ";
	//cin.ignore();
	cin.getline(sv.className, MAXNAMECLASSLEN);
	cout << "GPA: ";
	cin >> sv.gpa;
	cout << "Born year: ";
	cin >> sv.birthyear;
	return sv;
}
list inputList()
{
	int  n;
	cin >> n;
	list l = initList();
	for (int i = 0; i < n; i++)
	{
		cout << "Number " << i << ": \n";
		sinhVien sv = inputSV();
		addLast(l, sv);
	}
	return l;
}
void addLast(list& l, sinhVien info)
{
	node* p = getNode(info);
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
void outputSV(sinhVien info)
{
	cout << "ID: " << info.id << endl;
	cout << "Name: " << info.name << endl;
	cout << "Class name: " << info.className << endl;
	cout << "GPA: " << info.gpa << endl;
	cout << "Born year: " << info.birthyear << endl;
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
			outputSV(p->info);
			p = p->pNext;
		}
	}
}

double maxGPA(list l)
{
	if (l.pHead == NULL)
	{
		return -1;
	}
	else
	{
		node* maxNode = l.pHead;
		node* p = maxNode->pNext;
		while (p != NULL)
		{
			if (maxNode->info.gpa < p->info.gpa)
			{
				maxNode = p;
			}

			p = p->pNext;
		}
		return maxNode->info.gpa;
	}
}

sinhVien copySinhVien(sinhVien info)
{
	sinhVien newSV;
	newSV.name = new char[MAXNAMELEN];
	newSV.className = new char[MAXNAMECLASSLEN];
	/*newSV.name = _strdup(info.name);
	newSV.className = _strdup(info.className);*/
	strcpy(newSV.name, info.name);
	strcpy(newSV.className, info.className);
	newSV.gpa = info.gpa;
	newSV.birthyear = info.birthyear;
	newSV.id = info.id;
	return newSV;
}

list maxGPAList(list l)
{
	list newL = initList();
	node* p = l.pHead;
	double maxgpa = maxGPA(l);
	while (p != NULL)
	{
		if (p->info.gpa == maxgpa)
		{
			sinhVien info = copySinhVien(p->info);
			addLast(newL, info);
		}
		p = p->pNext;
	}
	return newL;
}

void swapSV(sinhVien& sv1, sinhVien& sv2)
{
	sinhVien temp = copySinhVien(sv1);
	sv1 = copySinhVien(sv2);
	sv2 = copySinhVien(temp);
}

void sort(list& l)
{
	if (l.pHead == NULL || l.pHead->pNext == NULL)
	{
		return;
	}
	node* p = l.pHead;
	while (p != NULL)
	{
		node* minNode = p;
		node* q = p->pNext;
		while (q != NULL)
		{
			if (minNode->info.gpa > q->info.gpa)
			{
				minNode = q;
			}
			q = q->pNext;
		}
		swapSV(p->info, minNode->info);
		p = p->pNext;
	}
}
void writeTextFile(list l, const char* filePath)
{
	ofstream ofs;
	ofs.open(filePath);
	if (ofs.is_open() == false)
	{
		cout << "Mo file khong thanh cong!\n";
		return;
	}

	node* p = l.pHead;
	while (p != NULL)
	{
		ofs << p->info.id;
		ofs << ',';
		ofs << p->info.name;
		ofs << ',';
		ofs << p->info.gpa;
		ofs << ',';
		ofs << p->info.className;
		ofs << ',';
		ofs << p->info.birthyear;
		ofs << endl;
		p = p->pNext;
	}
	ofs.close();
}

void readTextFile(list& l, const char* filePath)
{
	ifstream ifs;
	ifs.open(filePath);
	if (ifs.is_open() == false)
	{
		cout << "Mo file khong thanh cong!";
		return;
	}
	l = initList();
	while (ifs.eof() == false)
	{
		char* line = new char[100];
		ifs >> line;
		sinhVien sv = convertingData(line);
		addLast(l, sv);
	}
	ifs.close();
}

sinhVien convertingData(char* line)
{
	const char* seperate = ",";
	sinhVien sv;
	sv.className = new char[MAXNAMECLASSLEN];
	sv.name = new char[MAXNAMELEN];


	char* temp = strtok(line, seperate);
	sv.id = atoi(temp);

	sv.name = strtok(NULL, seperate);
	
	temp = strtok(NULL, seperate);
	sv.gpa = strtod(temp, NULL);

	sv.className = strtok(NULL, seperate);

	temp = strtok(NULL, seperate);
	sv.birthyear = atoi(temp);

	return sv;

}

void writeBinaryFile(list l, const char* filePath)
{
	ofstream ofs;
	ofs.open(filePath, ios::binary);
	if (ofs.is_open() == false)
	{
		cout << "Mo file khong thanh cong!\n";
		return;
	}

	node* p = l.pHead;
	while (p != NULL)
	{
		ofs.write((char*)&p->info, sizeof(sinhVien));
		p = p->pNext;
	}
	ofs.close();
}
void readBinaryFile(list& l, const char* filePath)
{
	ifstream ifs;
	ifs.open(filePath, ios::binary);
	if (ifs.is_open() == false)
	{
		cout << "Mo file khong thanh cong!\n";
		return;
	}
	l = initList();
	while (ifs.good())
	{
		sinhVien sv;
		ifs.read((char*)&sv, sizeof(sinhVien));
		addLast(l, sv);
	}
	ifs.close();
}

int tongDayDeQuy(int a, int n)
{
	if (n == 0)
	{
		return a;
	}
	else if (n == 1)
	{
		return 2 * a;
	}
	else
	{
		return 2 * tongDayDeQuy(a, n - 1) + 3 * tongDayDeQuy(a, n - 2);
	}
}

int tongDayKhongDeQuy(int a, int n)
{
	int sum = 0, f0 = a, f1 = 2 * a;
	if (n == 1)
	{
		return f1;
	}
	else if (n == 0)
	{
		return f0;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			sum = 2 * f1 + 3 * f0;
			f0 = f1;
			f1 = sum;
		}
	}
	return sum;
}

int timN(int a, int M)
{
	int n = 0;
	for (n; tongDayDeQuy(a, n) < M; n++);
	return n;
}

int* inputArr(int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Arr[" << i << "]: ";
		cin >> arr[i];
	}
	return arr;
}

void outputArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Arr[" << i << "]: " << arr[i] << endl;
	}
}

void findNum(int* arr, int n, int& a, int& b)
{
	a = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > a)
		{
			a = arr[i];
		}
	}

	b = arr[n - 2];
	for (int i = n - 2; i > 0; i--)
	{
		if (arr[i] > b && arr[i] < a)
		{
			b = arr[i];
		}
	}
}




