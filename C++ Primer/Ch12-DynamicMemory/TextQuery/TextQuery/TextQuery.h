/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: TextQuery.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-14
* 이전 버전 작성 일자: 2024-01-12
* 버전 내용: 프로그램 이해를 위한 주석 추가
* 이전 버전 내용: 본문 조회 프로그램 - TextQuery Class - 선언 및 정의
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
	// 타입 별칭을 사용하기 위해서 전방에 using(typedef) 사용.
public:
#ifdef TYPE_ALIAS_DECLS // using을 이용한 타입 별칭을 쓸 경우 (C++11 표준 이상)
	using line_no = std::vector<std::string>::size_type;
#else // using을 이용한 타입 별칭을 사용하지 않을 경우 (C++11 표준 미만)
	typedef std::vector<std::string>::size_type line_no;
#endif
	// 멤버 변수
private:
	// 여기서 저장되는 값은 동적으로 할당되는 vector<string> 컨테이너 객체다.
	// std::가 잔뜩 붙어있어 이해하기 어려울 수 있다.
	// 일단은 std를 먼저 떼어놓고 데이터 형을 보고나서 std::를 붙여주면 좋다.
	// shared_ptr<vector<string>> file 과 같은 형태로 이해하면 훨씬 편하다.
	// 여기서는 입력받은 파일을 한 줄씩 읽어 string으로 저장한 vector를 가리키는 shared_ptr이 된다.
	std::shared_ptr<std::vector<std::string>> file;
	
	// 여기서는 단어를 key로, 해당 단어를 포함하고 있는 줄의 번호를 value로 하는 map이 필요하다.
	// 단어는 유일한 key이며, value는 여러 줄에서 나올 수 있으므로 map을 사용.
	// 그리고 줄 번호는 중복될 수 없기 때문에 유일한 key를 사용하는 set를 사용한다.
	// 마찬가지로 std::가 잔뜩 붙어있어서 이해하기 어려운 부분이 좀 있다.
	// map<string, share_ptr<set<line_no>>> 이렇게 먼저 보고 나서 std::를 붙여주면 훨씬 간편하다.
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
	
	// 텍스트 표준화 함수: 구두점을 제거하고 모든 문자를 소문자로 만드는 함수
	// static 멤버이므로 모든 TextQuery 객체에서 공유를 하는 멤버 함수.
	static std::string cleanup_str(const std::string &);
public:
	TextQuery(std::ifstream &); // 생성자, 파일 입력 스트림을 받는다.
	QueryResult query(const std::string &) const; // 입력받은 단어를 통해 조회 결과를 반환하는 함수. -> 반환 값이 QueryResult.
	void display_map(); // 디버깅 보조용: map을 출력
};
#endif