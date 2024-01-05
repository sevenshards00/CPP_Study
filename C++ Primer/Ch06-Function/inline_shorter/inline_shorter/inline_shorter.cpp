/*
* C++ Primer - Function (함수)
* 파일명: inline_shorter.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: inline 함수 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

// 함수 inline화
inline const
string& shoterString(const string& s1, const string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

int main(int argc, const char* argv[])
{
	string s1("successes"), s2("failure");
	cout << shoterString(s1, s2) << endl;

	// 반환되는 값이 string&이므로 string의 멤버 함수를 호출할 수 있음.
	cout << shoterString(s1, s2).size() << endl;

	// 위의 함수가 inline 함수가 되었다면 아래와 같은 형태로 코드가 생성됨
	cout << (s1.size() <= s2.size() ? s1 : s2) << endl;
}