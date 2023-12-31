/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: convs.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: 특정 데이터 형 변환에 대한 예시
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int i = 42;
	cout << i << endl; // 42가 출력
	if (i) // 산술 타입이 조건식에서 쓰일 경우에는 bool 타입 true로 판별
		i = 0;
	
	cout << i << endl; // 참이므로 0이 출력

	bool b = 42; // bool형으로 캐스팅, bool은 true와 false만 가진다. 산술 타입 값이 들어오는 경우 0이 아니라면 true
	cout << b << endl; // true이므로 1이 출력

	int j = b; // b는 bool 타입, true값이므로 int형으로 캐스팅되면 1이 됨
	cout << j << endl; // 1이 출력

	double pi = 3.14; // pi는 double형 변수
	cout << pi << endl; // 3.14가 출력

	j = pi; // double을 int로 캐스팅 -> 소수부는 잘려나간다. j = 3
	cout << j << endl; // 3이 출력

	unsigned char c = -1;   // char가 8비트(1바이트)라고 가정하면 unsigned char이므로 255가 된다. -> Underflow로 인잔 wrap around된 값
	i = c;  // 문자 255는 출력 불가능한 문자다.
	// c의 값 255를 int형 변수 i에 대입
	cout << i << endl; // 255를 출력

	return 0;
}