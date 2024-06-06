#include "function.h"

double GenerateRandom(const param& param)
{

	double dis = param.max - param.min;
	int n = dis * 1.0 / 0.03125;
	srand(time(NULL));
	int x = rand() % (n + 1);
	double real = x * 0.03125;
	return param.min + real;
}

void ExtractInfo(const char* strInput, char*& pHT, int& pMS)
{
	int size = strlen(strInput), i;
	for (i = 0; i < size; i++)
	{
		if (strInput[i] == '&')
		{
			break;

		}
	}
	pHT = new char[i + 1];
	strncpy(pHT, strInput, i);
	//Chú ý giữa \0 và \n
	pHT[i] = '\0';
	char* temp = new char[size - i + 1];
	strcpy(temp, strInput + i + 1);
	pMS = atoi(temp);
}

hocSinh* CreateHocSinh(const char* strInput, const double& dtbMin, const double& dtbMax)
{
	hocSinh* hs = new hocSinh;
	char* pHT;
	int pMS;
	ExtractInfo(strInput, pHT, pMS);
	hs->hoTen = _strdup(pHT);
	hs->maSo = pMS;
	param pr;
	pr.min = dtbMin;
	pr.max = dtbMax;
	hs->diemTB = GenerateRandom(pr);
	return hs;
}

void FreeHocSinh(hocSinh* pHS)
{
	if (pHS != NULL)
	{
		delete[] pHS->hoTen;
		delete pHS;
	}
}