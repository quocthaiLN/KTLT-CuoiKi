#include "function.h"


int main()
{
	list l = initList();
	inputList(l);
	outputList(l);
	cout << endl;
	cout << isSymmetric(l);


	return 0;



}