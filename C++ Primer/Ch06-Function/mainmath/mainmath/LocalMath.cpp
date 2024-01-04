/*
* C++ Primer - Function (함수)
* 파일명: LocalMath.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-04
* 이전 버전 작성 일자:
* 버전 내용: 간단한 분리 컴파일 예제 - 소스 파일
* 이전 버전 내용:
*/

#include "LocalMath.h"

// v1 > v2라는 가정을 가지고 시작한다.
int gcd(int v1, int v2) // 최대 공약수
{
	while (v2) // v2가 0이 될 때까지 수행
	{
		int temp = v2;
		v2 = v1 % v2; //v1을 v2로 나눈 나머지를 v2로 취한다
		v1 = temp; // 그리고 v1을 v2로
	}

	return v1;
}

int fact(int val) // 팩토리얼
{
	int ret = 1;
	while (val > 1) // 입력받은 값이 1이 되면 반복을 종료.
		ret *= val--; // 입력 받은 값을 계속 곱하고, 후위 감소를 통해 감소.
	return ret;

}

int factorial(int val) // 팩토리얼(재귀, Recursive)
{
	if (val > 1) // 입력받은 값이 1보다 크면 반복 -> 재귀의 탈출 조건
		return factorial(val - 1) * val; // 재귀를 이용하여 팩토리얼 수행
	return 1; // 만약 1을 입력거나 재귀를 통해서 val이 1이 되면 1을 반환 -> 재귀 탈출
}