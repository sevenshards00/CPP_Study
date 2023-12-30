/*
* C++ Primer - Introduction (서론)
* 파일명: whilecount.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-30
* 이전 버전 작성 일자:
* 버전 내용: C++ 맛보기 - while 반복문을 이용한 1~10까지의 합 구하기
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int sum = 0, val = 1;
	// val이 10이 될 때까지 반복문 실행
	while (val <= 10)
	{
		sum += val;
		val++; // val을 1씩 증가
	}
	// 결과 출력
	cout << "Sum of 1 to 10 inclusive is " << sum << endl;
	return 0;
}