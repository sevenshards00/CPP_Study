/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: escape.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: escape sequence(확장 문자열) 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, const char* argv[])
{
	cout << '\n';       // 개행 문자 출력
	std::cout << "\tHi!\n";  // 탭 문자 + Hi! + 개행 문자 출력
	std::cout << "Hi \x4dO\115!\n"; // Hi + MOM(일반화된 확장 문자열) + ! + 개행 문자 출력
	std::cout << '\115' << '\n';    // M(일반화된 확장 문자열) + 개행 문자 출력

	return 0;
}