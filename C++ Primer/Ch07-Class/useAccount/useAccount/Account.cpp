/*
* C++ Primer - Class (클래스)
* 파일명: Account.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: static 클래스 멤버 예제 - 소스 파일
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include "Account.h"

// static 멤버(데이터, 함수)를 클래스 외부에서 정의
const string Account::accountType("Savings Account");
double Account::interestRate = initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}
