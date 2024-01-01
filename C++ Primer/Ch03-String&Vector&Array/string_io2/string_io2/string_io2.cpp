/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: string_io2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(2) - 기본적인 입출력
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	string s1, s2; // string 객체 s1, s2

	cin >> s1 >> s2; // 공백 문자 이전까지 s1에 저장, 이후 문자열은 s2에 저장
	cout << s1 << s2 << endl; // 저장된 문자열을 출력

	return 0;
}