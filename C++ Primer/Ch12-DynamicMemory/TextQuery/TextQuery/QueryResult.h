/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: QueryResult.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자:
* 버전 내용: 본문 조회 프로그램 - QueryResult Class - 선언 및 정의
* 이전 버전 내용:
*/

#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>

// 검색한 단어에 대한 결과를 담기 위한 Class
class QueryResult
{
	// 비멤버 함수 print -> 질의 결과를 출력하기 위한 함수
	friend std::ostream &print(std::ostream &, const QueryResult &);

public:
	typedef std::vector<std::string>::size_type line_no;
	typedef std::set<line_no>::const_iterator line_it;
private:
	std::string seek;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
public:
	// 생성자
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
		:seek(s), lines(p), file(f) {}
	std::set<line_no>::size_type size() const { return lines->size(); }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; };
};

std::ostream &print(std::ostream &, const QueryResult &);
#endif