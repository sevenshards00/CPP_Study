/*
* C++ Primer - Overloaded Operations & Conversions (다중 정의 연산과 변환)
* 파일명: Sales_data.cpp
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-17
* 이전 버전 작성 일자: 2024-01-06
* 버전 내용: Sales_data 클래스 연산자 오버로딩
* 이전 버전 내용: 클래스 기본 예제 - 소스 파일
*/

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

#include "Sales_data.h"

// 입력 스트림을 인자로 받는 생성자
Sales_data::Sales_data(istream &is)
{
	is >> *this; // 입력 스트림을 통해 받은 값을 해당 객체에 >> 연산자를 수행
	// >> 연산자를 오버로딩 하므로 이와 같은 생성자를 만들 수 있음.
}

// 멤버 함수
// 클래스 외부에서 정의 -> 범위 지정 연산자(::)를 이용하여 클래스의 멤버 함수임을 컴파일러에게 알려야함
// 매개변수가 const Sales_data& -> 값을 가져다 쓸 뿐 바꾸지는 않는다.
// 판매한 가격과 수익을 합치는 함수
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	this->units_sold += rhs.units_sold;
	this->revenue += rhs.revenue;
	return *this; // *this를 반환 -> 객체 자신 그 자체를 반환한다
	// 그래서 반환형이 Sales_data&, 참조형 -> lvalue를 반환
}

// 판매 평균 가격을 반환하는 함수
double Sales_data::avg_price() const // const 함수 -> 값을 바꿀 목적이 없다.
{
	if (this->units_sold)
		return this->revenue / this->units_sold;
	else
		return 0;
}

// 비멤버 함수
// 연산자 오버로딩 (+, <<, >>)
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}
ostream &operator<<(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
istream &operator>>(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

// 연산자 오버로딩을 사용하기 전에 만든 함수들 -> 사실상 쓸 필요가 없어짐.
// 클래스 내부의 멤버함수가 아니므로 범위 지정 연산자를 이용하여 클래스의 멤버 함수임을 알릴 필요가 없다.

// Sales_data 객체의 멤버를 합한다. -> operator+()
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs; // += 연산자를 오버로딩 했기 때문에 combine을 쓸 필요가 없음.
	return sum;
}

// 객체의 데이터 멤버를 출력하는 함수. -> operator<<()
ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

// 데이터를 읽어서 객체에 등록하는 함수 -> operator>>()
istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}