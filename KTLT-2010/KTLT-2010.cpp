#include "function.h"

int main()
{
	list l;
	l = inputList();
	cout << endl;
	outputList(l);
	cout << endl;
	cout << maxGPA(l) << endl;
	list newL = maxGPAList(l);
	outputList(newL);
	cout << endl;
	sort(l);
	outputList(l);
	cout << endl;
	writeTextFile(l, "data.txt");
	cout << endl;
	list l1;
	readTextFile(l1, "data.txt");
	outputList(l1);
	cout << endl;
	writeBinaryFile(l, "data.bin");
	cout << endl;
	list l2;
	readBinaryFile(l2, "data.bin");
	outputList(l2);
	return 0;


}