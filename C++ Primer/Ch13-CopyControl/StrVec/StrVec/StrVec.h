/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: StrVec.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-15
* 이전 버전 작성 일자: 2024-01-15
* 버전 내용: 이동 생성자, 이동 대입 연산자 추가
* 이전 버전 내용: 복사 제어 예제 - Vector<string> 흉내내기 - StrVec class 정의
*/
#ifndef __STRVEC_H__
#define __STRVEC_H__

#include <iostream>
#include <memory>
#include <utility>

#define INIT_LIST
#define NOEXCEPT

#ifdef INIT_LIST // C++11 표준 이상 목록 초기화를 사용하는 경우
#include <initializer_list>
#endif

// vector class와 유사한 메모리 할당 전략을 사용하는 클래스 StrVec을 구현
class StrVec
{
public:
	// 생성자 포함 복사 제어 멤버 함수들
	// 생성자, 초기값은 모두 nullptr, alloc은 암시적으로 기본 초기화.
	StrVec()
		:elements(nullptr), first_free(nullptr), cap(nullptr) { }
// 중괄호 목록 초기화를 하는 생성자
#ifdef INIT_LIST // C++11 표준 이상 목록 초기화를 사용하는 경우
	StrVec(std::initializer_list<std::string>);
#else
	StrVec(const std::string *, const std::string *);
#endif
	// 복사 연산
	// 복사 생성자
	StrVec(const StrVec &);
	// 대입 연산자 오버로딩(복사 대입)
	StrVec &operator=(const StrVec &);

	// 이동 연산
#ifdef NOEXCEPT // C++11 표준 이후 noexcept를 사용할 경우
	// 이동 생성자
	StrVec(StrVec &&) noexcept;
	// 이동 대입 연산자
	StrVec &operator=(StrVec &&) noexcept;
	// 소멸자
	~StrVec() noexcept;
#else // C++11 표준 미만 noexcept를 사용하지 않을 경우
	// 이동 생성자
	StrVec(StrVec &&) throw();
	// 이동 대입 연산자
	StrVec &operator=(StrVec &&) throw();
	// 소멸자
	~StrVec() throw();
#endif
	

	// vector에서 제공하는 기본 연산들의 멤버 함수
	// push_back -> 요소 복사 버전
	void push_back(const std::string &);
	// push_back -> 요소 이동 버전
	void push_back(std::string &&);
	// size
	size_t size() const { return first_free - elements; }
	// capacity
	size_t capacity() const { return cap - elements; }
	// begin()
	std::string *begin() const{return elements;}
	// end()
	std::string *end() const { return first_free; }
private:
	static std::allocator<std::string> alloc; // 요소의 메모리 공간을 할당하기 위한 allocator

	// utility 함수
	// chk_n_alloc
	// 요소를 추가할 때, 재할당이 필요한지 여부를 확인할 때 사용
	void chk_n_alloc()
	{
		if (size() == capacity()) // 현재 vector 내 요소 개수(size)와 할당한 메모리 공간(capacity)가 같다면
			reallocate(); // 재할당 수행
	}
	// alloc_n_copy
	// 복사 생성자, 대입 연산자, 소멸자에서 사용할 utility 함수
	std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
	void free(); // vector의 요소를 소멸, 공간을 해제하는 함수
	void reallocate(); // vector의 공간 재할당이 필요할 경우 재할당을 하는 함수
	std::string *elements; // vector의 맨 첫 요소
	std::string *first_free; // vector의 마지막 요소 다음 값
	std::string *cap; // 할당된 vector 메모리 공간의 끝 다음 위치.
};

#endif