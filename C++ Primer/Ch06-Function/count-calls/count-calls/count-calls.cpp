/*
* C++ Primer - Function (함수)
* 파일명: count-calls.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-04
* 이전 버전 작성 일자:
* 버전 내용: static 지역 변수 사용 예제
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

size_t count_calls()
{
	static size_t cnt = 0; // static 변수는 함수가 반환해도 소멸되지 않고 메모리에 남아있게 된다.
	return ++cnt;
}

int main(int argc, const char* argv[])
{
	for (size_t i = 0; i != 10; ++i)
		cout << count_calls() << endl;
	return 0;
}