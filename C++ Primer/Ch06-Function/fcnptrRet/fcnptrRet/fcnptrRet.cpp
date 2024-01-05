/*
* C++ Primer - Function (함수)
* 파일명: fcnptrRet.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-04
* 이전 버전 작성 일자:
* 버전 내용: 함수 포인터를 반환하는 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// 함수 선언 (정의 아님)
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);


// 함수 정의
string::size_type sumLength(const string& s1, const string& s2)
{
	return s1.size() + s2.size();
}

string::size_type largerLength(const string& s1, const string& s2)
{
	return (s1.size() > s2.size()) ? s1.size() : s2.size();
}

// 함수 포인터를 반환하는 세 가지 방법
// 여기서는 getFcn이라는 함수 포인터를 이용하여 sumLength 또는 largerLength 함수의 포인터를 반환하려고 한다.

// 1) decltype을 사용하여 반환형을 추론하고 그 뒤에 *를 붙여 함수 포인터를 반환하는 것을 명시한다.
decltype(sumLength)* getFcn(const string&);


// 2) 후행 반환을 사용한다.
auto getFcn(const string&) -> string::size_type(*)(const string&, const string&);


// 3) 함수 포인터를 직접 정의한다 -> 제일 까다롭다
string::size_type (*getFcn(const string&))(const string&, const string&);

// 함수 포인터를 반환하는 함수 정의
decltype(sumLength)* getFcn(const string& fetch)
{
	if (fetch == "sum")
		return sumLength;
	return largerLength;
}

int main(int argc, const char* argv[])
{
	cout << getFcn("sum")("hello", "world!") << endl;    // prints 11
	cout << getFcn("larger")("hello", "world!") << endl; // prints 6

	return 0;
}