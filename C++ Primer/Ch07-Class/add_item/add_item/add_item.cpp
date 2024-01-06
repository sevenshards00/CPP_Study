/*
* C++ Primer - Class (클래스)
* 파일명: add_item.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: 클래스 기본 예제 - main
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
	if (read(cin, data1) && read(cin, data2))
	{
		if (data1.isbn() == data2.isbn())
		{
			data1.combine(data2);
			print(cout, data1);
			cout << endl;
		}
		else
			cerr << "Input failed!" << endl;
	}

	return 0;
}