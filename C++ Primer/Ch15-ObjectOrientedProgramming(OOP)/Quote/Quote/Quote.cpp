/*
* C++ Primer - Object Oriented Programming (객체 지향 프로그래밍)
* 파일명: Quote.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-19
* 이전 버전 작성 일자:
* 버전 내용: 상속 기본 예제 - 서적 판매 견적서(Quote, Bulk_quote 클래스 구현부)
* 이전 버전 내용:
*/

#include "Quote.h"

#include <algorithm>
using std::min;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

// 계산한 결과 출력
double print_total(ostream &os, const Quote &item, size_t n)
{
	// 동적 결합이 가능
	// item이 참조하는 객체가 Quote면 Quote의 net_price를, Bulk_quote면 Bulk_quote의 net_price를 호출
	// 기초 클래스의 참조자(reference)나 포인터(pointer)로 파생 객체와 결합하는 것이 가능하다.
	// 그리고 해당 객체가 어떤 타입이냐에 따라서 해당 객체의 net_price를 호출
	// 이 때문에 동적 결합은 실행 시점 결합(run-time binding)이라고도 한다.
	// 포인터나 참조자를 통해 '가상 함수를 호출할 때'에만 동적 결합이 발생한다.
	double ret = item.net_price(n);

	// isbn()은 Quote의 isbn()을 호출.
	os << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

// 파생 클래스 Bulk_quote의 멤버 함수
// override 키워드는 멤버 함수를 정의할 때 없어도 된다.
double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty) // 구매 최소 수량보다 이상이라면
		return cnt * (1 - discount) * price; // 할인된 가격을 반환
	else // 그게 아니라면
		return cnt * price; // 정상 가격 반환
}