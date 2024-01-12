/*
* C++ Primer - Class (클래스)
* 파일명: WindowMgr.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: 추가적인 클래스 기능 - WindowMgr 헤더 파일
* 이전 버전 내용:
*/

#ifndef __WINDOW_MGR__
#define __WINDOW_MGR__

#include <vector>
#include <string>
#include <iostream>

#include "Screen.h"

class BitMap;

// BitMap 클래스의 storeOn 함수 오버로딩
extern std::ostream& storeOn(std::ostream&, Screen&);
extern BitMap& storeOn(BitMap&, Screen&);

class Window_mgr
{
private:
	// Windows_mgr이 기본으로 설정하는 Screen.
	// Windows_mgr에서는 24x80의 빈 화면을 가진다.
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
public:
	// 창의 각 화면에 대한 위치 ID
	using ScreenIndex = std::vector<Screen>::size_type;

	// Screen을 추가하고 해당 인덱스를 반환하는 함수
	ScreenIndex addScreen(const Screen&);

	// 현재 인덱스의 Screen을 모두 공백으로 설정
	void clear(ScreenIndex);

	// Screen의 크기를 변경
	void resize(Screen::pos r, Screen::pos c, ScreenIndex i);
};

// 반환 타입은 Window_mgr의 범위에 들어가기 전에 표시
inline
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

inline
void Window_mgr::clear(ScreenIndex i)
{
	// s는 clear하기 원하는 Screen에 대한 참조자
	Screen& s = screens[i];
	// 화면의 내용을 전부 공백으로 바꾼다.
	s.contents = std::string(s.height * s.width, ' ');
}

inline
void Window_mgr::resize(Screen::pos r, Screen::pos c, ScreenIndex i)
{
	// Window_mgr은 Screen에 friend로 선언되어 있음
	// 그래서 Screen의 private 멤버에 접근이 가능
	screens[i].height = r;
	screens[i].width = c;
	screens[i].contents = string(r * c, ' ');
}
#endif