/*
* Fundamental C++ - Ch01-Type
* 파일명: Float.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: 부동 소수점 타입의 비트 배열 표현
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

int main()
{
	unsigned ui1 = 0xC11B0000;							// 1(부호) 10000010(지수) 00110110000000000000000(가수)
	unsigned ui2 = 0b11000001000110110000000000000000;	// 1(부호) 10000010(지수) 00110110000000000000000(가수)
														// 1100(C) 0001(1) 0001(1) 1011(B) 0000(0) 0000(0) 0000(0) 0000(0)

	float f1;
	float f2;
	memcpy(&f1, &ui1, sizeof(f1));
	memcpy(&f2, &ui2, sizeof(f2));
	cout << f1 << '\n';
	cout << f2 << '\n';
	return 0;
}