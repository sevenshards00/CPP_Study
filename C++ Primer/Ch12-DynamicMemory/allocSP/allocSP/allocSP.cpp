/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: allocSP.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: shared_ptr 기본 사용 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#include "Foo.h"

// 동적으로 할당되는 객체를 가리키는 shared_ptr을 반환
shared_ptr<Foo> factory(T arg)
{
	// make_shared 함수에 의해서 new를 사용한 동적 할당이 된 것.
	// 반환하는 값은 동적 할당한 객체의 포인터
	return make_shared<Foo>(arg);
}

shared_ptr<Foo> use_factory(T arg)
{
	// p를 사용
	shared_ptr<Foo> p = factory(arg);
	print(cout, *p);
	cout << endl;
	
	return p; // p를 반환하면서 참조 횟수(reference count)가 증가
}

int main(int argc, const char *argv[])
{
	T arg;
	while (cin >> arg)
		use_factory(arg);

	return 0;
}