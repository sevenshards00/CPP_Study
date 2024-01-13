/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: QueryResult.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-14
* 이전 버전 작성 일자: 2024-01-12
* 버전 내용: 프로그램 이해를 위한 주석 추가
* 이전 버전 내용: 본문 조회 프로그램 - QueryResult Class - 선언 및 정의
*/

#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>


// 어제 부랴부랴 내용만 나가다보니 정리가 안되었던 내용인데, 천천히 보니 이해가 되었다.
// 특히 shared_ptr을 왜 썼는지에 대한 이유가 납득이 되지 않았었던 것이 크다.
// 거기에 대해서 좀 정리를 하고 넘어가려고 한다.

// 검색한 단어에 대한 결과를 담기 위한 Class 
class QueryResult
{
	// 비멤버 함수 print -> 질의 결과를 출력하기 위한 함수
	// friend 선언을 추가하여 QueryResult 객체의 멤버에 접근할 수 있다.
	friend std::ostream &print(std::ostream &, const QueryResult &);
	
	// 타입 별칭 사용.
public:
	typedef std::vector<std::string>::size_type line_no; // line 번호
	typedef std::set<line_no>::const_iterator line_it; // set의 const 반복자.
private:
	// 여기서 shared_ptr을 사용한 이유를 좀 정리하고 넘어가려고 한다.
	// 저자의 의도를 내가 잘 이해한 것인지는 모르겠지만, 나름대로 정리를 해보면 다음과 같다.
	//  
	// 1) 기본 자료형(내장 타입)이 아닌 객체를 주고 받는다.
	// 우선 이 프로그램은 Call-by-value를 하기에는 효율적이지 못하다.
	// 단순한 기본 자료형(내장 타입)의 복사라면 모를까, 객체(Object)를 복사해서 가져와야 하는 상황이다.
	// 객체의 복사는 굉장히 느리며, 성능면에서 좋은 선택지가 아니다.
	// 
	// 2) 데이터는 일부만 필요하다.
	// QueryResult라는 클래스는 TextQuery 클래스에 의존적이다.
	// TextQuery에 있는 일부분의 데이터만 가지고 객체를 만들어내기 때문.
	// 그래서 TextQuery의 '모든' 데이터가 필요한 것이 아니라 '일부'만 사용하면 된다.
	// 그렇기 때문에 반복자나 포인터를 사용하면 복사를 사용하는 문제는 해결이 된다.
	// 
	// 3) '공유'를 하면서 '소멸 시점을 동기화해야 한다'
	// 어떻게 보면 이게 shared_ptr을 사용하는 가장 큰 이유가 된다.
	// 반복자나 포인터를 사용하게 되면 한 가지 고려를 해야될 것이 있다.
	// 바로 QueryResult가 처리되기 전에 TextQuery가 소멸하게 된다는 문제다
	// QueryResult에서 가리키는 값은 더 이상 존재하지 않는 객체의 데이터를 참조하는 꼴이 된다. (허상 포인터, Dangling Poiter)
	// 그래서 TextQuery와 QueryResult의 생명주기를 동기화하기 위해서 '공유'를 하고 거기에 가장 적합한 것이 share_ptr이 되는 것이다.

	std::string seek; // 찾는 대상 단어.
	std::shared_ptr<std::set<line_no>> lines; // TextQuery의 set 객체를 가리키는 shared_ptr
	std::shared_ptr<std::vector<std::string>> file; // TextQuery의 vector<string> 객체를 가리키는 포인터.
public:
	// 생성자
	// std::가 많아서 굉장히 난해하게 보일 수 있다.
	// 떼어놓고 보면 한결 수월하게 보인다.
	// QueryResult(string s, shared_ptr<set<line_no>> p, share_ptr<vector<string>> f)
	// 멤버 이니셜라이저를 이용하여 멤버 변수를 초기화한다.
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
		:seek(s), lines(p), file(f) {}

	// 엑세스 함수
	// set의 size() 멤버 함수를 사용하기 위해서 size()를 정의
	std::set<line_no>::size_type size() const { return lines->size(); }
	// set의 반복자를 사용하기 위해 begin과 end를 정의
	// 값의 변경은 하지 않을 것이므로 const 반복자를 취한다.
	line_it begin() const { return lines->cbegin(); }
	line_it end() const { return lines->cend(); }
	// 입력된 file의 포인터를 받아오기 위한 함수. (getter)
	std::shared_ptr<std::vector<std::string>> get_file() { return file; };
};

// friend로 선언된 비멤버 함수를 선언
std::ostream &print(std::ostream &, const QueryResult &);
#endif