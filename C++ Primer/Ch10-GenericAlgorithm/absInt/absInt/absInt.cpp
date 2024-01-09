/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: absInt.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 일반화 알고리즘 라이브러리 transform과 람다 표현식 반환 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <iterator>
using std::inserter;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::for_each;
using std::transform;

int main(int argc, const char *argv[])
{
	vector<int> vi;
	int i;
	while (cin >> i)
		vi.push_back(i);

	for_each(vi.begin(), vi.end(), [](int i) {cout << i << endl; });
	cout << endl;

	vector<int> orig = vi;

	// vector 내의 음수를 절대값으로 바꾼다.
	transform(vi.begin(), vi.end(), vi.begin(),
		[](int i) {return i < 0 ? -i : i; });
	for_each(vi.begin(), vi.end(), [](int i) {cout << i << endl; });
	cout << endl;

	// 아래는 위와 동일
	// 람다 표현식에서 반환 타입을 정의할 때는 반드시 후행 반환 타입을 사용한다. (C++11 표준 이후)
	vi = orig;
	transform(vi.begin(), vi.end(), vi.begin(),
		[](int i) -> int {if (i < 0) return -i; else return i; });
	for_each(vi.begin(), vi.end(), [](int i) {cout << i << endl; });

	return 0;
}