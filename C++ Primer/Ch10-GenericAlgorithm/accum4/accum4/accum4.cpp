/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: accum4.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 입출력 반복자와 accumulate 사용 예제
* 이전 버전 내용:
*/

#include <numeric>
using std::accumulate;

#include <iterator>
using std::istream_iterator;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	istream_iterator<int> in(cin); // 표준 입력을 통해 int를 읽어들이는 입력 스트림 반복자
	istream_iterator<int> eof; // 입력 스트림 끝 반복자

	cout << accumulate(in, eof, 0) << endl; // 반복자를 통해 EOF까지 입력받은 값을 합산
	return 0;
}