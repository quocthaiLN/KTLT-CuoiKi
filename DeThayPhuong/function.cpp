#include "function.h"


int** tichMaTran(int** a, int** b, int N)
{

	int** ans = alloc(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				ans[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}
	return ans;
}
int** alloc(int N)
{
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
	{
		a[i] = new int[N];
	}
	return a;
}
void input(int**& a, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
}
void output(int** a, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int longestCommonSubsequence(int* A, int nA, int* B, int nB) {


	int** DP = new int* [nA + 1];
	for (int i = 0; i <= nA; i++)
	{
		DP[i] = new int[nB + 1];
	}
	for (int i = 0; i <= nA; i++)
	{
		for (int j = 0; j <= nB; j++)
		{
			DP[i][j] = 0;
		}
	}


	// Xây dựng bảng DP theo công thức đệ quy của LCS
	for (int i = 1; i <= nA; ++i) {
		for (int j = 1; j <= nB; ++j) {
			if (A[i - 1] == B[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	// Kết quả là DP[m][n] là độ dài của LCS của hai chuỗi A và B
	return DP[nA][nB];
}


D[i][j]: "Độ dài chuỗi con dài nhất" tính của A[0 --> i-1] và B[0 --> j-1]
Nếu: A[i-1] == B[j-1] thì độ dài lớn nhất sẽ được cập nhật lại tại D[i][j] là trước đó + 1: D[i][j] = D[i-1][j-1] + 1
Nếu: A[i-1] != B[j-1] thì độ dài lớn nhất sẽ đc chọn giữa 2 giá trị D[i-1][j] và D[i][j-1], điều kiện là chọn max


void input1D(int*& a, int N)
{
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
}

void output1D(int* a, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
}
