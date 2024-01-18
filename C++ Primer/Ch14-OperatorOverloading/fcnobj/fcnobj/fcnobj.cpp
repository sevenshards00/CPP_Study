/*
* C++ Primer - Overloaded Operations & Conversions (다중 정의 연산과 변환)
* 파일명: fcnobj.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-18
* 이전 버전 작성 일자:
* 버전 내용: 라이브러리에서 정의한 함수 객체 및 function 라이브러리 사용 예제
* 이전 버전 내용:
*/

#include <functional>
using std::plus;
using std::negate;
using std::function;
using std::placeholders::_1;
using std::bind;
using std::less_equal;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::count_if;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;

#include <string>
using std::string;

#define LIST_INIT // 목록 초기화를 사용할 경우 (C++11 표준 이상)

#ifndef LIST_INIT // 목록 초기화를 사용하지 않을 경우 (C++11 표준 미만)
#include <iterator>
using std::begin;
using std::end;
#endif

bool size_compare(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

int main()
{
	// plus<int>객체 사용
	cout << plus<int>()(3, 4) << endl;

	plus<int> intAdd; // 두 값을 더하는 plus<int> 객체
	negate<int> intNegate; // 해당 값에 대해 부정(Not) 연산을 하는 객체

	int sum = intAdd(10, 20);
	cout << sum << endl;

	sum = intNegate(intAdd(10, 20));
	cout << sum << endl;

	sum = intAdd(10, intNegate(10));
	cout << sum << endl;

#ifdef LIST_INIT // 목록 초기화를 사용할 경우 (C++11 표준 이상)
	vector<int> vec = { 0,1,2,3,4,5,16,17,18,19 };
#else // 목록 초기화를 사용하지 않을 경우 (C++11 표준 미만)
	int temp[] = { 0,1,2,3,4,5,16,17,18,19 };
	vector<int> vec(begin(temp), end(temp));
#endif
	// 10보다 작거나 같은 수만 세는 경우
	// bind를 이용하여 단항 술어 함수로 바꿔서 전달
	cout << count_if(vec.begin(), vec.end(), bind(less_equal<int>(), _1, 10));
	cout << endl;

	vector<string> svec;
	string in;

	while (cin >> in)
		svec.push_back(in);

	// function 라이브러리를 이용한 함수 포인터 생성
	function<decltype(size_compare)> fp = size_compare;
	function<bool(const string &)> fp2 = bind(size_compare, _1, 6);

	cout << count_if(svec.begin(), svec.end(), fp2) << endl;
	cout << count_if(svec.begin(), svec.end(), bind(size_compare, _1, 6)) << endl;

	return 0;
}