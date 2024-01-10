/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: map1.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: 순서 있는 연관 컨테이너에서의 키 타입에 대한 비교 함수 사용 및 map에 첨자([]) 연산을 하는 예제
* 이전 버전 내용:
*/

#include <set>
using std::multiset;

#include <map>
using std::map;

#include <string>
using std::string;

#include <utility>
using std::pair; using std::make_pair;

#include <iostream>
using std::cout; using std::endl;

#include "Sales_data.h"      
#include "make_plural.h"

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

// SDComp -> 함수 포인터
// Sales_data 객체를 비교하는 함수를 가리키는 함수 포인터가 된다.
typedef bool(*SDComp)(const Sales_data &, const Sales_data &);

// bookstore 객체는 같은 ISBN에 대해서 여러 거래 정보를 가질 수 있다.
// bookstore 객체 내의 요소는 ISBN의 순서로 정렬된다.
// 여기서는 decltype을 이용하여 함수 포인터 타입을 결정
// 생성자에는 Sales_data의 CompareIsbn 함수를 전달
// &CompareIsbn으로 써도 되지만, 함수 이름은 자동으로 포인터 변환이 되므로 아래와 같이 써도 무방함.
multiset<Sales_data, decltype(CompareIsbn) *> bookstore(CompareIsbn);

// 다른 방법으로는 람다 표현식을 사용하여 비교 조건이 되는 함수를 전달할 수도 있다.
// decltype이 아닌 타입 별칭(typedef)을 사용하여 multiset의 비교 연산을 지정
multiset<Sales_data, SDComp> bookstore2(
	// 생성자에 람다 표현식을 전달
	[](const Sales_data &l, const Sales_data &r)
	{return l.isbn() < r.isbn(); });

int main(int argc, const char* argv[])
{
	map <string, size_t> word_count; // 빈 map

	// map에 key를 "Anna"로 하는 요소를 초기화하고 삽입한다.
	// 요소의 value에는 1을 대입.
	word_count["Anna"] = 1;

	// 첨자 연산을 통해 key가 "Anna"인 값을 가져온다.
	cout << word_count["Anna"] << endl; // 1 출력

	++word_count["Anna"];        // 첨자 연산을 통해 요소를 가져와서 1을 증가시킨다.
	cout << word_count["Anna"] << endl; // 2 출력

	// word_count에 word를 추가하는 다양한 방법 
	string word;
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	word_count.insert({ word, 1 });
#endif
	word_count.insert(make_pair(word, 1)); // make_pair를 사용하여 pair 객체를 생성하거나
	word_count.insert(pair<string, size_t>(word, 1)); // pair 객체 생성자를 이용하여 생성하거나
	word_count.insert(map<string, size_t>::value_type(word, 1)); // 혹은 map의 value_type을 이용하여 생성하여 추가한다.

	typedef map<string, size_t>::value_type valType; // 또는 타입 별칭을 사용하여 간략화한 후에
	word_count.insert(valType(word, 1)); // 추가할 수도 있다.

	// insert의 반환 값을 사용하기 위해 insert_ret 변수를 선언
	pair<map<string, size_t>::iterator, bool> insert_ret;

	// 만약 "Anna"라는 key가 map 내에 없다면 value는 1로 초기화하여 추가된다.
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	insert_ret = word_count.insert({ "Anna", 1 });
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	insert_ret = word_count.insert(make_pair("Anna", 1));
#endif

	if (insert_ret.second == false)    // "Anna"인 key가 이미 map에 있을 경우, insert의 second 값은 false를 반환한다.
		insert_ret.first->second++;    // 이미 있으므로 값을 증가
	cout << word_count["Anna"] << endl; // 3이 출력 된다.

	// word_count의 첫 번째 요소의 반복자를 얻는다.
	auto map_it = word_count.begin();

	// *map_it은 pair<const string, size_t> 객체를 참조하게 된다.
	cout << map_it->first; // 해당 요소의 key를 출력
	cout << " " << map_it->second; // 해당 요소의 value를 출력
	++map_it->second;     // key는 const이므로 변경 불가, 하지만 value는 const가 아니므로 반복자를 통해 값을 변경할 수 있다.
	return 0;
}