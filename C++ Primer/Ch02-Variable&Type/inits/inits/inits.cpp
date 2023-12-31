/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: inits.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: 변수의 초기화 방법 예제
* 이전 버전 내용:
*/

#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

// 해당 매크로를 주석처리하면 기존의 방식
// 매크로를 사용하면 C++11 기준으로 초기화가 가능한지 확인 가능
#define LIST_INIT

int main(int argc, const char* argv[])
{
	int v1(1024);    // 직접 초기화, 함수에 인자를 주듯 초기화하는 것이 가능
#ifdef LIST_INIT
	int v2{ 1024 };    // 직접 초기화, 목록(list) 초기화 방식. C++11에서 새로 추가한 표준.
#else
	int v2(1024);    // 목록(list) 초기화가 지원이 안되는 컴파일러는 괄호를 사용.use parens if list-initialization not yet supported
#endif
	int v3 = 1024;   // 값의 복사를 통한 초기화. 우리가 흔히 아는 변수 초기화 방식.
#ifdef LIST_INIT
	int v4 = { 1024 }; // 값의 복사를 통한 초기화. C++11에서 새로 추가한 표준인 목록(list) 초기화 방식
#else
	int v4 = 1024; // 마찬가지로 목록(list) 초기화가 지원이 안되는 컴파일러면 기존의 변수 초기화 방식 사용.
#endif

	cout << "v1: " << v1 << "\nv2: " << v2 << "\nv3: " << v3 << "\nv4: " << v4 << endl;

	// 문자열 상수를 string 클래스에 초기화 하는 방법
	string titleA = "C++ Primer, 5th Ed."; // 대입 연산자를 사용해서 초기화 가능
	string titleB("C++ Primer, 5th Ed."); // 함수처럼 인자를 전달하듯이 초기화하는 것도 가능
	string all_nines(10, '9');  // 또는 첫 번쨰 인자로는 문자의 갯수와 입력할 문자를 지정하여 초기화하는 것도 가능.

	cout << "titleA: " << titleA << "\ntitleB: " << titleB << "\nall_nines: " << all_nines << endl;

	return 0;
}