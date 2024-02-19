/*
* Fundamental C++ - Ch01-Type
* 파일명: FloatLongLongCompare.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: 부동소수점 타입으로 계산시 오차 발생 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

int main()
{
	// 정수 계산에서의 문제
	float f = 33554432 + 3;		// 부호부가 0, 지수부가 2^25, 가수부는 0인 float -> 4의 배수만 표현이 가능
	cout.precision(32);
	cout << f << '\n';			// 당연히 제대로 나오지 않는다.

	__int64 i64 = 33554432 + 3;
	cout << i64 << '\n';

	// 반올림에서의 문제
	printf("%.3f\n", 0.3255);
	printf("%.3f\n", 0.4255);
	printf("%.3f\n", 0.42550001);

	return 0;
}