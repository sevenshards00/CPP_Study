/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: StrBlob.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: StrBlob 클래스에서 share_ptr, weak_ptr 사용 예제 - StrBlob, StrBlobPtr클래스 정의
* 이전 버전 내용:
*/

#ifndef __STRBLOB_H__
#define __STRBLOB_H__

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


// shared_ptr을 사용한 StrBlob 클래스
class StrBlob
{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
private:
	shared_ptr<vector<string>> data; // vector<string>을 가리키는 shared_ptr 변수
	void check(size_type i, const string &msg) const; // 현재 지정한 색인을 벗어났는지 확인하기 위한 함수
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

	// vector의 요소 접근 연산
	string &front();
	string &back();
	const string& front() const;
	const string& back() const;
	
	// StrBlobPtr에 대한 interface
	// StrBlobPtr가 있어야 정의할 수 있다.
	StrBlobPtr begin();
	StrBlobPtr end();
};

// StrBlob 클래스의 멤버 함수 정의
// 생성자 정의
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
inline StrBlob::StrBlob(initializer_list<string> il)
	:data(make_shared<vector<string>>(il)) {}
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
inline StrBlob::StrBlob(string *b, string *e)
	: data(make_shared<vector<string>>(b, e)) { }
#endif

// 현재 지정한 색인을 벗어났는지 확인하기 위한 함수
void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size()) // 현재 입력받은 index가 vector의 크기(범위)를 벗어났다면
		throw out_of_range(msg); // 범위를 벗어났음을 알리는 예외를 발생시킨다.
}

// vector의 요소 접근 연산
string& StrBlob::front()
{
	check(0, "front on empty StrBlob"); // 0과 함께 예외 발생 시 전달할 메세지를 전달.
	return data->front(); // 예외가 발생하지 않는다면 return을 통해 vector의 front연산을 수행
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob"); // 0과 함께 예외 발생 시 전달할 메세지를 전달.
	return data->back(); // 예외가 발생하지 않는다면 return을 통해 vector의 back연산을 수행
}
// const 버전
const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob"); // 0과 함께 예외 발생 시 전달할 메세지를 전달.
	return data->front(); // 예외가 발생하지 않는다면 return을 통해 vector의 front연산을 수행
}
const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob"); // 0과 함께 예외 발생 시 전달할 메세지를 전달.
	return data->back(); // 예외가 발생하지 않는다면 return을 통해 vector의 back연산을 수행
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob"); // 0과 함께 예외 발생 시 전달할 메세지를 전달.
	return data->pop_back(); // 예외가 발생하지 않는다면 return을 통해 vector의 pop_back연산을 수행
}


// weak_ptr을 이용한 클래스 StrBlobPtr
// weak_ptr은 shared_ptr로 관리하는 객체를 가리킬 수 있다.
// 다만 참조 횟수(reference count)에 영향을 주지 않는 '약한' 공유를 하는 포인터라서 weak_ptr이라 한다.
// StrBlobPtr 클래스는 StrBlob에서 존재하지 않는 vector에 접근하는 것을 막을 수 있다.
// 이미 동적 할당된 메모리가 헤제된 shared_ptr에 잘못 접근하는 것을 막기 위해 weak_ptr을 사용할 수 있다.
class StrBlobPtr
{
	// 현 시점 기준에서는 연산자 오버로딩에 대한 개념을 설명하지 않았으므로, 별도의 함수로 정의.
	// 상등연산자(==)의 역할을 수행하는 함수
	// 비멤버 함수, friend 선언을 통해서 StrBlobPtr에 있는 멤버에 접근 가능하다.
	friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
private:
	shared_ptr<vector<string>> check(size_t, const string &) const; // 대상으로 가리키는 vector가 존재하는지 확인하는 함수
	weak_ptr<vector<string>> wptr; // weak_ptr 변수
	size_t curr; // vector 내의 현재 위치(인덱스)
public:
	// 생성자
	StrBlobPtr():curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

	// 마찬가지로 현 시점에서 연산자 오버로딩에 대한 개념을 설명하지 않았음
	// 그래서 역참조와 전위 증가, 전위 감소에 대한 것을 아래의 함수로 선언.
	string& deref() const;
	StrBlobPtr& incr();
	StrBlobPtr& decr();
};

// StrBlobPtr 클래스의 멤버 함수 정의
// 역참조 연산자(dereference)의 역할을 하는 함수
inline string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end"); // 현재 인덱스가 끝을 지나서 참조할 경우 예외 발생.
	return (*p)[curr]; // 그게 아니라면 vector의 인덱스 접근.
}
// StrBlobPtr 클래스의 check 함수
// 여기서는 StrBlob의 check와 달리 하나를 더 확인한다.
inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock(); // 현재 shared_ptr이 가리키는 vector가 아직 존재하는지를 확인.
	if (!ret) // vector가 존재하지 않는다면 이미 할당이 해제된 것으로 NULL shared_ptr이 반환됨
		throw runtime_error("unbound StrBlobPtr"); // runtime_error 예외를 발생시킨다. 없는 영역을 참조하려 했기 떄문

	// 이 부분은 StrBlob의 check와 동일.
	if (i >= ret->size())
		throw out_of_range(msg);
	
	return ret; // 문제가 없다면 vector를 가리키는 weak_ptr을 반환.
}

// 전위 증가 연산자 역할을 하는 함수
inline StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr"); // 끝을 지난 위치인지 확인하기 위해 check 함수 호출
	++curr; // 아니라면 다음 위치로 이동
	return *this; // 문제가 없다면 반환.
}

// 후위 증가 연산자 역할을 하는 함수
inline StrBlobPtr &StrBlobPtr::decr()
{
	// 만약 curr가 0이라면, 감소했을 때 유효하지 않은 첨자([]) 연산을 하게 됨
	--curr; // 우선 현재 인덱스에서 하나를 감소
	check(-1, "decrement past begin of StrBlobPtr"); // 시작보다 이전 위치인지 확인하기 위해 check 함수 호출
	return *this; // 문제가 없다면 반환.

}

// StrBlobPtr을 정의한 이후 만든 함수
// StrBlob의 멤버함수로, vector의 begin과 end 연산을 대신하는 함수
inline StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

// 상등 연산자(==)를 대신하는 함수
inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	// 두 vector가 존재하는지 먼저 확인한다
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();

	if (l == r) // 둘이 같다면 -> 둘 다 null이거나, vector 내에서 같은 요소를 가리키고 있을 수 있음
		return (!r || lhs.curr == rhs.curr);
	else
		return false; // 그게 아니라면 다른 vector를 가리키고 있는 것.
}

// 상등 연산자(!=)를 대신하는 함수
inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	// eq(==)를 구현했기 때문에 이에 반대되는 결과를 취하면 '!='을 한 것과 같아진다.
	return !eq(lhs, rhs);
}
#endif