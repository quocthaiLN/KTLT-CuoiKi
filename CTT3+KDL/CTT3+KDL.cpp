#include "function.h"

int main()
{
	char* src = new char[100], * sub = new char[100], * rep = new char[100];
	cin >> src;
	cin >> sub;
	cin >> rep;
	cout << replace(src, sub, rep);

	return 0;


}