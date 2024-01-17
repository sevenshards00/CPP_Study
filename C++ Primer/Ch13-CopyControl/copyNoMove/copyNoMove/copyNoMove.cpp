/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: copyNoMove.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-17
* 이전 버전 작성 일자:
* 버전 내용: 이동 생성자가 없을 경우에는 복사 생성자가 실행되는 예제
* 이전 버전 내용:
*/

#include <utility>
#include <iostream>

#define DEFAULT_FCNS

class Foo
{
public:
#ifdef DEFAULT_FCNS // C++11 표준 이상 =dafault를 지원하는 경우
	Foo() = default; // 컴파일러가 생성하는 합성 기본 생성자를 사용할 경우, 복사 생성자를 정의하였기 때문에 필요.
#else // C++11 표준 미만
	Foo() {} // 컴파일러가 생성하는 합성 기본 생성자와 차이는 없음. 그러나 복사 생성자를 정의하였기 때문에 필요.
#endif
	Foo(const Foo &); // 복사 생성자
	// 이동 생성자는 정의하지 않음.
};

Foo::Foo(const Foo &) { std::cout << "Foo Copy Constructor Called" << std::endl; }

int main()
{
	Foo x; // 생성자 호출
	Foo y(x); // 복사 생성자 호출, x는 lvalue
	Foo z(std::move(x)); // 이동 생성자가 호출될 것으로 생각됐지만, 복사 생성자 호출. -> 이동 생성자가 없으므로.

	return 0;
}