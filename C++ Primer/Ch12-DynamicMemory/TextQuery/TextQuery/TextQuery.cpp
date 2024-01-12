/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: TextQuery.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자:
* 버전 내용: 본문 조회 프로그램 - TextQuery Class - 생성자 및 멤버 함수 정의
* 이전 버전 내용:
*/

#include <cstddef>
#include <memory>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;

#include "TextQuery.h"
#include "make_plural.h"

// 생성자
// 입력 파일을 읽고 줄의 내용을 줄 번호에 매핑한 map을 생성한다.
TextQuery::TextQuery(ifstream &is)
	:file(new vector<string>)
{
	string text;
	// 파일의 끝(EOF)까지 한 줄씩 읽어들인다.
	while (getline(is, text))
	{
		file->push_back(text); // 파일에서 읽어들은 한 줄의 내용을 vector에 저장
		size_t n = file->size() - 1; // 현재 줄 번호
		istringstream line(text); // 한 줄의 내용을 단어로 쪼개기 위해 istringstream 사용
		string word; // 단어를 저장하기 위한 string
		while(line >> word) // 한 문장을 단어로 하나씩 쪼갠다.
		{
			word = cleanup_str(word); // 대소문자 구분을 하지 않고, 구두점을 포함한 단어에 대한 처리 (단어 전처리)
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
// 입력받은 단어를 통해 조회 결과를 반환하는 함수.
QueryResult TextQuery::query(const string &seek) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(cleanup_str(seek));

	if (loc == wm.end())
		return QueryResult(seek, nodata, file);
	else
		return QueryResult(seek, loc->second, file);
		
}

// 결과 출력용 함수
ostream &print(ostream &os, const QueryResult &qr)
{
	os << qr.seek << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "times", "s") << endl;

	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;

	return os;
}
// 디버깅 보조용: map을 출력
void TextQuery::display_map()
{
	auto iter_begin = wm.cbegin();
	auto iter_end = wm.end();

	for (; iter_begin != iter_end; ++iter_begin)
	{
		cout << "word: " << iter_begin->first << " {";

		auto text_locs = iter_begin->second;
		auto loc_iter_begin = text_locs->cbegin();
		auto loc_iter_end = text_locs->cend();

		while (loc_iter_begin != loc_iter_end)
		{
			cout << *loc_iter_begin;
			
			if (++loc_iter_begin != loc_iter_end)
				cout << ", ";
		}

		cout << "}\n";
	}
	cout << endl;
}

// 텍스트 표준화 함수: 구두점을 제거하고 모든 문자를 소문자로 만드는 함수
// 책에서는 다루지 않는 부분
// 구두점과 모든 문자를 소문자로 변경.
// Query(질의)에 대해서 대소문자를 구분하지 않고 동작하게 됨.
// 간단하게 요약해서 입력받은 값을 대소문자 구분하지 않고, 구두점들을 제외한 단어만 추려내는 함수.
// 함수 선언때 static으로 선언했기 때문에 여기서는 static 키워드가 빠져도 된다.
string TextQuery::cleanup_str(const std::string &word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it)
	{
		if (!ispunct(*it))
			ret += tolower(*it);
	}

	return ret;
}