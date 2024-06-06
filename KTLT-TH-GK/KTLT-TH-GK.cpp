#include "function.h"


int main()
{
	char* pHT = NULL;
	int pMS = 0;
	const char* strInput = "Le Nguyen Quoc Thai&23120352";
	ExtractInfo(strInput, pHT, pMS);
	cout << pHT << " " << pMS;
	return 0;
}


