/*
* C++ Primer - Expression (표현식)
* 파일명: arraysizeof.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 배열을 대상으로 한 sizeof 연산자 사용 예제
* 이전 버전 내용:
*/

#define CONSTEXPR_VARS

#include <iostream>
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

int ia[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main(int argc, const char* argv[])
{
#ifdef CONSTEXPR_VARS // constexpr을 사용할 경우 (C++11 표준 지원하는 컴파일러 대상)
	constexpr size_t sz = sizeof(ia) / sizeof(*ia);
#else
	const size_t sz = sizeof(ia) / sizeof(*ia);
#endif

	int arr2[sz];

	cout << "ia size: " << sz << endl;

	return 0;
}