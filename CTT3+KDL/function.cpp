#include "function.h"

int fnDQ(int n)
{
	if (n == 0)
	{
		return 2;
	}
	else if (n == 1)
	{
		return 3;
	}
	else if (n == 2)
	{
		return 4;
	}
	else
	{
		return 2 * fnDQ(n - 1) + 3 * fnDQ(n - 2) + 4 * fnDQ(n - 3);
	}
}

int fnKDQ(int n)
{
	int fn = 0, f0 = 2, f1 = 3, f2 = 4;
	if (n == 0)
	{
		return f0;
	}
	else if (n == 1)
	{
		return f1;
	}
	else if (n == 2)
	{
		return f2;
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			fn = 2 * f2 + 3 * f1 + 4 * f0;
			f0 = f1;
			f1 = f2;
			f2 = fn;
		}
	}
	return fn;
}


//char* replace(char* src, char* sub, char* rep) {
//	if (src == nullptr) {
//		return nullptr;
//	}
//
//	int srcLen = strlen(src);
//	int subLen = strlen(sub);
//	int repLen = strlen(rep);
//
//	// Đếm số lần xuất hiện của chuỗi con "sub" trong chuỗi "src"
//	int count = 0;
//	char* pos = src;
//	while ((pos = strstr(pos, sub)) != nullptr) {
//		count++;
//		pos += subLen;
//	}
//
//	// Tính kích thước của chuỗi kết quả
//	int resultLen = srcLen + count * (repLen - subLen);
//	char* result = new char[resultLen + 1];
//	result[resultLen] = '\0';
//
//	// Thay thế chuỗi con "sub" bằng chuỗi "rep"
//	char* dest = result;
//	pos = src;
//	while ((pos = strstr(pos, sub)) != nullptr) {
//		int len = pos - src;
//		strncpy(dest, src, len);
//		dest += len;
//		strcpy(dest, rep);
//		dest += repLen;
//		pos += subLen;
//		src = pos;
//	}
//
//	// Sao chép phần còn lại của chuỗi "src"
//	strcpy(dest, src);
//
//	return result;
//}

//char* replace(char* src, char* sub, char* rep)
//{
//	if (src == NULL)
//	{
//		return NULL;
//	}
//	int srcLen = strlen(src), subLen = strlen(sub), repLen = strlen(rep), cnt = 0;
//
//	char* pos = src;
//	while (strstr(pos, sub) != NULL)
//	{
//		cnt++;
//		int len = strstr(pos, sub) - pos;
//		pos += len;
//	}
//
//	char* ans = new char[srcLen + cnt * (repLen - subLen)];
//	ans[srcLen + cnt * (repLen - subLen) - 1] = '\0';
//	char* keep = ans;
//	pos = src;
//	while (strstr(pos, sub) != NULL)
//	{
//		int len = strstr(pos, sub) - pos;
//		strncpy(keep, src, len);
//		keep += len;
//		strcpy(keep, rep);
//		keep += repLen;
//		pos += len + repLen;
//	}
//	strcpy(keep, pos);
//	return ans;
//}