/*
* C++ Primer - Class (클래스)
* 파일명: Debug.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: 상수 클래스 예제 - 소스 파일
* 이전 버전 내용:
*/

#include "Debug.h"
// Debug 클래스에서 유일하게 구현할 부분은 enable이라는 static 멤버에 대한 정의만 하면 됨
#ifdef CONSTEXPR_CTORS // C++11 표준 이후
constexpr Debug HW_Subsystem::enable;
constexpr Debug IO_Subsystem::enable;
#else // C++11 표준 이전
const Debug HW_Subsystem::enable(true, false, false);
const Debug IO_Subsystem::enable(true, false, true);
#endif