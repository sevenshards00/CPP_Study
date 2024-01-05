/*
* C++ Primer - Function (함수)
* 파일명: ref-fcn.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: 참조자를 반환하는 예제 - 참조자는 lvalue(좌변값)
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// 반환형이 char&, 참조자를 반환한다.
char& get_val(string& str, string::size_type ix)
{
	return str[ix];
}

int main(int argc, const char* argv[])
{
	string s("a value");
	cout << s << endl; // a value 출력.

	get_val(s, 0) = 'A'; // 여기서 주목할 부분은 참조자를 반환하는 경우 'lvalue(좌변값)'이다.
	// 이 부분을 풀어서 보면 사실상 이렇게 된다.
	// char& str[0] = 'A';
	// 참조자를 통해 값을 바꾸는 것.
	cout << s << endl; // A value 출력
	return 0;
}