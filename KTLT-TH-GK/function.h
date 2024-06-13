#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


struct hocSinh
{
	char* hoTen;
	int maSo;
	double diemTB;
};

struct param
{
	double min, max;
};

double GenerateRandom(const param& param);
void ExtractInfo(const char* strInput, char*& pHT, int& pMS);
hocSinh* CreateHocSinh(const char* strInput, const double& dtbMin, const double& dtbMax);
void FreeHocSinh(hocSinh* pHS);
//char* HocSinhToString(const hocSinh* pHS);
int demChuSo(int n);
void outputHS(hocSinh* pHS);
void deleteChar(char* &inputStr, int idx);
char* TrimText(const char* str);

