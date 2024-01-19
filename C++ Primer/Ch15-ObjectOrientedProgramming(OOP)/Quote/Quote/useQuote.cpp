/*
* C++ Primer - Object Oriented Programming (객체 지향 프로그래밍)
* 파일명: useQuote.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-19
* 이전 버전 작성 일자:
* 버전 내용: 상속 기본 예제 - 서적 판매 견적서(Quote, Bulk_quote 클래스 main)
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::ostream;

#include "Quote.h"

int main()
{
	Quote base("0-201-82470-1", 50);
	print_total(cout, base, 10); // 여기서는 Quote의 net_price를 호출

	Bulk_quote derived("0-201-82470-1", 50, 5, 0.19);
	print_total(cout, derived, 10); // 여기서는 Bulk_quote의 net_price를 호출
	
	// 파생 -> 기초로 변환
	// 상속 관계에 있을 경우 기초 클래스의 참조자나 포인터로 파생 클래스 객체와 결합이 가능(가리킬 수 있다)
	// 파생 클래스에는 기초 클래스의 부분을 가지고 있기 때문.
	Quote *baseP = &derived;

	// 가상 함수 메커니즘 회피
	// 범위 지정 연산자(::)를 사용하여 기초 클래스인 Quote의 net_price를 호출.
	// 이 경우에는 baseP가 가리키고 있는 객체의 타입과 무관하게 Quote의 net_price를 호출한다.
	// 이 때는 Run-time이 아닌 Compile time에 함수 호출이 결정된다.
	double undiscounted = baseP->Quote::net_price(42); 

	return 0;
}