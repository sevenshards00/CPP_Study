/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: reverse.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 컨테이너 관련 일반화 알고리즘 사용 예제 - reverse, reverse_cpy, remove_copy_if
* 이전 버전 내용:
*/

#include <algorithm>
using std::find;
using std::find_if;
using std::for_each;
using std::remove_copy_if;
using std::reverse_copy;
using std::reverse;

#include <iterator>
using std::back_inserter;

#define LIST_INIT

#ifndef LIST_INIT // 목록 초기화를 지원하지 않는 경우 (C++11 표준 미만)
using std::begin;
using std::end;
#endif

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
#ifdef LIST_INIT
	vector<int> v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else
	int temp[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v1(begin(temp), end(temp));
#endif
	vector<int> v2;
	vector<int> v3 = v1;

	find(v1.begin(), v1.end(), 42); // 42와 같은 요소의 첫 번째 위치의 반복자를 반환
	find_if(v1.begin(), v1.end(), [](int i) {return i % 2; }); // 최초로 홀수인 요소의 반복자를 반환

	reverse(v1.begin(), v1.end()); // v1의 요소를 모두 역순으로 뒤집는다.
	
	v1 = v3;

	reverse_copy(v1.begin(), v1.end(), back_inserter(v2)); // v1의 요소를 역순으로 v2에 삽입 반복자를 이용하여 복사한다.

	for (auto i : v1)
		cout << i << " ";
	cout << endl;

	for (auto i : v2)
		cout << i << " ";
	cout << endl;

	auto it = remove_if(v1.begin(), v1.end(), [](int i) {return i % 2; }); // v1의 요소 내에서 홀수만 삭제한다.
	for_each(v1.begin(), it, [](int i) {cout << i << " "; });
	cout << endl;

	v1 = v3;
	v2.clear();

	remove_copy_if(v1.begin(), v1.end(), back_inserter(v2), [](int i) {return i % 2; }); // v2에 짝수만 요소로 추가한다.
	for (auto i : v2)
		cout << i << " ";
	cout << endl;

	for (auto i : v1)
		cout << i << " ";
	cout << endl;
	
	return 0;
}