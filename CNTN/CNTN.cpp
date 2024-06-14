#include "function.h"

int main()
{
	/*listSV l = initListSV();
	inputListSV(l);
	outputListSV(l);
	writeFile(l, "data.bin");*/

	listSV l2 = initListSV();
	readFile(l2, "data.bin");
	outputListSV(l2);

	return 0;


}