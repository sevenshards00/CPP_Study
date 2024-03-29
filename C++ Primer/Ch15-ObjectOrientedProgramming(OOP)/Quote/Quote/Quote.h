﻿/*
* C++ Primer - Object Oriented Programming (객체 지향 프로그래밍)
* 파일명: Quote.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-19
* 이전 버전 작성 일자:
* 버전 내용: Disc_quote 클래스 추가 (리팩터링)
* 이전 버전 내용: 상속 기본 예제 - 서적 판매 견적서(Quote, Bulk_quote 클래스 선언부)
*/

#ifndef __QUOTE_H__
#define __QUOTE_H__

#define IN_CLASS_INITS
#define DEFAULT_FCNS
#define REFMEMS

#include <memory>
#include <iostream>
#include <string>
#include <cstddef>
#include <utility>

// 기초 클래스 Quote (Base Class)
class Quote
{
public:
	// 클래스 내 초기화와 default를 이용한 기본 생성자를 사용하는 경우 (C++11 표준 이상)
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
	Quote() = default; // 디폴트 생성자
#else // 둘 다 사용하지 않는 경우 (C++11 표준 미만)
	Quote() : price(0.0) {} // 디폴트 생성자
#endif
	// 생성자
	Quote(const std::string &book, double sales_price)
		:bookNo(book), price(sales_price) { }

	// 멤버 함수
	// 책의 번호를 반환 (Getter)
	std::string isbn() const
	{
		return bookNo;
	}
	// 책 판매 수량에 대한 전체 판매 가격을 반환. (Getter)
	// 가상 멤버 함수 -> 상속 받는 클래스에서 재정의
	virtual double net_price(std::size_t n) const
	{
		return n * price;
	}

	// 소멸자 -> virtual(가상) 소멸자
#ifdef DEFAULT_FCNS // default를 사용하는 경우 (C++11 표준 이상)
	virtual ~Quote() = default;
#else // default를 사용하지 않는 경우 (C++11 표준 미만)
	virtual ~Quote() {}
#endif

private:
	std::string bookNo; // 해당 책에 대한 ISBN 번호
protected: // 상속과 관련된 접근 지정 한정자
#ifdef IN_CLASS_INITS // 클래스 내 초기화를 사용하는 경우 (C++11 표준 이상)
	double price = 0.0;
#else // 클래스 내 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	double price;
#endif
};

// 파생 클래스 Disc_quote (Quote <- Disc_Quote)
// 추상 클래스(Abstract Class)
class Disc_quote : public Quote
{
public:
	// 클래스 내 초기화와 default를 이용한 기본 생성자를 사용하는 경우 (C++11 표준 이상)
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
	Disc_quote() = default; // 디폴트 생성자
#else // 둘 다 사용하지 않는 경우 (C++11 표준 미만)
	Disc_quote() : quantity(0), discount(0.0) {} // 디폴트 생성자
#endif
	// 생성자
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
		:Quote(book, price), quantity(qty), discount(disc) { }

	// 순수 가상 함수 (pure virtual function)
	// 상속을 받았으나 재정의를 하지 않음 -> = 0 으로 순수 가상함수임을 알림
	// 순수 가상 함수를 멤버로 가지고 있으므로 추상 클래스(Abstract Class)가 됨
	double net_price(std::size_t n) const = 0;
protected:
#ifdef IN_CLASS_INITS // 클래스 내 초기화를 사용하는 경우 (C++11 표준 이상)
	std::size_t quantity = 0;
	double discount = 0.0;
#else // 클래스 내 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	std::size_t quantity;
	double discount;
#endif
};

// 파생 클래스 Bulk_quote (Quote <- Disc_Quote <- Bulk_quote)
class Bulk_quote : public Disc_quote
{
public:
	// 생성자
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS) // 클래스 내 초기화와 default를 이용한 기본 생성자를 사용하는 경우 (C++11 표준 이상)
	Bulk_quote() = default;
#else // 둘 다 사용하지 않는 경우 (C++11 표준 미만)
	Bulk_quote() { }
#endif
	Bulk_quote(const std::string &book, double price, std::size_t qty, double disc)
		: Disc_quote(book, price, qty, disc) {}
	double net_price(std::size_t) const override; // 기초 클래스에서 재정의할 함수 (override 키워드)
};

double print_total(std::ostream &, const Quote &, std::size_t);
#endif