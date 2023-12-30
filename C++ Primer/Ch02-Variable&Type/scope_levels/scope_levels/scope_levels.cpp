/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: scope_levels.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-30
* 이전 버전 작성 일자:
* 버전 내용: 전역 변수와 지역 변수의 유효 범위 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int reused = 42; // 전역 변수

int main(int argc, char* argv[])
{
	int unique = 0; // 지역 변수

	// 출력 결과 #1: 42 0 -> 이때는 전역변수 reused가 출력된다.
	std::cout << reused << " " << unique << std::endl;

	int reused = 0; // 지역 변수명을 전역 변수와 동일하게 정의, 전역 변수는 지역 변수에 가려진다.

	// 출력 결과 #2: 0 0 -> 지역 변수 reused가 전역 변수를 가렸기 때문
	std::cout << reused << " " << unique << std::endl;

	// 출력 결과 #3: 42 0 -> 범위 지정 연산자를 사용하여 명시적으로 전역 변수 reused를 출력
	std::cout << ::reused << " " << unique << std::endl;

	return 0;
}