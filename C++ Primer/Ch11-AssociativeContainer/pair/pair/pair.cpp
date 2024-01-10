/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: pair.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: pair 템플릿 타입 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <utility>
using std::pair;
using std::make_pair;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Sales_data.h"

pair<string, string> anon; // <string, string>을 취하는 pair 객체
pair<string, size_t> word_count; // <string, size_t>를 취하는 pair 객체
pair<string, vector<int>> line; // <string, vector<int>>를 취하는 pair 객체

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
pair<string, string> author{ "James", "Joyce" }; // 목록 초기화
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
pair<string, string> author("James", "Joyce"); // 생성자 호출 방식으로 초기화
#endif

// 타입 별칭을 사용
typedef pair<string, string> Author;
Author proust("Marcel", "Proust"); // 생성자를 통한 pair 객체 생성 및 초기화
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
Author joyce{ "James", "Joyce" }; // 목록 초기화
#endif
Author austen = make_pair("Jane", "Austen"); // make_pair()를 이용한 pair 객체 생성

// 선행 작업 함수 -> 입력받은 값을 정렬
void preliminaries(vector<string> &v)
{
	/*
	* 불필요한 부분
	* 이미 main에서 입력을 다 받았으며, 여기서는 입력을 더 받지 않기 때문.
	* 사실 상 vector에 추가되는 것이 없다.
	istream_iterator<string> input(cin);
	istream_iterator<string> eof;
	// 입력 스트림을 통해 받은 값을 vector에 push_back()
	copy(input, eof, back_inserter(v));
	*/

	// vector 내 요소에 대한 정렬을 수행.
	// 세 번째 인자로 함수 호출성 객체를 전달.
	// 이 인자가 정렬의 기준이 된다. -> 오름차순 정렬
	sort(v.begin(), v.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
}

// pair 객체를 반환받는 3가지 방법 -> 가장 큰 문자열을 반환하는 경우를 예시로
// 1) 목록 초기화를 이용하여 반환 (C++11 표준 이상)
pair<string, int> process(vector<string> &v)
{
#ifdef LIST_INIT
	if (!v.empty())
		return { v.back(), v.back().size() };
	else
		return pair<string, int>();
#else
	if (!v.empty())
		return make_pair(v.back(), v.back().size());
	else
		return pair<string, int>();
#endif
}
// 2) make_pair를 이용하여 pair 객체를 생성하여 반환
pair<string, int> process2(vector<string> &v)
{
	if (!v.empty())
		return make_pair(v.back(), v.back().size());
	else
		return pair<string, int>();
}
// 3) 명시적으로 pair 생성자를 이용하여 pair 객체를 생성하고 반환
pair<string, int> process3(vector<string> &v)
{
	if (!v.empty())
		return pair<string, int>(v.back(), v.back().size());
	else
		return pair<string, int>();
}

int main(int argc, const char *argv[])
{
	vector<string> v;
	string s;
	while (cin >> s)
		v.push_back(s);

	preliminaries(v);

	auto biggest = process(v);
	cout << biggest.first << " " << biggest.second << endl;
	biggest = process2(v);
	cout << biggest.first << " " << biggest.second << endl;
	biggest = process3(v);
	cout << biggest.first << " " << biggest.second << endl;
	return 0;
}