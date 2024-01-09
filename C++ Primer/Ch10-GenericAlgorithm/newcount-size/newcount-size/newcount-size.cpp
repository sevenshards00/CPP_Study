/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: newcount-size.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 문장 내 중복 단어 삭제 및 일정 크기 이상의 단어 개수를 구하는 예제
* 이전 버전 내용:
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

#include "make_plural.h"

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

// 컨테이너 내에 중복되는 요소를 제거하기 위한 함수(eliminate duplicates)
void elimDups(vector<string> &words)
{
	// 컨테이너 내의 단어를 정렬한다.
	sort(words.begin(), words.end());
	// 이후 각각의 요소에 대해서 출력 (for_each)
	// for_each는 세 번째 인자로 함수 호출성 객체를 받는다.
	// 여기서는 람다 표현식을 사용.
	for_each(words.begin(), words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;

	// 중복되는 단어들에 대해 재정렬 수행.
	// unique에 의해 반환되는 값은 중복되지 않는 요소 범위의 하나 지난 위치의 반복자를 반환
	auto end_unique = unique(words.begin(), words.end());
	for_each(words.begin(), words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;

	// 중복되는 단어를 삭제한다.
	// 시작하는 반복자 위치는 중복되는 단어의 시작점.
	words.erase(end_unique, words.end());
	for_each(words.begin(), words.end(),
		[](const string &s) {cout << s << " "; });
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
	// 람다 표현식을 이용하여 단어의 길이를 비교
	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b)
		{ return a.size() < b.size(); });

	// 요소 중에서 sz의 크기 이상인 첫 번째 요소의 반복자를 반환
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a) {return a.size() >= sz; });

	// 단어의 길이가 sz 이상인 요소의 수를 계산
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;

	// 지정한 크기 이상의 단어를 출력한다.
	for_each(wc, words.end(),
		[](const string &s) {cout << s << " "; });

	cout << endl;
}

// 단어의 크기를 확인하는 함수
bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

int main(int argc, const char *argv[])
{
	vector<string> words;

	string next_word;
	while (cin >> next_word)
		words.push_back(next_word);

	biggies(words, 5); // biggies를 사용한 경우

	size_t sz = 5;
	// 람다 표현식이 아닌 bind를 사용한 경우(C++11 표준 이후)
	// find_if는 단항 술어 함수를 인자로 요구
	// 그래서 함수 호출성 객체인 람다 표현식을 사용하거나, bind를 이용하여 단항 술어 함수처럼 인자로 사용.
	// 위에 있는 check_size는 이항 술어 함수.
	// bind를 이용하면 매개변수를 변형한 새로운 함수 호출성 객체를 생성.
	// _1은 첫 번째 매개 변수 위치 지정자(placeholder)
	// 앞에 있는 words의 string을 check_size의 첫 번째 매개변수로 받게 된다.
	auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;

	return 0;
}