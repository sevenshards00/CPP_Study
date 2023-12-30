/*
* C++ Primer - Introduction (서론)
* 파일명: item_io.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-30
* 이전 버전 작성 일자:
* 버전 내용: C++ 맛보기 - Sales_item 클래스 객체 읽고 쓰기
* 이전 버전 내용:
*/

#include <iostream>
#include "Sales_item.h"
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	Sales_item book;
	cin >> book;
	cout << book << endl;

	return 0;
}