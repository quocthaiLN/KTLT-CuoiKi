#pragma once

#include <iostream>
using namespace std;
//ABCD = 0352
//M = 10
//N = 18
//P = 3
//Q = 28

//1AC:
//- p1 trỏ vào x
//- p2 trỏ vào y
//- x = x - 10
//- y = y + 18
//- xuất: 3 + x - 10 + y + 18 = 28 
//- có: x + y = 17, x = 7, y = 10
//
//1AL:
//- X = 10, Y = 18
//- p1 trỏ vào X, p2 trỏ vào Y
//- X = X - P = 7, Y = Y + P = 21
//- Xuất: 28
//
//2BC:
//- Để: X = 5, Y = 3
//- Cho: X = 0, Y = X + F(X)
//- Tìm F(X)

int FxBC(int &x)
{
	x = x + 5;
	return x - 7;
}

//2BL:
//- Để: X = 2, Y = 28
//- Cho:  X = 3, Y = 3 - F(X)

int FxBL(int &x)
{
	x = x - 1;
	return x - 28;

}

//Chú ý chương trình sẽ ưu tiên thực hiện hàm trước mới đến bên ngoài, từ trong ra ngoài


//3CC:
//- Để: Y = 18
//- X = 0, Y = 3
//- p1 trỏ vào X, p2 trỏ vào Y
//- F(p1, p2)
//- Y = X + *p1 - F(p2, p1)

//Câu 4:


