/*
* C++ Primer - Expression (표현식)
* 파일명: sizeof_pgm.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: sizeof 연산자 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include "Sales_data.h"

#define SIZEOF_MEMBER

int main(int argc, const char* argv[])
{
	Sales_data data, * p;
	sizeof(Sales_data);
	sizeof data;
	sizeof p;
	sizeof* p;
	sizeof data.revenue;

#ifdef SIZEOF_MEMBER // C++11 표준으로 추가된 부분. 범위 접근 연산자(::)를 사용하여 타입 멤버 크기를 얻는 것이 가능
	sizeof Sales_data::revenue;
#else
	sizeof Sales_data().revenue; // 임시객체를 생성해서 해당 멤버에 접근하여 sizeof 연산을 수행
#endif

	cout << "short: " << sizeof(short) << '\n'
		<< "short[3]: " << sizeof(short[3]) << '\n'
		<< "short*: " << sizeof(short*) << '\n'
		<< "short&: " << sizeof(short&) << endl;

	cout << "int: " << sizeof(int) << '\n'
		<< "int[3]: " << sizeof(int[3]) << '\n'
		<< "int*: " << sizeof(int*) << '\n'
		<< "int&: " << sizeof(int&) << endl;

	cout << "Sales_data: " << sizeof(Sales_data) << '\n'
		<< "Sales_data[3]: " << sizeof(Sales_data[3]) << '\n'
		<< "Sales_data*: " << sizeof(Sales_data*) << '\n'
		<< "Sales_data&: " << sizeof(Sales_data&) << endl;

#ifdef SIZEOF_MEMBER // C++11 표준으로 추가된 부분. 범위 접근 연산자(::)를 사용하여 타입 멤버 크기를 얻는 것이 가능
	cout << "Sales_data::revenue: " << sizeof Sales_data::revenue << '\n'
		<< "data.revenue: " << sizeof data.revenue << endl;
#else
	cout << "Sales_data().revenue: " << sizeof Sales_data().revenue << '\n' // 임시객체를 생성해서 해당 멤버에 접근하여 sizeof 연산을 수행
		<< "data.revenue: " << sizeof data.revenue << endl;
#endif

	int x[10];
	int* ip = x;

	cout << sizeof(x) / sizeof(*x) << endl; // 배열 요소 개수
	cout << sizeof(ip) / sizeof(*ip) << endl; // int형 포인터의 크기를 int형 크기로 나눔

	return 0;
}