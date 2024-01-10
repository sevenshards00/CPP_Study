/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: setOps.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: 연관 컨테이너 연산 예제 - set, multiset
* 이전 버전 내용:
*/

#include <set>
using std::set; // key가 유일한 set
using std::multiset; // 다중 key를 허용하는 set

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#define LIST_INIT

#ifndef LIST_INIT // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
#include <iterator>
using std::begin;
using std::end;
#endif

int main(int argc, const char *argv[])
{
	vector<int> ivec;
	// vector에 20개의 요소를 추가.
	for (vector<int>::size_type i = 0; i != 10; ++i)
	{
		// 1부터 10까지 두 번씩 요소를 추가한다.
		ivec.push_back(i);
		ivec.push_back(i);
	}

	// iset에서는 ivec에서 유일한(unique) 요소만 추가하고, miset에서는 키가 유일하지 않으므로 20개 요소 모두 추가된다.
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());

	cout << "ivec size(): " << ivec.size() << endl; // 20
	cout << "iset size(): " << iset.size() << endl; // 10
	cout << "miset size(): " << miset.size() << endl; // 20

	// find -> 특정 요소의 존재 여부를 확인할 때
	iset.find(1); // key가 1인 요소를 찾을 경우 1에 대한 반복자를 반환
	iset.find(11); // 11은 없으므로 끝 다음 반복자, iset.end()를 반환
	
	// count -> 특정 요소가 몇 개가 있는지 찾고자 할 때
	miset.count(1); // 1을 반환
	miset.count(11); // 없으므로 0을 반환
	
	// set에 요소 추가
	set<string> set1; // 빈 set
	set1.insert("the");
	set1.insert("and");

#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	ivec = { 2, 4, 6, 8, 2, 4, 6, 8 }; // 중복된 요소가 있는 vector
	set<int> set2; // 빈 set
	// 추가하는 경우, set는 키 값이 유일(unique)하므로 2, 4, 6, 8만 추가
	set2.insert(ivec.cbegin(), ivec.cend());
	cout << "set2 size(): " << set2.size() << endl;
	// 아래의 경우도 1, 3, 5, 7만 추가된다.
	set2.insert({ 1, 3, 5, 7, 1, 3, 5, 7 });
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	// 이하 동일
	int temp[] = { 2, 4, 6, 8, 2, 4, 6, 8 };
	set<int> set2;
	set2.insert(begin(temp), end(temp));
	cout << "set2 size(): " << set2.size() << endl;
	int temp2[] = { 1, 3, 5, 7, 1, 3, 5, 7 };
	set2.insert(begin(temp2), end(temp2));
#endif

	cout << "set2 size(): " << set2.size() << endl;
	
	return 0;
}