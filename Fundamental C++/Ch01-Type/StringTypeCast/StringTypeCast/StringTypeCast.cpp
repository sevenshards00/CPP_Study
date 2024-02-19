/*
* Fundamental C++ - Ch01-Type
* 파일명: StringTypeCast.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: C++의 C형식 문자열의 type 일치 및 형 변환 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

#include <string>
using std::string;

// 4개의 함수 오버로딩
// VS2022 기준 컴파일러에서는 결과가 다르다.

// C형식 문자열의 경우 1순위로 const char*를 매개변수로 받는 함수를 호출
void Func(const char *str)
{
	cout << "const char *" << '\n';
}

// 호출되지 않음.
// VS2022 기준으로 C형식 문자열은 const char*이며 char*로 암시적으로 형 변환하지 않음
void Func(char *str)
{
	cout << "char *" << '\n';
}

// 호출되지 않음.
// VS2022 기준으로 const char*에서 void*로 암시적으로 형 변환이 발생하지 않는다.
void Func(void *str)
{
	cout << "void *" << '\n';
}

// VS2022 기준 2순위로 해당 함수가 호출.
// C형식 문자열(const char*)에서 string으로는 암시적 형 변환이 가능.
void Func(string str)
{
	cout << "string" << '\n';
}

int main()
{
	Func("Hello World!");
	return 0;
}