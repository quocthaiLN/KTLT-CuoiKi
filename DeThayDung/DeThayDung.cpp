#include "function.h"

int main()
{
	/*int y = 5;
	cout << y << endl;
	cout << --y << endl;
	cout << y++ << endl;
	cout << y;*/
	int y = 5;
	int* z = &y;
	++z;
	z--;
	cout << *z;
	return 0;


}