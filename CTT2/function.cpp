#include "function.h"

int countNumCharKDQ(char* str)
{
	int size = strlen(str), cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			cnt++;
		}
	}
	return cnt;
}


int countNumCharDQ(char* str)
{
	int cnt = 0;
	if (str == nullptr || str[0] == '\0')
	{
		return cnt;
	}
	else
	{
		if (str[0] >= '0' && str[0] <= '9')
		{
			cnt++;
		}
		return cnt + countNumCharDQ(str + 1);
	}
//	if (str == nullptr || *str == '\0') {
//		// Base case: reached the end of the string
//		return 0;
//	}
//	else if (*str >= '0' && *str <= '9') {
//		// If the current character is a digit, count it
//		return 1 + countNumCharDQ(str + 1);
//	}
//	else {
//		// Otherwise, skip to the next character
//		return  countNumCharDQ(str + 1);
//	}
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

node* getMinNode(node* head, node* tail)
{
	if (head == NULL)
	{
		return NULL;
	}
	node* minNode = head;
	node* p = head->next;
	while (p != NULL)
	{
		if (p->key < minNode->key)
		{
			minNode = p;
		}
		p = p->next;
	}
	return minNode;
}
node* getMaxNode(node* head, node* tail)
{
	if (head == NULL)
	{
		return NULL;
	}
	node* maxNode = head;
	node* p = head->next;
	while (p != NULL)
	{
		if (p->key > maxNode->key)
		{
			maxNode = p;
		}
		p = p->next;
	}
	return maxNode;
}

int countNodeBetweenMinMax(node* head, node* tail)
{
	int cnt = 0;
	node* p = head;
	while (p != NULL)
	{
		if (p == getMaxNode(head, tail) || p == getMinNode(head, tail)) break;
		p = p->next;
	}

	while (p != NULL)
	{
		p = p->next;
		if (p == getMaxNode(head, tail) || p == getMinNode(head, tail)) break;
		cnt++;
	}
	return cnt;
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

int compareStudentID(char* strID1, char* strID2)
{
	for (int i = 0; i < strlen(strID1); i++)
	{
		if (strID1[i] < strID2[i])
		{
			return -1;
		}
		else if (strID1[i] > strID2[i])
		{
			return 1;
		}
	}
	return 0;
}

//Câu 4:
//b. Tập tin nhị phân lưu trữ thông tin theo từng khối dữ liệu của mỗi sinh viên cụ thể, mỗi khối dữ liệu này có kích thước là: 51 + 9 + 8 = 68 byte liên tục, sau khi kết thúc khối dữ liệu này
//thì khối dữ liệu của sinh viên kế sẽ bắt đầu

//Câu 5:
//- Dung lượng lưu trữ trong bộ nhớ RAM: sử dụng mảng động sẽ tối ưu hơn vì không cần tốn thêm bộ nhớ cho con trỏ để lưu node tiếp theo như dánh sách liên kết
//- Chi phí thực hiện tính năng thêm sinh viên: sử dụng danh sách liên kết sẽ tối ưu hơn vì ta chỉ cần tìm đến vị trí phù hợp sau đó thay đổi các liên kết để thêm sinh viên
//(đối với danh sách liên kết), còn với mảng động ta cần phải cấp phát thêm vùng nhớ, di chuyển cả vùng nhớ chứa dữ liệu ID của sinh viên lớn hơn sinh viên cần thêm rồi mới thêm vào được
//- Số lần truy cập tập tin: cả 2 cách sử dụng đều tương đương nhau vì ta mở tập tin đọc sau đó là thao tác thêm sinh viền rồi ghi lại vào file


void addSort(listSV& l, sinhVien data)
{
	nodeSV* p = getNodeSV(data);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}

	

	/*while (cur != NULL)
	{
		if (compareStudentID(cur->data.maSo, p->data.maSo) == 1)
		{
			prev->pNext = p;
			p->pNext = cur;
			break;
		}
		prev = cur;
		cur = cur->pNext;
	}*/

	if (compareStudentID(p->data.maSo, l.pHead->data.maSo) == -1)
	{
		p->pNext = l.pHead;
		l.pHead = p;
		return;
	}

	nodeSV* cur = l.pHead;
	nodeSV* prev = NULL;
	while (compareStudentID(cur->data.maSo, p->data.maSo) == -1)
	{
		prev = cur;
		cur = cur->pNext;
	}

	prev->pNext = p;
	p->pNext = cur;

}

void addStudent(sinhVien data, const char* fileName)
{
	listSV l = initListSV();

	readFile(l, fileName);

	addSort(l, data);

	writeFile(l, fileName);


}

void writeFile(listSV& l, const char* fileName)
{
	ofstream ofs;
	ofs.open(fileName, ios::binary);
	if (ofs.is_open() == false)
	{
		cout << "Ghi file khong thanh cong!";
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
		cout << "Doc file khong thanh cong!";
		return;
	}

	sinhVien info;
	while (ifs.read((char*)&info, sizeof(sinhVien)))
	{
		addLastListSV(l, info);
	}
	ifs.close();
}



