/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: Sales_data.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: Sales_data 클래스 정의
* 이전 버전 내용:
*/

#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string> // string 클래스를 사용하기 위함
using std::string;

// struct는 구조체지만 C++에서는 클래스로 볼 수 있다.
// 일단 클래스에 대한 개념을 정립하기 전까지는 struct로
struct Sales_data
{
	string bookNo;
#ifdef IN_CLASS_INITS // 조건부 컴파일 시작
	unsigned units_sold = 0;
	double revenue = 0.0;
#else
	unsigned units_sold;
	double revenue;
#endif // 조건부 컴파일 종료
};
#endif