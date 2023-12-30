/*
* C++ Primer - Introduction (서론)
* 파일명: add.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-30
* 이전 버전 작성 일자:
* 버전 내용: C++ 맛보기 - 두 수를 입력받고 더하기
* 이전 버전 내용:
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	cout << "Enter two numbers: " << endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
	return 0;
}