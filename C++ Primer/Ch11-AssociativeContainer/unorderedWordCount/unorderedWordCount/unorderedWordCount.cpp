/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: unorderedWordCount.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: 순서 없는 연관 컨테이너 기본 예제 (C++11 표준 이상)
* 이전 버전 내용:
*/

#include <unordered_map>
using std::unordered_map;

#include <unordered_set>
using std::unordered_set;
using std::unordered_multiset;

#include <string>
using std::string;

using std::hash;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

#include "Sales_data.h"

#define TYPE_ALIAS_DECLS // using을 이용한 타입 별칭을 사용하는 경우 (C++11 표준 이상)

// map이 아닌 unordered_map, 순서 없는 map 기준의 word_count
int main(int argc, const char* argv[])
{
	// 단어가 발생한 횟수를 세지만, map과 달리 사전 편찬 순서가 아니다.
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
		++word_count[word];

	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

	return 0;
}

// 순서 없는 연관 컨테이너에서도 Key의 type에 조건이 있다.
// multimap의 경우에는 Key의 type이 < 연산이 가능한 순약순서가 정의되어 있어야 했다.
// 여기서도 마찬가지로 다음의 조건이 필요하다.
// 
// 1) Key는 상등 연산(==)이 가능해야 한다.
// 2) 해시 코드를 계산할 수 있어야 한다.
// 
// multimap에서 CompareIsbn을 사용했던 것과 마찬가지로 Sales_data를 키로 사용하기 위해서는 두 가지가 필요하다
// 1) 상등 연산자를 대체할 함수
// 2) 해시 코드를 계산하는 함수
// 
// 아래에는 Sales_data를 Key type으로 사용하기 위해 기본 hash와 상등 연산자로 사용할 함수를 재정의(override)한다.
size_t hasher(const Sales_data &sd)
{
	return hash<string>()(sd.isbn());
}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

// 타입 별칭을 사용하여 타입을 간소화
// 전달하는 인자로 위에서 정의한 함수를 포인터로 전달
#ifdef TYPE_ALIAS_DECLS // using을 이용한 타입 별칭을 사용하는 경우 (C++11 표준 이상)
using SD_multiset = unordered_multiset<Sales_data, decltype(hasher) *, decltype(eqOp) *>;
#else // using을 이용한 타입 별칭을 사용하지 않는 경우 (C++11 표준 미만)
typedef unordered_multiset<Sales_data, decltype(hasher) *, decltype(eqOp) *> SD_multiset;
#endif

// bookstore 객체는 같은 ISBN에 대해서 여러 Sales_data 객체를 가질 수 있음
// 전달되는 인자는 버킷의 크기, 해시 함수에 대한 포인터와 상등 연산자 함수에 대한 포인터다.
SD_multiset bookstore(42, hasher, eqOp);

// 해시 함수를 재정의 하는 방법
// 먼저, Foo 객체는 반드시 상등 연산(==)이 가능해야 한다.
struct Foo { string s; };

// 연산자 오버로딩을 이용하여 Foo 객체의 상등 연산(==)을 정의.
// 정확한 내용은 14장에서 다룬다.
bool operator==(const Foo &l, const Foo &r) { return l.s == r.s; }

// FooHash를 이용하여 해시 함수를 재정의(override)
size_t FooHash(const Foo &f) { return hash<string>()(f.s); }

// FooHash를 이용하여 해시 코드를 생성한다.
// Foo에는 상등 연산자가 정의되어 있으므로 인자로 전달할 필요는 없음.
unordered_set<Foo, decltype(FooHash) *> fooSet(10, FooHash);