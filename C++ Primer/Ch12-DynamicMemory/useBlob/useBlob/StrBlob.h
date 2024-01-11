/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: StrBlob.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: StrBlob 클래스 정의
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;

#include <stdexcept>
using std::runtime_error;
using std::out_of_range;

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
#include <initializer_list>
using std::initializer_list;
#endif

class StrBlobPtr; // friend 선언을 위해 StrBlob 클래스보다 전방에 선언.

class StrBlob
{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const; // private member 함수
public:
	// 생성자
	StrBlob() : data(make_shared<vector<string>>()) {}
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	StrBlob(initializer_list<string> il);
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	StrBlob(string *, string *);
#endif

	// 멤버 함수
	// vector 관련 size 연산
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	// vector 관련 삽입 연산
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();

	// 요소 접근 연산
	string &front();
	string &back();
	const string& front() const;
	const string& back() const;
	
	// StrBlobPtr에 대한 interface
	// StrBlobPtr 있어야 정의할 수 있다.
	StrBlobPtr begin();
	StrBlobPtr end();
};