/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: find-str.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: string 컨테이너에서 find 연산 사용 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char argv[])
{
	string name("AnnaBelle");
	auto pos1 = name.find("Anna");
	cout << pos1;
	string lowercase("annabelle");
	pos1 = lowercase.find("Anna"); // 대소문자를 구분한다. 결과적으로는 찾지 못하므로 pos1 == npos
	cout << " " << pos1 << endl;
}