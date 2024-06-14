#include "function.h"

int main()
{
	const char* fileName = "data.bin";
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
	

	addStudent(data, fileName);

	listSV l1 = initListSV();
	readFile(l1, fileName);
	outputListSV(l1);


	/*const char* fileName = "data.bin";
	listSV l = initListSV();
	inputListSV(l);
	outputListSV(l);
	writeFile(l, fileName);
	
	listSV l1 = initListSV();
	readFile(l1, fileName);
	outputListSV(l1);*/



}