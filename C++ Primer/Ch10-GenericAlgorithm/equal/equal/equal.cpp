/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: equal.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: 순차 컨테이너에 equal 사용 예제
* 이전 버전 내용:
*/

#include <algorithm>
using std::equal;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#define LIST_INIT // C++11 표준 이후 -> 목록 초기화를 사용할 경우

#ifndef LIST_INIT // C++11 표준 이하를 사용할 경우 (목록 초기화를 지원하지 않는 경우)
#include <iterator>
using std::begin;
using std::end;
#endif

int main(int argc, const char* argv[])
{
#ifdef LIST_INIT // C++11 표준 이후 -> 목록 초기화를 사용할 경우
	list<const char*> roster1;
	vector<string> roster2;
	roster1 = { "hello", "so long" };
	roster2 = { "hello", "so long", "tata" };
#else // C++11 표준 이하를 사용할 경우 (목록 초기화를 지원하지 않는 경우)
	const char* temp1[] = { "hello", "so long" };
	string temp2[] = { "hello", "so long", "tata" };
	list<const char*> roster1(begin(temp1), end(temp1));
	vector<string> roster2(begin(temp2), end(temp2));
#endif

	// equal을 통해 비교
	// roster2에는 최소한 roster1만큼 요소를 가지고 있어야 한다.
	// roster2.size() >= roster1.size()
	// 서로 타입이 다른 컨테이너의 요소를 비교 가능
	auto b = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
	(b) ? cout << "true" : cout << "false";
	cout << endl;
}