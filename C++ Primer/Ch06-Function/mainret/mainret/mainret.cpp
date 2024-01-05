/*
* C++ Primer - Function (함수)
* 파일명: mainret.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: main에서의 반환 예제
* 이전 버전 내용:
*/

#include <cstdlib> // stdlib.h의 cpp 버전

int main(int argc, const char* argv[])
{
	bool some_failure = false;
	if (some_failure)
		return EXIT_FAILURE; // cstdlib에 정의된 값, 1
	else
		return EXIT_SUCCESS; // cstdlib에 정의된 값, 0
}