/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: reverse_iter.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 역방향 반복자 기본 예제(2)
* 이전 버전 내용:
*/

#include <algorithm>
using std::copy;
using std::sort;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	vector<int> vec;
	istream_iterator<int> in(cin);
	istream_iterator<int> eof;
	
	copy(in, eof, back_inserter(vec)); // 스트림 반복자를 이용하여 표준 입력을 통한 vector 초기화

	sort(vec.begin(), vec.end()); // vector 내 요소를 정렬한다. (기본 오름차순)
	vector<int> vec2(vec);

	sort(vec.rbegin(), vec.rend()); // vector를 역순으로 정렬한다. (내림차순)

	// vec, vec2 출력
	ostream_iterator<int> out(cout, " ");
	copy(vec.begin(), vec.end(), out);
	cout << endl;

	copy(vec2.begin(), vec2.end(), out);
	cout << endl;

	auto it = vec.begin(); // vec의 첫 번째 요소를 가리키는 반복자
	vector<int>::reverse_iterator rev_it(it); // 반복자 it를 참조하여 역방향 반복자 rev_it을 만든다. 이 반복자는 첫 번째 요소보다 하나 앞을 가리킨다.

	// base()를 사용하여 순방향 반복자를 얻을 수 있다.
	// 아래의 결과는맨 처음 요소를 출력하게 된다.
	cout << *(rev_it.base()) << endl;

	// vec의 첫 번째 요소를 가리키는 다양한 방법
	cout << *it << endl;
	cout << *(rev_it.base()) << endl;
	cout << *(rev_it - 1) << endl;
	return 0;
}