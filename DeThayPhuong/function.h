#pragma once

#include <iostream>
using namespace std;


int** tichMaTran(int** a, int** b, int N);
int** alloc(int N);
void input(int**& a, int N);
void output(int** a, int N);

#include <vector>
#include <algorithm>

// Hàm tính độ dài của dãy con chung dài nhất (LCS) sử dụng Dynamic Programming
int longestCommonSubsequence(int* A, int nA, int* B, int nB);
void input1D(int*& a, int N);
void output1D(int* a, int N);

