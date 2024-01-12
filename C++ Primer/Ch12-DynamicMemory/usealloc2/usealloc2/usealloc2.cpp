/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: usealloc2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자:
* 버전 내용: allocator 사용 예제 (2) - 초기화되지 않은 메모리를 복사하고 채우기
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::uninitialized_copy;
using std::allocator;
using std::uninitialized_fill_n;

#include <iostream>
using std::cout;
using std::endl;

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

#ifndef LIST_INIT // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
#include <iterator>
using std::begin;
using std::end;
#endif

int main(int argc, const char *argv[])
{
#ifdef LIST_INIT
	vector<int> vi{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else
	int temp[] = { 1 ,2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vi(begin(temp), end(temp));
#endif

	allocator<int> alloc; // allocator 객체 생성

	// vector<int>의 2배 크기만큼 메모리를 할당, p는 해당 메모리를 가리킨다.
	auto p = alloc.allocate(vi.size() * 2); 
	// vi의 요소 복사본으로 p부터 시작해서 요소를 '생성'한다.
	// q는 해당 요소를 생성한 끝의 다음을 가리키게 된다.
	auto q = uninitialized_copy(vi.begin(), vi.end(), p);

	// q를 시작으로 vi.size()만큼 42로 초기화한다.
	uninitialized_fill_n(q, vi.size(), 42);

	// p에서 시작 -> vector에서 복사한 요소를 출력
	for (size_t i = 0; i != vi.size(); ++i)
		cout << *(p + i) << " ";
	cout << endl;

	// q에서 시작 -> 42를 vi.size()만큼 초기화한 요소를 출력
	for (size_t i = 0; i != vi.size(); ++i)
		cout << *(q + i) << " ";
	cout << endl;

	// 마지막으로 메모리를 할당 해제.
	alloc.deallocate(p, vi.size() * 2);
	return 0;
}