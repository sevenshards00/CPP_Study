/*
* C++ Primer - Function (함수)
* 파일명: mk_plural.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: 단어를 복수형으로 만드는 예제 - 소스 파일
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "make_plural.h"

int main(int argc, const char* argv[])
{
	size_t cnt = 1;
	cout << make_plural(cnt, "success", "es") << endl;

	cnt = 2;
	cout << make_plural(cnt, "failure", "s") << endl;

	return 0;
}