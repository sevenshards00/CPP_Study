/*
* Fundamental C++ - Ch03-Build
* 파일명: Tracer.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-22
* 이전 버전 작성 일자:
* 버전 내용: 사전 정의 매크로 사용 예제 - Function Call Tracer
* 이전 버전 내용:
*/

#pragma once

#include <iostream>

#define A_TRACE \
std::cout << "A_TRACE: " << __FUNCTION__ << '\n';

void B_TRACE()
{
	std::cout << "B_TRACE: " << __FUNCTION__ << '\n';
}