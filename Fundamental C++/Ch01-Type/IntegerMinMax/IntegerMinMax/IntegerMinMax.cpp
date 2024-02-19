/*
* Fundamental C++ - Ch01-Type
* 파일명: IntegerMinMax.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: 비트 연산을 이용한 간단한 최대 최소값 구하기
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

int main()
{
	int i = 1;			// 00000000 00000000 00000000 00000001

	i = (i << 31);		// 10000000 00000000 00000000 00000000 -> signed int의 최솟값
	cout << i << '\n';

	i = ~i;				// 01111111 11111111 11111111 11111111 -> signed int의 최댓값
	cout << i << '\n';

	unsigned ui = 0;	// 00000000 00000000 00000000 00000000 -> unsigned int의 최솟값
	cout << ui << '\n';

	ui = ~ui;			// 11111111 11111111 11111111 11111111 -> unsigned int의 최댓값
	cout << ui << '\n';



	return 0;
}