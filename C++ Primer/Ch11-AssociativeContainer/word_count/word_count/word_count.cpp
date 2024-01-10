/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: word_count.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: map 기본 예제 - 단어 세기
* 이전 버전 내용:
*/

#include <map>
using std::map;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	map<string, size_t> word_count; // string을 키, size_t를 값으로 갖는 빈 map을 생성
	string word;
	
	// 첨자 연산을 이용하여 해당 key에 대한 value를 증가.
	// 만약 key가 map에 없다면 값을 0인 요소를 새로 생성.
	while (cin >> word)
		++word_count[word]; 

	// 범위 for문을 이용하여 map의 key와 value를 출력
	// map에서 가져온 요소는 pair 타입 객체다.
	// 멤버 변수 first는 key, second는 value
	// public 멤버이므로 아래와 같이 바로 접근 가능.
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second << " times" << endl;

	// 반복자를 이용하여 map의 key와 value를 출력하는 경우
	auto map_it = word_count.cbegin();
	while (map_it != word_count.cend())
	{
		cout << map_it->first << " occurs " << map_it->second << " times" << endl;
		++map_it;
	}

	return 0;
}