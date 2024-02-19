/*
* Fundamental C++ - Ch01-Type
* 파일명: RightBitShifting.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: 오른쪽으로 비트 시프트 연산하는 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

int main()
{
	// 부호 있는 정수 타입
	char c = 0x02;	// 0000 0010 == 2
	c = c >> 1;		// 0000 0001 == 1
	cout << static_cast<int>(c) << '\n';

	c = 0x82;		// 1000 0010 == -126
	c = c >> 1;		// 1100 0001 == -63
	cout << static_cast<int>(c) << '\n';

	// 부호 없는 정수 타입
	unsigned char uc = 0x02;	// 0000 0010 == 2
	uc = uc >> 1;				// 0000 0001 == 1
	cout << static_cast<int>(uc) << '\n';

	uc = 0x82;					// 1000 0010 == 130
	uc = uc >> 1;				// 0100 0001 == 65
	cout << static_cast<int>(uc) << '\n';
	
	return 0;
}