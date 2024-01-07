/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: accum.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: 다양한 순차 컨테이너에 accum 사용 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::fill;
using std::fill_n;

#include <numeric>
using std::accumulate;

#include <iterator>
using std::back_inserter;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	vector<int> vec(10);
	fill(vec.begin(), vec.end(), 1); // vector의 모든 요소를 1로 채운다.

	// vector<int>내의 모든 요소 값을 합하는 경우
	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << sum << endl;

	// vector<int>의 절반까지만 10으로 요소를 채운다.
	fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
	cout << accumulate(vec.begin(), vec.end(), 0) << endl; // 합한 값을 출력

	// vector<int>의 절반까지 다시 0으로 요소를 채운다.
	fill_n(vec.begin(), vec.size() / 2, 0);
	cout << accumulate(vec.begin(), vec.end(), 0) << endl; // 합한 값을 출력

	// vector<int>의 끝에서부터 42라는 값을 가지는 10개의 요소를 삽입
	fill_n(back_inserter(vec), 10, 42);
	cout << accumulate(vec.begin(), vec.end(), 0) << endl; // 합한 값을 출력


	// string에서의 총합을 하는 경우 string에서의 + 연산은 문자열을 연결하는 것.
	vector<string> v;
	string s;
	while (cin >> s)
		v.push_back(s);
	string concat = accumulate(v.cbegin(), v.cend(), string(""));
	cout << concat << endl;

	return 0;
}