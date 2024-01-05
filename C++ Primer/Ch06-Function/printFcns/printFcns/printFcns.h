/*
* C++ Primer - Function (함수)
* 파일명: printFcns.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: 함수 다중 정의(함수 오버로딩) 예제
* 이전 버전 내용:
*/

#ifndef __PRINTFCNS_H__
#define __PRINTFCNS_H__
#include <vector>
using std::vector;

#include <iterator>
using std::begin;
using std::end;

void print(const char* cp);
void print(const int* beg, const int* end);
void print(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end);
void print(const int ia[], size_t size);
void print(const std::vector<int>&);

inline void foo()
{
    int j[2] = { 0,1 };
    print("Hello World");        // print(const char*)
    print(j, end(j) - begin(j)); // print(const int*, size_t)
    print(begin(j), end(j));     // print(const int*, const int*)
}
#endif