/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: unsigned.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: signed와 unsigned의 특징 및 정수 Overflow / Underflow (Undefined Behavior)
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	// unsigned int (부호 없는 정수), 줄여서 unsigned
	unsigned u1 = 10, u2 = 42;
	cout << u2 - u1 << endl;
	cout << u1 - u2 << endl; // Underflow로 인한 Wrap around된 값.

	// signed (부호 있는 정수), signed를 쓸 경우 별도로 쓰지 않아도 됨
	int i1 = 10, i2 = 42;
	cout << i2 - i1 << endl;
	cout << i1 - i2 << endl;

	// unsigned int와 signed int의 연산
	// 이 경우 int형 변수는 unsigned int로 바뀐다.
	u1 = 42;
	i1 = 10;
	cout << i1 - u1 << endl; // -32가 나올 것을 기대할 수 있지만 실제로 underflow가 발생하게 된다. Wrap around된 값.
	cout << u1 - i1 << endl; // 이 경우에는 문제가 없다.

	u1 = 10;
	i1 = -42;
	cout << i1 + i1 << endl;  // (-42) + (-42) = -84
	cout << u1 + i1 << endl;  // 32비트(4바이트) int라면 4294967264 -> underflow로 인한 Wrap around된 값.

	i1 = 10;
	cout << "good" << endl;
	while (i1 >= 0) {
		std::cout << i1 << std::endl;
		i1--;
	}

	for (int i = 10; i >= 0; i--)
		cout << i << ' '; // 10 ~ 0까지 출력
	cout << endl;

	for (unsigned u = 0; u <= 10; u++)
		cout << u << ' ';  // prints 0 . . . 10
	cout << endl;

	// unsigned int를 사용한 예.
	// 위에 있는 signed int처럼 조건을 줄 수도 있는거 아닐까 싶을 수 있다.
	// 하지만 unsigned는 0~2^32-1까지의 값을 표현. 절대로 0이하로 될 수 없으므로 아래와 같이 쓰면 가능
	u1 = 11;
	while (u1 > 0) {
		u1--;        // 먼저 감소를 시켜서 while 조건식을 빠져나갈 수 있도록 한다.
		cout << u1 << ' ';
	}
	cout << endl;


	// signed int와 unsigned int를 조건식에서 사용할 경우be wary of comparing ints and unsigned
	u1 = 10;
	i1 = -42;
	if (i1 < u1)               // 마찬가지로 이 경우에는 i1이 unsigned로 변경이 된다.
		cout << i1 << endl;
	else
		cout << u1 << endl;

	u1 = 42; u2 = 10; // unsigned int의 연산
	cout << u1 - u2 << endl; // 문제가 없는 연산
	cout << u2 - u1 << endl; // 문제가 없는 연산이긴 하나, Underflow 발생으로 인한 Wrap around된 값

	return 0;
}