/*
* Fundamental C++ - Ch01-Type
* 파일명: BitShifting.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: 간단한 비트 연산 이해
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

int main()
{
	char c = 1;		// 00000001

	c = c << 7;		// 10000000
	cout << static_cast<int>(c) << '\n';

	c = c >> 7;		// 11111111 -> 이 부분을 요주의할 것 (절대 00000001이 아니다!)
					// signed 정수에는 절대로 bit shifting 연산을 하면 안된다.
					// 최상위 bit가 1일 경우에는 부호 유지 정책에 의해 1로 쭉 shifting이 되기 때문.
					// 따라서 1을 기대했지만 예상치 못한 값이 나올 수 있다.
	cout << static_cast<int>(c) << '\n';

	return 0;
}