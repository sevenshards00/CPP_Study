/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: TextQuery.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-14
* 이전 버전 작성 일자: 2024-01-12
* 버전 내용: 프로그램 이해를 위한 주석 추가
* 이전 버전 내용: 본문 조회 프로그램 - TextQuery Class - 생성자 및 멤버 함수 정의
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
	:file(new vector<string>) // 멤버 이니셜라이저를 이용하여 vector<string> 객체를 동적할당 한다.
{
	string text;
	
	while (getline(is, text)) // 파일의 끝(EOF)까지 한 줄씩 읽어들인다.
	{
		file->push_back(text); // 파일에서 읽어들은 한 줄의 내용을 vector에 저장
		size_t n = file->size() - 1; // 현재 줄 번호
		istringstream line(text); // 한 줄의 내용을 단어로 쪼개기 위해 istringstream 사용
		string word; // 단어를 저장하기 위한 string
		while(line >> word) // 한 문장을 단어로 하나씩 쪼갠다.
		{
			word = cleanup_str(word); // 대소문자 구분을 하지 않고, 구두점을 포함한 단어에 대한 처리 (단어 전처리)
			auto &lines = wm[word]; // lines는 shared_ptr이다. map의 key는 word이며 첨자 연산([])을 통해 map에 추가한다. 
			if (!lines) // 만약 word의 단어가 처음으로 나타나는 것이라면 이 포인터는 nullptr이다.
				lines.reset(new set<line_no>); // 그렇다면 새로운 set를 할당하고
			lines->insert(n); // 줄의 번호를 삽입한다.
		}
	}
	display_map();
}
// 입력받은 단어를 통해 조회 결과를 반환하는 함수.
QueryResult TextQuery::query(const string &seek) const
{
	// 만약 대상 단어를 찾지 못한다면 새로 할당한 set의 포인터인 nodata를 반환하게 한다.
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	// map에서 찾고자 하는 단어 seek을 find한다.
	// 첨자 연산자([])를 사용할 수도 있지만, 그럴 경우에는 해당 단어에 대해 map이 새로 추가가 되어버린다./
	// 그래서 find를 사용한 것.
	auto loc = wm.find(cleanup_str(seek));

	if (loc == wm.end()) // 만약 map의 end와 같다는 것은 찾지 못했다는 것이며
		return QueryResult(seek, nodata, file); // QueryResult의 생성자를 호출. 전달 인자는 nodata를 전달한다.
	else // 찾았다면
		return QueryResult(seek, loc->second, file); // find에 의해서 나온 map의 value를 전달한다.
		
}

// 결과 출력용 함수
ostream &print(ostream &os, const QueryResult &qr)
{
	// 단어를 찾았을 경우 찾는 단어와 찾는 단어의 횟수를 출력.
	os << qr.seek << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "times", "s") << endl;

	// 단어가 나온 각 줄을 출력
	for (auto num : *qr.lines)
		// 실제 인덱스는 0부터 시작하기 때문에 출력 시에는 1을 더한 값을 출력.
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;

	return os;
}
// 디버깅 보조용: map을 출력
// 책에서는 다루지 않는다.
void TextQuery::display_map()
{
	// map의 반복자
	auto iter_begin = wm.cbegin();
	auto iter_end = wm.cend();

	// map을 처음부터 끝까지 각 단어에 대해서 조회.
	for (; iter_begin != iter_end; ++iter_begin)
	{
		// 먼저 단어(key)를 출력하고
		cout << "word: " << iter_begin->first << " {";

		
		auto text_locs = iter_begin->second; // 단어가 나오는 줄의 위치(value)
		// set의 반복자
		auto loc_iter_begin = text_locs->cbegin();
		auto loc_iter_end = text_locs->cend();

		// 반복자를 이용하여 해당 단어가 나오는 모든 줄 번호를 출력한다.
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