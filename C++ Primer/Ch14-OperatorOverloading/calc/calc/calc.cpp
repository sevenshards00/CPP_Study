/*
* C++ Primer - Overloaded Operations & Conversions (다중 정의 연산과 변환)
* 파일명: calc.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-18
* 이전 버전 작성 일자:
* 버전 내용: 같은 호출 시그니처를 가진 다양한 함수 호출성 객체를 이용한 계산기 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <map>
using std::map;

#include <string>
using std::string;

#include <functional>
using std::bind;
using std::function;
using namespace std::placeholders;

#define LIST_INIT

#ifndef LIST_INIT // 목록 초기화를 사용하지 않을 경우 (C++11 표준 미만)
#include <utility>
using std::make_pair;
#endif

// 일반적인 함수
int add(int i, int j)
{
	return i + j;
}

// 람다 표현식 -> 이름 없는 함수 객체 클래스
auto mod = [](int i, int j) {return i % j; };

// 사용자 정의 함수 객체 클래스
struct divide
{
	int operator()(int i, int j)
	{
		return i / j;
	}
};

int main()
{
	// 위의 세 함수는 모두 반환형이 int에 인자를 (int, int) 형태로 받음.
	// 함수의 호출 시그니처가 int(int, int)

	function<int(int, int)> f1 = add; // 함수 포인터
	function<int(int, int)> f2 = divide(); // 함수 객체 클래스의 객체
	function<int(int, int)> f3 = [](int i, int j) { return i * j; }; // 람다 표현식
	
	cout << f1(4, 2) << endl;
	cout << f2(4, 2) << endl;
	cout << f3(4, 3) << endl;

	// 사칙 연산과 나머지 연산을 하는 함수 테이블을 만든다.
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	map<string, function<int(int, int)>> binops = {
		{"+", add},                  // 함수 포인터
		{"-", std::minus<int>()},    // 라이브러리의 함수 객체
		{"/",  divide()},            // 사용자 정의 함수 객체
		{"*", [](int i, int j) { return i * j; }}, // 이름 없는 람다식
		{"%", mod} };                // named lambda object
#else // 목록 초기화를 사용하지 않을 경우 (C++11 표준 미만)
	map<string, function<int(int, int)>> binops;
	binops.insert(make_pair("+", add));                 // 함수 포인터
	binops.insert(make_pair("-", std::minus<int>()));   // 라이브러리의 함수 객체
	binops.insert(make_pair("/", divide()));           // 사용자 정의 함수 객체
	binops.insert(make_pair("*", [](int i, int j) { return i * j; })); // 이름 없는 람다식
	binops.insert(make_pair("%", mod));                // named lambda object
#endif
	cout << binops["+"](10, 5) << endl; // add(10, 5)를 호출
	cout << binops["-"](10, 5) << endl; // minus<int> 객체의 operator()를 호출
	cout << binops["/"](10, 5) << endl; // divide 객체의 operator()를 호출
	cout << binops["*"](10, 5) << endl; // 람다 함수 객체를 호출
	cout << binops["%"](10, 5) << endl; // 람다 함수 객체를 호출

	return 0;
}