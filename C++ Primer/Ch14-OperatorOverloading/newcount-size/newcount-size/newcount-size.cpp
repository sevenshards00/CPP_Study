/*
* C++ Primer - Overloaded Operations & Conversions (다중 정의 연산과 변환)
* 파일명: newcount-size.cpp
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-18
* 이전 버전 작성 일자: 2024-01-09
* 버전 내용: 함수 호출 연산자 오버로딩과 함수 호출 객체(Functor) 추가
* 이전 버전 내용: 문장 내 중복 단어 삭제 및 일정 크기 이상의 단어 개수를 구하는 예제
*/

#include <algorithm>
using std::find_if;
using std::for_each;
using std::sort;
using std::stable_sort;
using std::unique;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <cstddef>
using std::size_t;

#include <functional>
using std::bind;
// using std::placeholders::_1;
// 위치 지정자(placeholder)를 매번 번거롭게 지정할 수는 없으므로 몇 개만 사용한다면 위처럼
// 그게 아니라면 아래처럼 using namespace 선언을 사용하여 다 갖다 쓴다.
using namespace std::placeholders;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include "make_plural.h"

#define DELETED_FCNS // 삭제된 함수(delete)를 사용할 경우 (C++11 표준 이상)
#define DEFAULT_FCNS // 기본(default) 생성자 또는 소멸자를 사용할 경우 (C++11 표준 이상)

// 단어 길이를 비교하는 함수.
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
// 단어의 길이가 m 이상인지 (greater than) 판별하기 위한 함수
bool GT(const string &s, string::size_type m)
{
	return s.size() >= m;
}

// 크기 비교를 하기 위한 함수 객체(Functor)
class SizeComp
{
public:
#ifdef DELETED_FCNS // 삭제된 함수(delete)를 사용할 경우 (C++11 표준 이상)
	SizeComp() = delete; // 기본 생성자를 사용하지 않음
	SizeComp &operator=(const SizeComp &) = delete; // 대입 연산을 사용하지 않겠다는 것
#else // 삭제된 함수(delete)를 사용하지 않을 경우 (C++11 표준 미만) 
	// private 생성자와 멤버 함수로 만들어서 호출되지 않도록 함.
private:
	SizeComp();
	SizeComp &operator=(const SizeComp &);
#endif
#ifdef DEFAULT_FCNS // 기본(default) 생성자 또는 소멸자를 사용할 경우 (C++11 표준 이상)
	~SizeComp() = default;
#else // 기본(default) 생성자 또는 소멸자를 사용하지 않을 경우 (C++11 표준 미만)
	~SizeComp() {}
#endif
	// 생성자
	SizeComp(size_t n) :sz(n) {}
	// 함수 호출 연산자 오버로딩
	bool operator()(const string &s) const
	{
		return s.size() >= sz;
	}

private:
	size_t sz;
};

// 화면에 문자열을 출력해주는 함수 객체(Functor)
class PrintString
{
public:
#ifdef DELETED_FCNS
	PrintString() = delete; // 기본 생성자를 사용하지 않음
	// #else는 필요하지 않다.
	// 왜냐하면 PrintString은 디폴트 생성자가 생기지 않는다.
	// 이미 다른 생성자를 가지고 있기 때문.
#endif
	// 생성자
	PrintString(ostream &o) :os(o) {}
	// 함수 호출 연산자 오버로딩
	void operator()(const string &s) const
	{
		os << s << " ";
	}
private:
	ostream &os;
};

// 문자열의 길이를 비교하기 위한 함수 객체(Functor)
class ShorterString
{
public:
	bool operator()(const string &s1, const string &s2) const
	{
		return s1.size() < s2.size();
	}
};

// 컨테이너 내에 중복되는 요소를 제거하기 위한 함수(eliminate duplicates)
void elimDups(vector<string> &words)
{
	// 컨테이너 내의 단어를 정렬한다.
	sort(words.begin(), words.end());
	// 이후 각각의 요소에 대해서 출력 (for_each)
	// for_each는 세 번째 인자로 함수 호출성 객체를 받는다.
	// 람다 표현식을 함수 객체 Printstring으로 대체
	for_each(words.begin(), words.end(), PrintString(cout));
	cout << endl;

	// 중복되는 단어들에 대해 재정렬 수행.
	// unique에 의해 반환되는 값은 중복되지 않는 요소 범위의 하나 지난 위치의 반복자를 반환
	auto end_unique = unique(words.begin(), words.end());
	
	for_each(words.begin(), words.end(), PrintString(cout));
	cout << endl;

	// 중복되는 단어를 삭제한다.
	// 시작하는 반복자 위치는 중복되는 단어의 시작점.
	words.erase(end_unique, words.end());
	for_each(words.begin(), words.end(), PrintString(cout));
	cout << endl;
}

// 지정한 크기 이상의 단어만 출력하기 위함 함수
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words); // 중복되는 단어 제거 + 사전 편찬 순 단어 정렬
	// words를 크기 순으로 정렬하되 길이가 같은 요소끼리 사전 편찬 순을 유지
	// stable_sort를 사용 -> 상등한 요소 사이의 원래 순서를 유지하며 정렬
	// 정렬한 순차열에서는 상등인 요소 사이에 상대적 순서는 의미가 없다 -> 어차피 상등하므로
	// 여기서의 상등함 == 길이가 같음
	// 길이가 같더라도 단어의 내용에 따라 순서는 다를 수 있으므로 stable_sort를 사용
	// 세 번째 인자로 함수 호출성 객체를 받는다.
	// 람다 표현식을 함수 객체 ShorterString으로 변경
	stable_sort(words.begin(), words.end(), ShorterString());

	// 요소 중에서 sz의 크기 이상인 첫 번째 요소의 반복자를 반환
	// 람다를 SizeComp로 변경
	auto wc = find_if(words.begin(), words.end(), SizeComp(sz));

	// 단어의 길이가 sz 이상인 요소의 수를 계산
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;

	// 지정한 크기 이상의 단어를 출력한다.
	// 람다를 PrintString으로 변경
	for_each(wc, words.end(), PrintString(cout));

	cout << endl;
}

int main(int argc, const char *argv[])
{
	vector<string> words;

	string next_word;
	while (cin >> next_word)
		words.push_back(next_word);

	biggies(words, 6);
	return 0;
}