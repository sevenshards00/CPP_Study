/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: elimDups.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 사전 편찬순 정렬, 길이 순 정렬, 문장 내 중복 단어 삭제 예제
* 이전 버전 내용:
*/

#include <algorithm>
using std::sort;
using std::for_each;

#include <functional>
using std::bind;
using namespace std::placeholders;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 단어의 길이를 비교, 짧은 단어 순서대로 정렬하기 위한 함수
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

// less than
bool LT(const string &s1, const string &s2)
{
	return s1 < s2;
}

void print(const vector<string> &words)
{
	// vector의 각 string을 출력.
	// for_each를 사용
	// 세 번쨰 인자에 함수 호출성 객체를 취한다.
	// 각 요소에 대해 해당 객체를 호출
	for_each(words.begin(), words.end(),
		[](const string &s) { cout << s << " "; });
	cout << endl;
}

int main(int argc, const char *argv[])
{
	vector<string> words;

	string next_word;
	while (cin >> next_word)
		words.push_back(next_word);

	print(words);

	vector<string> cpy = words;

	// sort에서는 string의 '<' 연산자를 이용하여 요소를 비교
	sort(words.begin(), words.end());
	print(words);

	words = cpy;

	// sort의 세 번째 인자로 함수 호출성 객체를 취하는 경우
	// 이전과 큰 차이가 없는 경우
	sort(words.begin(), words.end(), LT);
	print(words);

	words = cpy;

	// 단어를 정렬하고 중복을 제거하는 경우
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
	// 중복을 제거한 이후, 알파벳 순서는 유지한 상태에서 길이에 따른 정렬
	stable_sort(words.begin(), words.end(), isShorter);
	print(words);

	words = cpy;
	// sort의 세 번째 인자로 함수 호출성 객체를 받는다.
	// 해당 함수가 정렬의 기준.
	// 짧은 단어 순서대로 정렬이 된다.
	sort(words.begin(), words.end(), isShorter);
	print(words);

	// bind를 이용하여 매개변수를 재배열 하는 경우
	// 이 경우에는 반대로 긴 단어부터 짧은 단어 순으로 내림차순이 된다.
	sort(words.begin(), words.end(), bind(isShorter, _2, _1));
	print(words);

	words = cpy;
	return 0;
}