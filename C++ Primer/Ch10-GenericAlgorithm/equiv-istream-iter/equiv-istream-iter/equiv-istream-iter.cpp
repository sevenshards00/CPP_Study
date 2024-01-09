/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: equiv-istream-iter.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: iostream 반복자를 이용한 vector 초기화 예제
* 이전 버전 내용:
*/

#include <iterator>
using std::istream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	
	// iostream 반복자(iostream_iterator)를 이용하여 vector를 초기화
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;
	// iostream 반복자 범위를 이용하여 vector 초기화.
	vector<int> vec(in_iter, eof);
	
	// 위는 아래와 같다.
	/*
	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;

	vector<int> vec;
	while (in_iter != eof)
		vec.push_back(*in_iter++);
	*/
	for (auto it : vec)
		cout << it << " ";
	cout << endl;

	return 0;
}