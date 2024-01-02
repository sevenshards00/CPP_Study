/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: vecSubs.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-02
* 이전 버전 작성 일자:
* 버전 내용: vector 템플릿 사용 예제(5) - vector 요소 접근 방법
* 이전 버전 내용:
*/

#define LIST_INIT

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 목록 초기화를 하지 않을 경우
#ifndef LIST_INIT
#include <iterator>
using std::begin;
using std::end;
#endif

int main(int argc, const char* argv[])
{
#ifdef LIST_INIT // 목록 초기화를 할 경우 배열처럼 초기화 가능
	vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else // 목록 초기화를 하지 않을 경우
	int temp[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // 배열을 정의
	vector<int> v(begin(temp), end(temp)); // iterator의 begin과 end를 이용, 배열을 가지고 vector를 초기화
#endif

// Case1: 반복자(iterator)를 이용하여 0~9까지 vector에 추가
	auto sz = v.size();
	decltype(sz) i = 0;

	while (i != sz)
	{
		v.push_back(*v.begin() + i); // 반복자 사용
		i++;
	}

	for (auto it : v)
		cout << it << " ";

	cout << endl;
// Case2: 배열처럼 첨자([])를 이용하여 0~9까지 추가
#ifdef LIST_INIT
	vector<int> alt_v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else
	vector<int> alt_v(begin(temp), end(temp));
#endif

	for (decltype(alt_v.size()) i = 0, sz = alt_v.size(); i != sz; i++)
		alt_v.push_back(alt_v[i]); // 첨자 사용

	for (auto it : alt_v)
		cout << it << " ";

	cout << endl;
// Case3: 배열처럼 요소에 접근, 0~4까지의 값을 0으로 변경
#ifdef LIST_INIT
	vector<int> v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else
	vector<int> v2(begin(temp), end(temp));
#endif
	decltype(v2.size()) ix = 0;

	while (ix != v2.size() && v2[ix] < 5)
	{
		v2[ix] = 0; // 첨자([]) 사용
		ix++;
	}

	for (auto i = 0; i != v2.size(); i++)
		cout << v2[i] << " ";

	cout << endl;

// Case4: 반복자(iterator)를 사용하여 요소 접근, 0~4까지의 값을 0으로 변경
#ifdef LIST_INIT
	vector<int> alt_v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else
	vector<int> alt_v2(begin(temp), end(temp));
#endif
	auto it = alt_v2.begin();
	while (it != alt_v2.end() && *it < 5)
	{
		*it = 0; // 반복자 사용
		it++;
	}

	for (auto it = alt_v2.begin(); it != alt_v2.end(); it++)
		cout << *it << " ";

	cout << endl;

	return 0;
}