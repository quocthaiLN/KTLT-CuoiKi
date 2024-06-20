#include "function.h"

void hailstone(int i);
void hailstone(int i)
{
	if (i == 1)
	{
		cout << i;
		return;
	}
	else
	{
		if (i % 2 == 0)
		{
			cout << i << " ";
			hailstone(i / 2);
		}
		else
		{
			cout << i << " ";
			hailstone(i * 3 + 1);
		}
	}
}

int main() {
	int A[] = { 1, 3, 0, 9, 1 };
	int nA = 5;
	int B[] = { 1, 3, 0, 9, 5 };
	int nB = 5;

	int lengthLCS = longestCommonSubsequence(A, nA, B, nB);
	std::cout << "Do dai cua day con chung dai nhat (LCS) la: " << lengthLCS << std::endl;

	return 0;
}
