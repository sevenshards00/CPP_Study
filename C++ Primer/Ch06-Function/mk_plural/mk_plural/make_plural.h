/*
* C++ Primer - Function (함수)
* 파일명: make_plural.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: 단어를 복수형으로 만드는 예제 - 헤더 파일
* 이전 버전 내용:
*/

#ifndef __MAKE_PLURAL_H__
#define __MAKE_PLURAL_H__

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

// 함수의 인라인(inline)화 요청.
// 컴파일러는 이걸 인라인화할 수도 있고 안할 수도 있다.
inline
string make_plural(size_t cnt, const string& word, const string& ending)
{
	return (cnt > 1) ? word + ending : word;
}

#endif