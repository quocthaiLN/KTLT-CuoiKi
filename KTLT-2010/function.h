#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;
#define MAXNAMELEN 51
#define MAXNAMECLASSLEN 21

struct sinhVien
{
	int id;
	char* name;
	char* className;
	double gpa;
	int birthyear;
};

struct node
{
	sinhVien info;
	node* pNext;
};

struct list
{
	node* pHead, * pTail;
};

list initList();
node* getNode(sinhVien info);
sinhVien inputSV();
list inputList();
void addLast(list& l, sinhVien info);
void outputSV(sinhVien info);
void outputList(list l);
double maxGPA(list l);
sinhVien copySinhVien(sinhVien info);
list maxGPAList(list l);
void swapSV(sinhVien& sv1, sinhVien& sv2);
void sort(list& l);
sinhVien convertingData(char* line);
void writeTextFile(list l, const char* filePath);
void readTextFile(list& l, const char* filePath);
void writeBinaryFile(list l, const char* filePath);
void readBinaryFile(list& l, const char* filePath);

