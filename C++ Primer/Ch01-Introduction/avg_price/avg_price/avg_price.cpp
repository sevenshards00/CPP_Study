/*
* C++ Primer - Introduction (서론)
* 파일명: avg_price.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-30
* 이전 버전 작성 일자:
* 버전 내용: C++ 맛보기 - 서점 프로그램 예제
* 이전 버전 내용:
*/

#include <iostream>
#include "Sales_item.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main(int argc, const char* argv[])
{
	Sales_item total; // 서적 판매량을 담을 변수
	if (cin >> total)
	{
		Sales_item trans; // 다음 거래 내용을 담을 변수
		while (cin >> trans)
		{
			if (total.isbn() == trans.isbn()) // ISBN이 같다면
				total += trans; // 더한다.
			else // ISBN이 다르다면
			{
				cout << total << endl; // 현재까지의 총합을 출력
				total = trans; // total을 다음 거래 내용(다른 ISBN)으로 갱신
			}
		}	
		cout << total << endl; // EOF를 만났을 경우 마지막 처리 내용을 화면에 출력
	}
	else
	{
		cerr << "No data" << endl;
		return -1;
	}
	return 0;
}