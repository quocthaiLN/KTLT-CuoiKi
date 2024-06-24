#include "function.h"

//int n, k;
//int a[1005], c[1005]; // mang c de in dap an
//bool b[1005]; // mang danh dau phan tu thu i da duoc su dung hay chua
//void backtrack(int i) {
//    if (i > k) {
//        for (int j = 1; j <= k; j++)
//            cout << c[j] << " ";
//        cout << endl;
//        return;
//    }
//    for (int j = 1; j <= n; j++) // mo hinh quay lui, cac kha nang co the chon cua phan tu thu i
//        if (b[j] == false) // phan tu thu j chua duoc su dung
//        {
//            c[i] = a[j];
//            b[j] = true; // danh dau phan tu thu j da duoc su dung
//            backtrack(i + 1);
//            b[j] = false; // quay lui, bo danh dau phan tu j
//        }
//
//}
//int main() {
//    cin >> n >> k;
//    for (int i = 1; i <= n; i++)
//        cin >> a[i];
//    for (int i = 1; i <= n; i++)
//        b[i] = false;
//    backtrack(1);
//    return 0;
//}

int idx = 0, step = 0;
const char* director[] = { "Mark", "Tim", "Alan", "Bella" };
bool used[10] = { 0 };
char* ans[10];

void generate(const char* dircector[], int N, int K)
{
	if (idx == K)
	{
		for (int i = 0; i < K; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	for (int i = step + 1; i < N; i++)
	{
		if (used[i] == false)
		{
			ans[idx] = _strdup(dircector[i]);
			used[i] = true;
			idx++;
			generate(dircector, N, K);
			idx--;
			free(ans[idx]);
			used[i] = false;
			
		}
	}
}


int main()
{
	int K = 2, N = 4;
	generate(director, N, K);
}


