/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: ostreamIter2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 출력 스트림 반복자 사용 예제
* 이전 버전 내용:
*/

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include<vector>
using std::vector;

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	vector<int> vec;
	istream_iterator<int> in_iter(cin);  // 표준 입력에서 int형 데이터를 읽어들인다.
	istream_iterator<int> eof;           // 반복자의 끝

	while (in_iter != eof) // EOF를 만날 때까지
		vec.push_back(*in_iter++); // vector에 요소를 추가한다.

	ostream_iterator<int> out_iter(cout, " "); // 출력 스트림 반복자, 출력 시 " "를 추가한다.

	for (auto e : vec)
		out_iter = e;  // 이 대입문은 cout에 vector의 요소를 하나씩 기록하는 것.
	cout << endl;

	return 0;
}