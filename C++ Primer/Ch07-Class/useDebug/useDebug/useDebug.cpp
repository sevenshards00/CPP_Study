/*
* C++ Primer - Class (클래스)
* 파일명: useDebug.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: 상수 클래스 예제 - main
* 이전 버전 내용:
*/

#include <iostream>
using std::cerr; using std::endl;

#include "Debug.h"

int main(int argc, const char* argv[])
{
#ifdef CONSTEXPR_VARS // C++11 표준 이후
	constexpr Debug io_sub(false, true, false);  // IO에 대한 디버깅    
#else // C++11 표준 이전
	const     Debug io_sub(false, true, false);  // IO에 대한 디버깅    
#endif
	if (io_sub.any())  // if(true)와 같다
		cerr << "print appropriate error messages" << endl;

#ifdef CONSTEXPR_VARS // C++11 표준 이후
	constexpr Debug prod(false); // 생성 중 디버깅을 하지 않음
#else // C++11 표준 이전
	const     Debug prod(false); // 생성 중 디버깅을 하지 않음
#endif
	if (prod.any())    // 디버깅을 하지 않으므로 if(false)와 같음
		cerr << "print an error message" << endl;

	IO_Subsystem ioErrs;        // 기본 생성자에 의해 생성되는 객체로 디버깅 대상이 없음
	// 그래서 여기는 디버깅이 되지 않음
	if (ioErrs.default_debug()) // if (false || debug.any())
		cerr << "print message 3" << endl;
	ioErrs.set_debug(true);     // 여기서 디버깅을 켜면 이후부터 출력
	if (ioErrs.default_debug()) // if (false || debug.any())
		cerr << "print message 4" << endl;
	ioErrs.set_debug(false);

	HW_Subsystem hw;
	hw.set_debug(true);
	if (ioErrs.default_debug() || hw.default_debug()) // if (false || debug.any())
		cerr << "print message 5" << endl;
}