/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: restricted_count.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: set 기본 예제 - 단어 세기 + 특정 단어 제외
* 이전 버전 내용:
*/

#include <map>
using std::map;

#include <set>
using std::set;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

#ifndef LIST_INIT // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
#include <iterator>
using std::begin;
using std::end;
#endif

int main(int argc, const char *argv[])
{
	map<string, size_t> word_count;
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	set<string> exclude = { "The", "But", "And", "Or", "An", "A",
							"the", "but", "and", "or", "an", "a" };
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	string temp[] = { "The", "But", "And", "Or", "An", "A",
					  "the", "but", "and", "or", "an", "a" };
	set<string> exclude(begin(temp), end(temp));
#endif

	string word;

	// set을 이용하여 해당 set에 있는 단어는 제외한다.
	// 조건식에서 word에 있는 단어가 exclude의 end와 상등이라면 set 내의 단어와 일치하지 않는 다는 것
	// 그래서 key를 추가하고 value를 증가.
	while (cin >> word)
		if (exclude.find(word) == exclude.end())
			++word_count[word];

	// 출력에서 3항 연산자를 사용하여 단어의 사용 횟수가 1을 넘을 경우 출력 여부를 추가.
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

	return 0;
}