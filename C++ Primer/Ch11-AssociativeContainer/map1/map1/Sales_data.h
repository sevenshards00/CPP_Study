/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: Sales_data.h
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자: 2024-01-10
* 버전 내용: using 선언 제거
* 이전 버전 내용: 순서 있는 연관 컨테이너에서의 키 타입에 대한 비교 함수 사용 및 map에 첨자([]) 연산을 하는 예제
*/

#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#define IN_CLASS_INITS // 클래스 내 초기화를 사용할 경우
#define DEFAULT_FCNS // C++11 표준 이후로 지원하는 컴파일러가 생성하는 기본 생성자를 사용할 경우

#include <string>
#include <iostream>

class Sales_data
{
private:
	std::string bookNo;
#ifdef IN_CLASS_INITS // 클래스 내 초기화를 사용할 경우
	unsigned units_sold = 0;
	double revenue = 0.0;
#else
	unsigned units_sold;
	double revenue = 0.0;
#endif
public:
	// 생성자 정의
	// 기본 생성자
	// 클래스 본체 내부 또는 외부에서 정의 가능
	// 클래스 내에서 정의하면 기본적으로 inline화
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS) // 클래스 내 초기화 + C++11 표준 컴파일러가 생성하는 기본 생성자를 사용할 경우
	Sales_data() = default; // 기본 생성자 사용 (C++11 이후 표준)
#else // 클래스 내 초기화를 사용하지 않을 경우 -> 멤버 이니셜라이저 사용
	Sales_data() : units_sold(0), revenue(0.0) { }
#endif
	// string을 인자로 받는 생성자
#ifdef IN_CLASS_INITS // 클래스 내 초기화를 사용할 경우
	Sales_data(const std::string &s) : bookNo(s) { }
#else // 클래스 내 초기화를 사용하지 않을 경우 -> 멤버 이니셜라이저 사용
	Sales_data(const std::string &s) : bookNo(s), units_sold(0), revenue(0.0) { }
#endif
	// 인자를 3개를 받는 생성자
	Sales_data(const std::string &s, unsigned n, double p)
		:bookNo(s), units_sold(n), revenue(p *n) { }

	// Sales_data 객체에 대한 함수들
	// 멤버 함수
	// 클래스 본체 내에서 멤버 함수를 정의
	std::string isbn() const { return this->bookNo; } // const 멤버 함수 -> 값을 바꿀 일이 없으며 조회만을 목적으로 한다.
	// 아래의 두 멤버 함수는 클래스 외부에서 정의
	Sales_data &combine(const Sales_data &);
	double avg_price() const;

	// 비멤버 함수
	// friend 선언을 통해서 Sales_data 객체의 private 데이터 멤버에 접근 가능
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
	friend std::istream &read(std::istream &, Sales_data &);

};

// Sales_data에 대한 비멤버 함수 선언 -> interface
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

// multimap에서 사용될 비교 연산 함수
// 순서 있는 연관 컨테이너에서는 key 타입에 대해 순약순서(strict weak ordering)이 정의되어 있어야 한다.
// 순약순서에 대해서 간단하게 정의하면 '보다 작다'의 개념이 있어야 한다.
// 순약순서를 정의하는 비교 함수에서는 다음의 특성을 지녀야 한다.
// 1) 두 key가 모두 상대보다 작을 수 없다 -> k1 < k2 라면 반드시 k2 > k1이 성립한다. k2 < k1이 성립될 수 없다.
// 2) k1 < k2, k2 < k3라면 반드시 k1 < k3가 성립한다.
// 3) k1, k2가 서로 작지 않다라면 k1 == k2, 상등 관계가 성립해야 한다.
// 그리고 k1 == k2, k2 == k3라면 k1 == k3 역시 성립해야 한다.
inline
bool CompareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
#endif