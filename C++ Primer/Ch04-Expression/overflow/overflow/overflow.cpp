/*
* C++ Primer - Expression (표현식)
* 파일명: overflow.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 산술 오버플로 발생 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	short short_value = 32767; // 부호가 있는 2byte short에서 표현 가능한 양수 최대값

	short_value += 1; // 1를 더하면 산술 오버플로 발생
	cout << "short_value: " << short_value << endl;

	return 0;
}