/*
* C++ Primer - Expression (표현식)
* 파일명: unaryOps.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 단항 연산자 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int i = 1024;
	int k = -i;

	bool b = true;
	bool b2 = -b; // 마찬가지로 true, 0이 아니므로.

	cout << b << " " << b2 << " " << endl;
}