/*
* C++ Primer - Class (클래스)
* 파일명: avg_price.cpp
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
	Sales_data total; // 총합을 더할 객체
	if (read(cin, total)) // EOF를 받기 전까지 입력을 받는다.
	{
		Sales_data trans; // 현재 거래 내역
		while (read(cin, trans)) // 현재 거래 내역을 읽는다.
		{
			if (total.isbn() == trans.isbn()) // isbn이 같다면
				total.combine(trans); // 총합에 현재 거래 내역을 합친다.
			else // 그게 아니라면
			{
				print(cout, total) << endl; // 이전까지의 결과를 출력.
				total = trans; // 새로운 거래 내역을 total에 복사
			}
		}
		print(cout, total) << endl; // EOF를 만나 반복이 종료되면 이전까지 수행했던 결과를 출력한다.
	}
	else // 읽을 데이터가 아예 없는 경우
		cerr << "No data" << endl;

	return 0;
}