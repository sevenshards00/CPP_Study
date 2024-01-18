/*
* C++ Primer - Overloaded Operations & Conversions (다중 정의 연산과 변환)
* 파일명: directcall.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-18
* 이전 버전 작성 일자:
* 버전 내용: 오버로딩한 연산자를 직접 호출하는 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Sales_data.h"

int main()
{
	Sales_data data1, data2;
	cin >> data1 >> data2;
	cout << data1 + data2 << endl;
	cout << 42 + 5 << endl;

	// 비멤버 함수 연산자 오버로딩 호출
	data1 + data2;            // 일반 표현식을 통한 operator+() 호출
	operator+(data1, data2);  // 위와 동일, operator+()를 직접 호출
	cout << operator+(data1, data2) << endl; // data + data2와 같다.

	// 멤버 함수 연산자 오버로딩 호출
	data1 += data2;           // 표현식을 기반으로 한 operator+=() 호출
	data1.operator+=(data2);  // 위와 동일, 멤버 operator+=()를 호출
	cout << data1 << endl;

    return 0;
}