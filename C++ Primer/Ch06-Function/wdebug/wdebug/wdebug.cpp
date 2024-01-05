/*
* C++ Primer - Function (함수)
* 파일명: wdebug.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: 오류 수정 지원(디버깅) 도구 사용 예제
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

#include <cassert>
// assert는 전처리기(pre-processor) 매크로
// std에 없기 때문에 cassert 헤더를 포함해야 함.

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

//#define NDEBUG
#define FUNC_CPP
void printf(const int ia[], size_t size)
{
#ifndef NDEBUG
#ifdef FUNC_CPP
	// __func__는 C++ 컴파일러에서 정의한 지역 static으로 함수 이름을 가지고 있음
	cerr << __func__ << ": array size is " << size << endl;
#else
	// 만약 __func__를 지원하지 않는다면 MS에서 지원하는 비표준인 __FUNCTION__을 사용할 수 있음
	cerr << __FUNCTION__ << " array size is " << size << endl;
#endif // FUNC_CPP END
#endif // NDEBUG END
}

int main(int argc, const char* argv[])
{
	string word = "foo";
	const string::size_type threshold = 5;
	if (word.size() < threshold)
		cerr << "Error: " << __FILE__
#ifdef FUNC_CPP
		<< " : in function " << __func__
#else
		<< " : in function " << __FUNCTION__
#endif
		<< " at line " << __LINE__ << endl
		<< "	Compiled on " << __DATE__
		<< " at " << __TIME__ << endl
		<< "	Word read was \"" << word
		<< "\": Length too short" << endl;
	word = "something longer than five chars";
	assert(word.size() > threshold);

	return 0;
}