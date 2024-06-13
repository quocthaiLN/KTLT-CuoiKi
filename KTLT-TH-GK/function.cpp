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

//char* HocSinhToString(const hocSinh* pHS)
//{
//	char* maSo = new char[demChuSo(pHS->maSo) + 1];
//	maSo[demChuSo(pHS->maSo)] = '\0';
//	_itoa(pHS->maSo, maSo, 10);
//	
//	char* dtb = new char[8];
//	sprintf(dtb, "%lf", pHS->diemTB);
//	dtb[7] = '\0';
//
//	char* outputStr = new char[strlen(pHS->hoTen) + strlen(maSo) + strlen(dtb) + 3 + 2 + 1 + 1];
//	strcpy(outputStr, pHS->hoTen);
//	const char* s1 = " & ", * s2 = " {", * s3 = "}";
//	strcat(outputStr, s1);
//	strcat(outputStr, maSo);
//	strcat(outputStr, s2);
//	strcat(outputStr, dtb);
//	strcat(outputStr, s3);
//	outputStr[strlen(outputStr - 1)] = '\0';
//	return outputStr;
//}



int demChuSo(int n)
{
	int cnt = 0;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	return cnt;
}

void outputHS(hocSinh* pHS)
{
	cout << pHS->maSo << " " << pHS->hoTen << " " << pHS->diemTB << endl;
}

void deleteChar(char* &inputStr, int idx)
{
	int n = strlen(inputStr);
	for (int i = idx; i < n - 1; i++)
	{
		inputStr[i] = inputStr[i + 1];
	}
	inputStr[n - 1] = '\0';
}
char* TrimText(const char* str)
{
	int n = strlen(str);
	char* ans = new char[n + 1];
	strcpy(ans, str);
	for (int i = 1; i < n; i++)
	{
		if (str[i] == ' ' && str[i - 1] == ' ')
		{
			deleteChar(ans, i);
			i--;
			n--;
		}
	}
	return ans;
}

