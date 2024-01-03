/*
* C++ Primer - Expression (표현식)
* 파일명: warn_dbltoint.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 부동 소수점 타입의 데이터를 정수형 데이터에 저장하는 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int ival = 3.541 + 3; // 컴파일러가 이 부분에 대해서 warning을 띄운다.
	// double형 데이터인 3.541의 소수점 부분을 truncate하여 정수형인 int에 저장하기 때문
	cout << ival << endl;

	return 0;
}