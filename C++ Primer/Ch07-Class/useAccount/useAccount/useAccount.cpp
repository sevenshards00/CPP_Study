/*
* C++ Primer - Class (클래스)
* 파일명: useAccount.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: static 클래스 멤버 예제 - main
* 이전 버전 내용:
*/

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include "Account.h"

int main()
{
	Account a1("bem", 42);
	cout << a1.balance() << endl;
	a1.calculate();
	cout << a1.balance() << endl;

	return 0;
}