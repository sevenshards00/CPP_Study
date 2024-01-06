/*
* C++ Primer - I/O Library (I/O 라이브러리)
* 파일명: add_itemV2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: I/O 스트림 기본 예제 - main
* 이전 버전 내용:
*/


#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

#include "Sales_data.h"


int main(int argc, const char* argv[])
{
	Sales_data data1, data2;
	if (read(cin, data1) && read(cin, data2)) // 거래 내역을 읽는다.
	{
		if (data1.isbn() == data2.isbn()) // isbn이 일치한다면
		{
			Sales_data sum = add(data1, data2); // 거래 내역을 합친다.
			print(cout, sum); // 거래 내역을 출력
			cout << endl; // 개행을 하면서 버퍼를 비운다.
		}
		else
			cerr << "Input failed!" << endl;
	}

	return 0;
}