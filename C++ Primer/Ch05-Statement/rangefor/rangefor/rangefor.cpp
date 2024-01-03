/*
* C++ Primer - Statement (문장)
* 파일명: rangefor.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: C++11 표준으로 추가된 범위 for문 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#ifndef LIST_INIT
#include <iterator>
using std::begin;
using std::end;
#endif

#define LIST_INIT

int main(int argc, const char* argv[])
{
#ifdef LIST_INIT
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
#else
	int temp[] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> v(begin(temp), end(temp));
#endif

	for (auto& r : v)
		r *= 2;

	for (auto r : v)
		cout << r << " ";
	cout << endl;

	return 0;
}