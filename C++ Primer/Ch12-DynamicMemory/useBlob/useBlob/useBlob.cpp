/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: useBlob.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: StrBlob 클래스에서 share_ptr, weak_ptr 사용 예제 - main
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#ifndef LIST_INIT
#include <iterator>
using std::begin;
using std::end;

#include <string>
using std::string;
#endif

#include "StrBlob.h"

int main(int argc, const char* argv[])
{
	StrBlob b1;
	{
#ifdef LIST_INIT
		StrBlob b2 = { "a", "an", "the" };
#else
		string temp[] = { "a", "an", "the" };
		StrBlob b2(begin(temp), end(temp));
#endif
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;

	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
		cout << it.deref() << endl;

	return 0;
}