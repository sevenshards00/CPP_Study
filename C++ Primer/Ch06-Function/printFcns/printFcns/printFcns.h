/*
* C++ Primer - Function (함수)
* 파일명: printFcns.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자: 2024-01-05
* 버전 내용: using 선언 제거
* 이전 버전 내용: 함수 다중 정의(함수 오버로딩) 예제 - 헤더 파일
*/

#ifndef __PRINTFCNS_H__
#define __PRINTFCNS_H__
#include <vector>
#include <iterator>

void print(const char* cp);
void print(const int* beg, const int* end);
void print(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end);
void print(const int ia[], size_t size);
void print(const std::vector<int>&);

inline void foo()
{
    int j[2] = { 0,1 };
    std::vector<int> ivec = { 0,1,2,3,4,5,6,7,8,9 };
    print("Hello World\n");        // print(const char*)
    print(j, std::end(j) - std::begin(j)); // print(const int*, size_t)
    print(std::begin(j), std::end(j));     // print(const int*, const int*)
    print(ivec); // printf(const vector<int>&);
}
#endif