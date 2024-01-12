/*
* C++ Primer - Class (클래스)
* 파일명: Screen.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자: 2024-01-06
* 버전 내용: using 선언 제거
* 이전 버전 내용: 추가적인 클래스 기능 - Screen 헤더 파일
*/

#include <string>
#include <iostream>

#define IN_CLASS_INITS // 클래스 내 초기화 사용
#define DEFAULT_FCNS // C++11 표준 기본 생성자 사용

class Screen
{
public:
	typedef std::string::size_type pos; // 타입 멤버 정의
private:
	static const char bkground = ' ';
#ifdef IN_CLASS_INITS // 클래스 내 초기화를 사용할 경우
	pos cursor = 0;
	pos height = 0, width = 0;
#else
	pos cursor;
	pos height, width;
#endif
	std::string contents;
	// 화면에 표시하는 작업을 수행하는 멤버 함수 (private)
	void do_display(std::ostream& os) const { os << contents; }
public:
	// 클래스 내 초기화를 사용할 경우 + C++11 표준 기본 생성자 사용할 경우
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
	Screen() = default; // Screen에 다른 생성자도 있으므로 기본 생성자를 사용할 경우 필요
#else // 아닐 경우 -> 멤버 이니셜라이저 사용
	Screen() : cursor(0), height(0), width(0) { }
#endif
	Screen(pos ht, pos wd, char c) // 세 개의 인자를 받는 생성자
		:height(ht), width(wd), contents(ht* wd, c) { }
	friend class Window_mgr; // friend 선언 -> Window_mgr 클래스에서 Screen 클래스의 private 멤버에 접근 가능
	Screen(pos ht = 0, pos wd = 0) // 두 개의 인자를 받는 생성자
		:cursor(0), height(ht), width(wd), contents(ht* wd, ' ') { }

	// 엑세스 함수
	// getter
	char get() const { return contents[cursor]; } // 묵시적 inline
	inline char get(pos ht, pos wd) const; // getter(const) -> const에 의해서 함수 오버로딩 가능, 명시적 inline

	// setter
	Screen& set(char);
	Screen& set(pos, pos, char);

	// 멤버 함수
	Screen& clear(char = bkground);
	Screen& move(pos r, pos c); // 외부 정의에서 inline화 가능

	// 멤버 함수 중 private 멤버 함수를 이용
	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	// 객체에 대해 const 여부 또한 함수 오버로딩 가능
	const Screen& display(std::ostream& os) const
	{
		do_display(os);
		return *this;
	}
};

// 클래스 외부에서 함수 정의
// 별도의 소스파일로 만들어도 된다.
Screen& Screen::clear(char c)
{
	contents = std::string(height * width, c);
	return *this;
}

// 클래스 외부에서 정의할 때 inline 선언을 명시적으로 할 수 있다.
inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width; // 행의 위치를 계산하고
	cursor = row + c; // 커서를 해당 행의 열로 이동
	return *this; // 마지막으로 객체 자체를 반환(*this)
}

// 클래스 내에서 inline 선언을 하였으므로 여기서 inline 선언을 추가할 필요 없음
char Screen::get(pos r, pos c) const
{
	pos row = r * width; // 행의 위치를 계산하고
	return contents[row + c]; // 주어진 열의 문자를 반환한다.
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c; // 현재 커서 위치에 새로운 값을 설정
	return *this; // 객체 자체를 반환
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch; // 지정한 위치에 주어진 값을 설정
	return *this; // 객체 자체를 반환
}