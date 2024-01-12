/*
* C++ Primer - Function (함수)
* 파일명: make_plural.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자: 2024-01-05
* 버전 내용: using 선언 제거
* 이전 버전 내용: 단어를 복수형으로 만드는 예제 - 헤더 파일 (분리 컴파일 + 인라인화)
*/

#ifndef __MAKE_PLURAL_H__
#define __MAKE_PLURAL_H__

#include <cstddef>
#include <string>
#include <iostream>


// 함수의 인라인(inline)화 요청.
// 컴파일러는 이걸 인라인화할 수도 있고 안할 수도 있다.
inline
std::string make_plural(std::size_t cnt, const std::string& word, const std::string& ending)
{
	return (cnt > 1) ? word + ending : word;
}

#endif