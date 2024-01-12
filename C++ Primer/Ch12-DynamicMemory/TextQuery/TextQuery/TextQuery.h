/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: TextQuery.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자:
* 버전 내용: 본문 조회 프로그램 - TextQuery Class - 선언 및 정의
* 이전 버전 내용:
*/

#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#define TYPE_ALIAS_DECLS

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "QueryResult.h"

class QueryResult; // 전방 선언 -> 멤버 함수 query에서 반환하는 타입이 QueryResult 클래스 객체이므로
class TextQuery
{
public:
#ifdef TYPE_ALIAS_DECLS // using을 이용한 타입 별칭을 쓸 경우 (C++11 표준 이상)
	using line_no = std::vector<std::string>::size_type;
#else // using을 이용한 타입 별칭을 사용하지 않을 경우 (C++11 표준 미만)
	typedef std::vector<std::string>::size_type line_no;
#endif
private:
	// 멤버 변수
	// 입력받은 파일을 한 줄씩 읽어 string으로 저장한 vector를 가리키는 shared_ptr
	std::shared_ptr<std::vector<std::string>> file;
	// 단어가 나온 줄(line)을 담고 있는 set에 각 단어를 매핑한 map
	// 단어가 key, shared_ptr<set<line_no>>가 value
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
	// 텍스트 표준화 함수: 구두점을 제거하고 모든 문자를 소문자로 만드는 함수
	static std::string cleanup_str(const std::string &);
public:
	TextQuery(std::ifstream &); // 생성자
	QueryResult query(const std::string &) const; // 입력받은 단어를 통해 조회 결과를 반환하는 함수.
	void display_map(); // 디버깅 보조용: map을 출력
};
#endif