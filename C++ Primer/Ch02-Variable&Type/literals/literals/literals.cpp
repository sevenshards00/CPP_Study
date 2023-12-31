/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: literals.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: literal(리터럴, 상수)에 대한 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	cout << "Hello World!";  // 단순한 표준 문자로 이뤄진 문자열 상수 출력
	cout << "";              // 빈 문자열 상수 출력
	// escape sequence 인 탭과 개행문자를 사용하는 문자열 상수
	cout << "\nCC\toptions\tfile.[cC]\n";

	// 문자열 상수가 길 경우 다음과 같이 행을 바꿔서 이어 써도 된다.
	cout << "a really, really long string literal "
		"that spans two lines" << endl;

	// 대문자 M을 표현하는 세 가지 방식, 8진수 또는 16진수를 사용해서 표기가 가능하다는 것만 알아둘 것
	cout << 'M' << " " << '\115' << " " << '\x4d' << endl;

	// C++ 11에서 추가된 표준 자료형 long long (64비트, 8바이트 자료형) 타입
	unsigned long long bigVal = 1ULL;
	cout << bigVal << endl;

	return 0;
}