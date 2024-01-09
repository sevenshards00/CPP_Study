/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: avg_price.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 스트림 반복자를 클래스 타입에 사용하는 예제
* 이전 버전 내용:
*/

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <iostream>
using std::cin;
using std::cout;

#include "Sales_item.h"

int main(int argc, const char *argv[])
{
	// 스트림 반복자를 이용하여 Sales_item 객체를 읽고 쓰는 것이 가능하다.
	istream_iterator<Sales_item> item_iter(cin);
	istream_iterator<Sales_item> eof;
	ostream_iterator<Sales_item> out_iter(cout, "\n");

	// sum에 먼저 최초의 거래 내역을 기록하고, 후위 증가 연산을 통해 다음 거래내역을 읽는다.
	Sales_item sum = *item_iter++;

	// EOF일 때까지 거래내역을 읽어들인다.
	while (item_iter != eof)
	{
		if (item_iter->isbn() == sum.isbn()) // ISBN이 같다면
			sum += *item_iter++; // 이전 거래 내역과 더하고
		else // 같지 않다면
		{
			out_iter = sum; // 지금까지 합친 거래 내역을 출력
			sum = *item_iter++; // 새로운 거래 내역을 sum에 기록한다.
		}
	}
	out_iter = sum; // EOF를 만나 while이 종료되면 마지막에 남은 거래내역에 대해 출력.

	return 0;
}