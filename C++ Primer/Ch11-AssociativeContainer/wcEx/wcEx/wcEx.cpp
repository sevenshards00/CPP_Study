/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: wcEx.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: map에 요소를 추가하는 예제 - insert
* 이전 버전 내용:
*/

#include <map>
using std::map;

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

int main(int argc, const char *argv[])
{
    // 입력을 통해 각 단어가 몇 번 사용되었는지를 센다.
    map<string, size_t> word_count; // <string, size_t> pair로 되어있는 빈 map을 생성
    string word;
    while (cin >> word)
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
        // insert를 수행하면 삽입 여부를 알려주는 pair를 반환
        // first에는 지정한 키의 요소에 대한 반복자
        // second에는 요소를 삽입했는지 아니면 이미 존재하고 있었는지에 여부에 대한 bool값을 반환
        // 아래의 insert를 해석하면 다음과 같이 볼 수 있다.
        // pair {word, 0}에 대한 값을 삽입하고, 그 key에 대한 반복자 first를 이용하여 key에 대한 value(second)의 값을 증가시키는 것.
        ++word_count.insert({ word, 0 }).first->second;
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
        ++word_count.insert(make_pair(word, 0)).first->second;
#endif

    // 반복자를 이용하여 map의 처음부터 끝까지 출력하는 첫 번째 방법
    for (auto it = word_count.cbegin(); it != word_count.cend(); ++it) {
        // w에 반복자 역참조
        auto w = *it;
        cout << w.first << " occurs " << w.second << " times" << endl;
    }

    // 반복자를 이용하여 map의 처음부터 끝까지 출력하는 두 번째 방법
    // 사실 위와 큰 차이는 없고 while을 사용해서 map의 각 요소에 접근
    auto map_it = word_count.cbegin();
    while (map_it != word_count.cend()) {
        // 반복자를 통해 각 요소에 역참조하여 출력
        cout << map_it->first << " occurs " << map_it->second << " times" << endl;
        ++map_it;  // 다음 요소를 가리키기 위해 반복자 증가
    }

    return 0;
}