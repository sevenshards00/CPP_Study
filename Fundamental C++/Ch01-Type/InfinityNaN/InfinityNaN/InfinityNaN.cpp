/*
* Fundamental C++ - Ch01-Type
* 파일명: InfinityNaN.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: float를 이용한 무한(INF)와 NaN(Not a Number) 출력 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

int main()
{
	// 양의 무한
	// 0111 1111 1000 0000 0000 0000 0000 0000 -> 0x7F800000
	unsigned ui1 = 0x7F800000;
	// 음의 무한
	// 1111 1111 1000 0000 0000 0000 0000 0000 -> 0xFF800000
	unsigned ui2 = 0xFF800000;
	// -NaN
	// 1111 1111 1111 1111 1111 1111 1111 1111 -> 0xFFFFFFFF
	unsigned ui3 = 0xFFFFFFFF;
	// NaN
	// 0111 1111 1111 1111 1111 1111 1111 1111 -> 0x7FFFFFFF
	unsigned ui4 = 0x7FFFFFFF;
	
	float f1;
	float f2;
	float f3;
	float f4;

	memcpy(&f1, &ui1, sizeof(f1));
	memcpy(&f2, &ui2, sizeof(f2));
	memcpy(&f3, &ui3, sizeof(f3));
	memcpy(&f4, &ui4, sizeof(f4));

	cout << f1 << '\n';			// 양의 무한
	cout << f1 + f1 << '\n';	// 양의 무한
	cout << f2 << '\n';			// 음의 무한
	cout << f2 + f2 << '\n';	// 음의 무한
	cout << f1 + f2 << '\n';	// 양의 무한 + 음의 무한 = 미정의(NaN)

	cout << f3 << '\n';			// 미정의(-NaN)
	cout << f3 + f3 << '\n';	// 미정의(-NaN)
	cout << f4 << '\n';			// 미정의(NaN)
	cout << f4 + f4 << '\n';	// 미정의(NaN)
	cout << f3 + f4 << '\n';	// -NaN + NaN = 미정의(-NaN)
	return 0;
}