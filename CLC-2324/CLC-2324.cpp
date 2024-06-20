
#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;


int* ansIdx = new int[10];
int i = -1, N, K;
void generateIdx(int i)
{
	for (int j = ansIdx[i - 1] + 1; j < N - K + i; i++)
	{
		ansIdx[i] = j;
		if (i == N - 1)
		{
			for (int x = 0; x < K; x++)
			{

			}
			
		}
		else
		{
			generateIdx(++i);
		}
	}
}

char* ans[50];
void generate(const char* direction[], int N, int K)
{
	generateIdx(i);


}