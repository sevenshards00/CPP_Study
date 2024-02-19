﻿/*
* Fundamental C++ - Ch01-Type
* 파일명: ReferencePointer.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: C++의 참조자와 포인터의 실제 내부 구조 확인 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

int main()
{
	int a = 1;

	/*
	* 엄밀히 따지면 아래는 동일하게 동작하고 있는 것.
	* 참조자를 쓸 경우에는 주소(&) 연산자와 역참조(*) 연산자가 생략된 것임.
	* 실질적인 내부 동작은 포인터와 동일.
	* 그래서 참조자는 결국 포인터의 Wrapping 버전이라고 봐도 무방함.
	*/

	// 참조자(Reference)
	int &ra = a;
	ra = 2;
	cout << a << '\n';

	// 포인터(Pointer)
	int *pa = &a;
	*pa = 3;
	cout << a << '\n';

	// 참조자가 포인터로 동작한다는 예제
	const int &cra = 1;		// const 참조자를 통해 상수를 참조.
	
	/*
	* 일반적으로 참조 타입 객체가 초기화될 때의 과정은 다음과 같다.
	* 1) cra의 포인터 영역이 확보
	* 2) 초기화되는 변수의 주소가 포인터 영역에 쓰여짐
	* 3) const 지정자가 있는 경우, int 객체 (위의 1)에 대한 임시 영역이 마련되어 상수가 대입이 됨.
	* 4) 해당 상수를 대입한 임시 영역의 주소가 참조 타입 객체의 포인터 영역에 쓰이게 되는 것.
	*/

	pa = (int *) &cra;
	*pa = 2;
	cout << cra << '\n';

	return 0;
}