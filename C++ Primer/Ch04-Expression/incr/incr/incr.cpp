/*
* C++ Primer - Expression (표현식)
* 파일명: incr.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 증감 연산자 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int i = 0, j;
	j = ++i; // 전위 증가, j = 1, i = 1이 된다.
	cout << i << " " << j << endl;

	j = i++; // 후위 증가, j = 1, i = 2가 된다.
	cout << i << " " << j << endl;

	return 0;
}