/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: substr.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: string 컨테이너에서 substr 연산(부분 문자열 추출) 사용 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::out_of_range;

int main(int argc, const char* argv[])
{
	try
	{
		string s("hello world");
		cout << s.substr(0, 5) << endl;  // s의 0번째부터 5번째 문자까지 추출. -> hello
		cout << s.substr(6) << endl;     // s의 6번째부터 문자열의 끝까지 추출 -> world
		cout << s.substr(6, 11) << endl; // s의 6번째부터 11번째 문자까지 추출 -> world
		cout << s.substr(12) << endl;    // s의 범위를 넘어서는 경우 예외 out_of_range가 발생(throw)한다. 
	}
	catch (out_of_range)
	{
		cout << "caught out_of_range" << endl;
	}

	return 0;
}