#include "function.h"

int main()
{
	int n, a, b, * arr = inputArr(n);
	outputArr(arr, n);
	findNum(arr, n, a, b);
	cout << a << " " << b;
	return 0;


}










//int main()
//{
//	int a, n;
//	cin >> a;
//	cin >> n;
//
//	cout << tongDayKhongDeQuy(a, n) << endl;
//	cout << tongDayDeQuy(a, n) << endl;
//	cout << timN(a, tongDayDeQuy(a, n+1));
//	return 0;
//}

//int main()
//{
//	list l;
//	l = inputList();
//	cout << endl;
//	outputList(l);
//	cout << endl;
//	cout << maxGPA(l) << endl;
//	list newL = maxGPAList(l);
//	outputList(newL);
//	cout << endl;
//	sort(l);
//	outputList(l);
//	/*cout << endl;
//	writeTextFile(l, "data.txt");
//	cout << endl;*/
//	/*list l1;
//	readTextFile(l1, "data.txt");
//	outputList(l1);*/
//	cout << endl;
//	writeBinaryFile(l, "data.bin");
//	cout << endl;
//	list l2;
//	readBinaryFile(l2, "data.bin");
//	//outputList(l2);
//	/*ifstream ifs;
//	ifs.open("data.txt");
//	char* line = new char[100];
//	ifs >> line;
//	sinhVien sv = convertingData(line);
//	outputSV(sv);
//
//	ifs >> line;
//	sinhVien sv2 = convertingData(line);
//	outputSV(sv2);*/
//	outputList(l2);
//	return 0;
//}