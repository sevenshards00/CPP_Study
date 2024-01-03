/*
* C++ Primer - Expression (표현식)
* 파일명: oofe.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 간단한 함수 오버로딩 예제
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cctype>
using std::toupper;

string& tolower(string& s)
{
	for (auto& i : s)
		i = tolower(i);
	return s;
}

string& toupper(string& s)
{
	for (auto& i : s)
		i = toupper(i);
	return s;
}

int main(int argc, const char* argv[])
{
	int i = 0;
	cout << i << " " << ++i << endl; // undefined behavior -> 입출력에서 참조를 하는 값에 연산을 하지 마라

	string s("a string"), orig = s;
	cout << toupper(s) << endl;
	cout << tolower(s) << endl;

	s = orig;

	cout << toupper(s) << " " << tolower(s) << endl; // undefined behavior -> 위와 마찬가지 이유, 결과를 예측할 수 없다.

	string first = toupper(s);
	string second = tolower(s);

	cout << first << " " << second << endl;
	cout << second << " " << first << endl;
	cout << first << " " << first << endl;
	cout << second << " " << second << endl;

	return 0;
}