/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: erase2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: list형 컨테이너(list, forward_list)의 erase 사용법 예제
* 이전 버전 내용:
*/

#include <algorithm>
using std::find;

#include <string>
using std::string;

#include <list>
using std::list;

#include <forward_list>
using std::forward_list;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#define LIST_INIT // 목록 초기화 사용할 경우(C++11 이상)

#ifndef LIST_INIT // 목록 초기화를 사용하지 않을 경우
#include <iterator>
using std::begin;
using std::end;
#endif

int main(int argc, const char* argv[])
{
	// 이중 연결 리스트(list)
#ifdef LIST_INIT // 목록 초기화 사용할 경우(C++11 이상)
	list<int> lst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else // 목록 초기화를 사용하지 않을 경우
	int lstarr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> lst(begin(lstarr), end(lstarr));
#endif

	// 초기화된 리스트를 읽는다.
	cout << "initial list: ";
	for (auto it : lst)
		cout << it << " ";
	cout << endl;

	// 반복자를 이용하여 홀수 요소만 리스트에서 삭제
	auto it = lst.begin();
	while (it != lst.end())
		if (*it % 2)
			it = lst.erase(it);
		else
			++it;

	// 삭제된 결과 확인
	cout << "after erasing odd elements from lst: ";
	for (auto it : lst)
		cout << it << " ";
	cout << endl;

	// 단일 연결 리스트(forward_list)
#ifdef LIST_INIT // 목록 초기화 사용할 경우(C++11 이상)
	forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else // 목록 초기화를 사용하지 않을 경우
	int flstarr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	forward_list<int> flst(begin(lstarr), end(lstarr));
#endif

	// 초기화된 리스트를 읽는다.
	cout << "initial list: ";
	for (auto it : flst)
		cout << it << " ";
	cout << endl;

	// 반복자를 이용하여 홀수 요소만 리스트에서 삭제
	// 단일 연결 리스트 자료구조를 알고 있다면 왜 반복자를 둘을 놓았는지 이해가 될 것.
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr % 2)
			curr = flst.erase_after(prev);
		else
		{
			prev = curr;
			++curr;
		}
	}

	// 삭제된 결과 확인
	cout << "after erasing odd elements from lst: ";
	for (auto it : flst)
		cout << it << " ";
	cout << endl;
}