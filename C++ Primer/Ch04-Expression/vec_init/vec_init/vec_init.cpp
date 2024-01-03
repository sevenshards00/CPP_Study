/*
* C++ Primer - Expression (표현식)
* 파일명: vec_init.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: vector 초기화 예제
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	vector<int> ivec; // 비어있는 vector 객체
	int cnt = 10;

	while (cnt > 0) // 10부터 값을 1까지 값을 채운다.
		ivec.push_back(cnt--);

	auto iter = ivec.begin(); // 반복자 iter 정의

	while (iter != ivec.end()) // 반복자를 이용하여 vector에 저장된 값을 출력
		cout << *iter++ << endl; // 포인터처럼 연산 가능

	vector<int> vec2(10, 0); // 10개의 요소를 가지는 vector 객체, 초기값은 모두 0으로
	cnt = vec2.size(); // cnt는 10이 된다.

	// for문을 이용하여 vector에 값을 채워넣는다.
	for (vector<int>::size_type ix = 0; ix != vec2.size(); ++ix, --cnt)
		vec2[ix] = cnt;

	iter = vec2.begin();
	while (iter != vec2.end())
		cout << *iter++ << endl;

	return 0;
}