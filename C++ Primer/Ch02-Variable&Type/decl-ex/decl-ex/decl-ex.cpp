/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: decl-ex.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: C++11에서 추가된 decltype 타입 지정자 사용 예시
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int a = 0;
	/*
	* C++11에서는 auto와 decltype 타입 지정자를 표준으로 추가를 하였음.
	* 프로그래머가 직접 형을 결정하지 않고 컴파일러가 추론하여 변수의 형을 지정하게 된다.
	* auto는 초기값을 통해서 타입을 추론
	* decltype은 초기값 또는 표현식(expression)을 통해서 타입을 추론
	*/
	 
	decltype(a) c = a;   // c는 int형으로 결정
	decltype((a)) d = a; // 괄호로 둘러싼 변수에 decltype을 적용하면 항상 참조자를 반환, 그래서 d는 a의 int형 참조자 타입으로 결정
	++c; // c의 값을 증가, a와 d는 c와 별개이므로 증가하지 않는다.
	cout << "a: " << a << " c: " << c << " d: " << d << endl;
	++d; // d의 값을 증가, d는 a를 참조하고 있으므로 a 역시 값이 증가한다.
	cout << "a: " << a << " c: " << c << " d: " << d << endl;

	int A = 0, B = 0;
	decltype((A)) C = A;   // C는 A를 참조하는 참조자로 타입이 결정
	// A + B는 표현식(expression) 이다.
	// decltype은 대상 표현식의 형식에 의존하게 된다.
	// 대입(=)은 참조자 타입을 반환하는 하나의 예.
	// 해당 타입은 왼쪽 피연산자 (lvalue)에 대한 참조자가 된다.
	// 예를 들어 i가 int라면 표현식 i = x 는 int& 타입이 된다.
	// 그래서 D는 A를 참조하는 참조자가 된다.
	decltype(A = B) D = A; 
	++C;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;
	++D;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;

	return 0;
}