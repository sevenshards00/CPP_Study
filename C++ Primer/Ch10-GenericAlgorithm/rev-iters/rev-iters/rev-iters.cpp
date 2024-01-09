/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: rev-iters.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 역방향 반복자 기본 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#define LIST_INIT

#ifndef LIST_INIT // 목록 초기화를 지원하지 않는 경우 (C++11 표준 미만)
#include <iterator>
using std::begin;
using std::end;
#endif

int main(int argc, const char *argv[])
{
#ifdef LIST_INIT
	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else
	int temp[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vec(begin(temp), end(temp));
#endif

	// 역방향 반복자를 이용하여 반복문 수행
	for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter)
		cout << *r_iter << endl; // vector의 맨끝부터 처음까지 vector에 저장된 요소의 역순으로 출력된다.

	return 0;
}
