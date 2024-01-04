/*
* C++ Primer - Function (함수)
* 파일명: mainmath.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-04
* 이전 버전 작성 일자:
* 버전 내용: 간단한 함수 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include "LocalMath.h"

int main(int argc, const char argv[])
{
	// 리터럴(상수값)을 함수의 인자로 전달한 경우
	int f = fact(5);
	cout << "5! is " << f << endl;

	// 변수를 함수의 인자로 전달한 경우
	int i = 5;
	int j = fact(i);
	cout << i << "! is " << j << endl;

	// const, 상수화한 변수를 함수의 인자로 전달한 경우
	const int ci = 3;
	int k = fact(ci);
	cout << ci << "! is " << k << endl;

	return 0;
}