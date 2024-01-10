/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: erasemap.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: 연관 컨테이너에서 요소를 삭제하는 예제
* 이전 버전 내용:
*/

#include <map>
using std::map;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	map<string, size_t> word_count;  // <string, size_t>에 대한 빈 map
	string word;
	// 단어를 읽어들여서 map에 추가한다.
	while (cin >> word)
		++word_count[word];

	string removal_word = "the"; // 삭제 대상 단어

	// map에서 요소를 제거하는 두 가지 방법
	// 1. key를 사용
	// erase에 key를 전달하면 삭제한 요소 수가 반환
	// map이나 set의 경우, key는 유일하므로 0 또는 1이 반환
	// key의 중복을 허용하는 multimap, multiset에서는 2 이상일 수도 있음.
	if (word_count.erase(removal_word))
		cout << "ok: " << removal_word << " removed\n";
	else
		cout << "oops: " << removal_word << " not found!\n";

	// 2. 지울 대상을 가리키는 반복자를 이용
	removal_word = "The";  // 문자열은 대소문자를 구분하므로 "The"는 "the"와 다르다
	map<string, size_t>::iterator where;
	where = word_count.find(removal_word);  // find를 이용하여 해당 요소를 찾는다.

	if (where == word_count.end()) // 만약 find에 의해 map의 끝을 가리킨다면
		cout << "oops: " << removal_word << " not found!\n"; // 삭제 대상을 찾지 못한 것
	else {
		word_count.erase(where);   // 반복자에 의한 erase는 void를 반환한다.
		cout << "ok: " << removal_word << " removed!\n";
	}
	return 0;
}