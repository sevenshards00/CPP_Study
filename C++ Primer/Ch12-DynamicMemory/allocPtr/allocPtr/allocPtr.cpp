/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: allocPtr.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: 동적 할당 (new, delete) 기본 예제(2) - allocSP를 new와 delete로
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#include "Foo.h"

// 동적으로 할당되는 객체를 가리키는 shared_ptr을 반환
Foo* factory(T arg)
{
	// make_shared 대신 new를 사용하여 동적 할당.
	// 반환하는 값은 동적 할당한 객체의 포인터
	return new Foo(arg);
}

Foo* use_factory(T arg)
{
	// p를 사용
	Foo *p = factory(arg);
	print(cout, *p);
	cout << endl;

	return p;
}

int main(int argc, const char *argv[])
{
	T arg;
	while (cin >> arg)
	{
		auto p = use_factory(arg);
		delete p; // 동적 할당한 객체의 해제 호출한 쪽(Caller)에서 책임져야 한다.
	}

	return 0;
}