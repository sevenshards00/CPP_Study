/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: Foo.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자: 2024-01-11
* 버전 내용: using 선언 제거
* 이전 버전 내용: shared_ptr 기본 사용 예제
*/

#ifndef __FOO_H__
#define __FOO_H__

#include <iostream>

using T = int;
// struct == 멤버가 모두 기본 public인 class
struct Foo
{
	Foo(T t) :val(t) {}
	T val;
};

std::ostream &print(std::ostream &os, const Foo &f)
{
	os << f.val;
	return os;
}

#endif