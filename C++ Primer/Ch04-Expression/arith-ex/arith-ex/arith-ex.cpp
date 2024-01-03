/*
* C++ Primer - Expression (표현식)
* 파일명: arith-ex.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 간단한 산술 연산자 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	cout << -30 * 3 + 21 / 5 << endl;

	cout << -30 + 3 * 21 / 5 << endl;

	cout << 30 / 3 * 21 % 5 << endl;

	cout << 30 / 3 * 21 % 4 << endl;

	cout << -30 / 3 * 21 % 4 << endl;

	cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;

	return 0;
}