#include "function.h"

int fnDQ(int n)
{
	if (n == 0)
	{
		return 2;
	}
	else if (n == 1)
	{
		return 3;
	}
	else if (n == 2)
	{
		return 4;
	}
	else
	{
		return 2 * fnDQ(n - 1) + 3 * fnDQ(n - 2) + 4 * fnDQ(n - 3);
	}
}

int fnKDQ(int n)
{
	int fn = 0, f0 = 2, f1 = 3, f2 = 4;
	if (n == 0)
	{
		return f0;
	}
	else if (n == 1)
	{
		return f1;
	}
	else if (n == 2)
	{
		return f2;
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			fn = 2 * f2 + 3 * f1 + 4 * f0;
			f0 = f1;
			f1 = f2;
			f2 = fn;
		}
	}
	return fn;
}


char* replace(char* src, char* sub, char* rep) {
	if (src == nullptr) {
		return nullptr;
	}

	int srcLen = strlen(src);
	int subLen = strlen(sub);
	int repLen = strlen(rep);

	// Đếm số lần xuất hiện của chuỗi con "sub" trong chuỗi "src"
	int count = 0;
	char* pos = src;
	while ((pos = strstr(pos, sub)) != nullptr) {//Tìm vị trí bắt đầu xuất hiện sub, nếu trả về NULL có nghĩa là đã không còn sub ở sau
		count++;//tăng biến đếm
		pos += subLen;//pos đã ở vị trí bắt đầu xuất hiện sub nên cần cộng thêm 1 khoảng sub để tìm phần kế tiếp
	}



	// Tính kích thước của chuỗi kết quả
	int resultLen = srcLen + count * (repLen - subLen);//Kích thước mới bằng count lần độ lệnh
	char* result = new char[resultLen + 1];//Khai báo
	result[resultLen] = '\0';//Chuẩn hóa cuối chuỗi

	// Thay thế chuỗi con "sub" bằng chuỗi "rep"
	char* dest = result;//Khai báo chuỗi kết quả
	pos = src;//Duyệt từ đầu của src
	while ((pos = strstr(pos, sub)) != nullptr) {//Kiểm tra nếu có xuất hiện sub
		int len = pos - src;//lấy khoảng cách xuất hiện với lần đầu hoặc với lần trước đó
		strncpy(dest, src, len);//copy phần trước đó vào dest
		dest += len;//cho dest chạy lên trên
		strcpy(dest, rep);//copy tiếp phần rep
		dest += repLen;//cho dest chạy lên trên
		pos += subLen;//cho pos chạy lên trên tương tự như vòng lặp trên
		src = pos;
	}

	// Sao chép phần còn lại của chuỗi "src"
	strcpy(dest, src);

	return result;
}

//char* replace(char* src, char* sub, char* rep)
//{
//	if (src == NULL)
//	{
//		return NULL;
//	}
//	int srcLen = strlen(src), subLen = strlen(sub), repLen = strlen(rep), cnt = 0;
//
//	char* pos = src;
//	while (strstr(pos, sub) != NULL)
//	{
//		cnt++;
//		int len = strstr(pos, sub) - pos;
//		pos += len;
//	}
//
//	char* ans = new char[srcLen + cnt * (repLen - subLen)];
//	ans[srcLen + cnt * (repLen - subLen) - 1] = '\0';
//	char* keep = ans;
//	pos = src;
//	while (strstr(pos, sub) != NULL)
//	{
//		int len = strstr(pos, sub) - pos;
//		strncpy(keep, src, len);
//		keep += len;
//		strcpy(keep, rep);
//		keep += repLen;
//		pos += len + repLen;
//	}
//	strcpy(keep, pos);
//	return ans;
//}

//int count(List list)
//{
//	//Kiem tra danh sach neu co 1 phan tu hay 0 phan tu thi tra ve 0
//	if (list.head == NULL || list.head->next == NULL)
//	{
//		return 0;
//	}
//	//Khai bao bien dem
//	int cnt = 0;
//	//Khai bao node p duyet qua danh sach
//	Node* p = list.head;
//	while (p->next != NULL)
//	{
//		//So sanh neu bang voi average dang sau thi tang cnt
//		if (p->average == p->next->average)
//		{
//			cnt++;
//		}
//		p = p->next;
//	}
//	//tra ve cnt
//	return cnt;
//}
////Ham copyNode tao ra 1 node chua thong tin tuong tu nhung next la NULL
//
//Node* copyNode(Node* stu)
//{
//	//Kiem tra stu co hop le ko
//	if (stu == NULL)
//	{
//		return NULL;
//	}
//	//Tao node moi p va gan cac gia tri cua node stu vao p
//	Node* p = new Node;
//	p->stuID = stu->stuID;
//	p->average = stu->average;
//	//next cua p tro den NULL
//	p->next = NULL;
//	//tra ve p
//	return p;
//}
//List makeList(List list, int& n)
//{
//	//Kiem tra list co trong hay khong, neu trong thi thoat khoi ham
//	if (list.head == NULL)
//	{
//		exit(0);
//	}
//	//Tao node p de duyet qua list ban dau
//	Node* p = list.head;
//	//So phan tu cua listUnder5
//	n = 0;
//	//Khoi tao listUnder5
//	List listUnder5 = initList();
//	//Duyet qua list
//	while (p != NULL)
//	{
//		//Neu average < 5 thi copy node do vao listUnder5
//		if (p->average < 5.0)
//		{
//			Node* cpyNode = new Node;
//			cpyNode = copyNode(p);
//			addLast(listUnder5, cpyNode);
//			//Tang n
//			n++;
//		}
//		p = p->next;
//	}
//	return listUnder5;
//}
//void writeFailedStudent(List list, int n)
//{
//	//Khai bao ten file
//	string fileName = "data.bin";
//	//Mo o che do ghi file nhi phan
//	ofstream ofs;
//	//Kiem tra mo thanh cong hay khong
//	ofs.open(fileName, ios::binary);
//	if (ofs.is_open() == false)
//	{
//		cout << "Mo tap tin that bai";
//		return;
//	}
//	//ghi n la so sinh viet trong list
//	ofs.write((char*)&n, sizeof(int));
//	//Node p duyet qua list
//	Node* p = list.head;
//	while (p != NULL)
//	{
//		//Ghi stuID
//		ofs.write((char*)&p->stuID, sizeof(int));
//		//Ghi average
//		ofs.write((char*)&p->average, sizeof(double));
//		p = p->next;
//	}
//	ofs.close();
//}