/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: Main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: 전역 변수 초기화 시 메모리 영역
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

int GetTwo()
{
	return 2;
}

int g_A;				// 초기화 하지 않은 전역 변수 -> bss
int g_B = 0;			// 초기화는 했으나 기본값(0)으로 초기화한 전역 변수 -> bss
int g_C = 1;			// 상수로 초기화한 전역 변수 -> data
int g_D = GetTwo();		// 함수를 통해 초기화하는 전역 변수 -> bss => 일단 bss에 0으로 초기화된 이후 함수 호출로 인해서 초기화가 된다.

int main()
{
	cout << &g_A << '\n';
	cout << &g_B << '\n';
	cout << &g_C << '\n';	// 유일하게 주소가 다른 셋보다 작게 나옴 -> data 영역은 bss보다 작은 주소 방향에 위치하고 있기 때문.
	cout << &g_D << '\n';

	return 0;
}