/*
* C++ Primer - Class (클래스)
* 파일명: Debug.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: 상수 클래스 예제 - 헤더 파일
* 이전 버전 내용:
*/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#define CONSTEXPR_CTORS // C++11 이후 표준으로 지원하는 constexpr을 사용할 경우
#define CONSTEXPR_VARS

class Debug
{
private:
	bool hw;    // IO 오류를 제외한 하드웨어 오류
	bool io;    // IO 오류
	bool other; // 기타 오류

public:
#ifdef CONSTEXPR_CTORS // C++11 이후 기준
	// 생성자
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o) :
		hw(h), io(i), other(o) { }
	// 멤버 함수
	// 추가로 const 함수 선언
	constexpr bool any() const { return hw || io || other; }
	constexpr bool hardware() const { return hw || io; }
	constexpr bool app() const { return other; }
#else // C++11 표준 이전
	// 생성자
	Debug(bool b = true) : hw(b), io(b), other(b) { }
	Debug(bool h, bool i, bool o) :
		hw(h), io(i), other(o) { }
	// 멤버 함수
	bool any() const { return hw || io || other; }
	bool hardware() const { return hw || io; }
	bool app() const { return other; }
#endif
	// setter
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }

};

class HW_Subsystem
{
private:
	Debug debug;
#ifdef CONSTEXPR_CTORS // C++11 표준 이후
	constexpr static Debug enable{ true, false, false }; // 상수 클래스
#else // C++11 표준 이전
	static const Debug enable; // 상수 클래스
#endif

public:
	HW_Subsystem() : debug(false) { }          // 디버깅을 하지 않을 때의 기본 생성자
	bool field_debug() { return debug.any(); }
	bool default_debug() { return enable.any() && debug.any(); } // 여기서 any()에 const 추가를 하지 않아서 에러가 났었다.
	void set_debug(bool b) { debug.set_hw(b); }  // turn on hardware debugging

};

class IO_Subsystem
{
private:
	Debug debug;
#ifdef CONSTEXPR_CTORS // C++11 표준 이후
	constexpr static Debug enable{ true, false, true };
#else // C++11 표준 이전
	static const Debug enable;
#endif

public:
	IO_Subsystem() : debug(false) { }          // 디버깅을 하지 않을 때의 기본 생성자
	bool field_debug() { return debug.any(); }
	bool default_debug() { return enable.any() && debug.any(); }
	void set_debug(bool b) { debug.set_io(b); }  // turn on IO debugging

};
#endif