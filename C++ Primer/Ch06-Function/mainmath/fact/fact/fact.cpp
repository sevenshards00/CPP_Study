/*
* C++ Primer - Function (함수)
* 파일명: fact.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-04
* 이전 버전 작성 일자:
* 버전 내용: 재귀를 이용한 팩토리얼 함수 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include "LocalMath.h"

int main()
{
	cout << factorial(5) << endl; // 재귀 사용, 5!
	cout << fact(5) << endl; // 재귀 미사용, 5!
	cout << factorial(0) << endl; // 재귀 사용, 0!
	cout << fact(0) << endl; // 재귀 미사용, 0!

	return 0;
}