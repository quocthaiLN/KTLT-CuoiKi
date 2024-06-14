#include "function.h"

int main()
{
	int N;
	cin >> N;
	int** ptr = createPascalTriangel(N);
	printPascalTriangel(ptr, N);
	return 0;
}