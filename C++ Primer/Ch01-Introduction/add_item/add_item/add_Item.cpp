/*
* C++ Primer - Introduction (서론)
* 파일명: add_item.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-30
* 이전 버전 작성 일자:
* 버전 내용: C++ 맛보기 - 클래스 Sales_item의 객체 더하기
* 이전 버전 내용:
*/

#include <iostream>
#include "Sales_item.h"
using std::cout;
using std::cin;
using std::endl;

int main(int argc, const char* argv[])
{
	Sales_item item1, item2;
	cin >> item1 >> item2;
	cout << item1 + item2 << endl;
	
	return 0;
}