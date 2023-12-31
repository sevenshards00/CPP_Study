/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: sales_data.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: 간단한 클래스(Sales_data 클래스) 사용 예시
* 이전 버전 내용:
*/

#include <iostream>
#include <string>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, const char* argv[])
{
	Sales_data data1, data2; // Sales_data 클래스의 객체 data1, data2 선언 및 정의

	double price = 0;  // 책의 권당 가격, 총 수익 계산에 사용할 변수.

	// 첫 번째 거래 내역을 읽는다. 읽어들이는 정보는 ISBN과 판매 부수, 권당 가격
	cin >> data1.bookNo >> data1.units_sold >> price;
	// 총 수익을 계산하여 클래스의 멤버인 units_sold에 계산한 값을 대입한다.
	data1.revenue = data1.units_sold * price;

	// 두 번째 거래 내역을 읽는다. 첫 번째 거래 내역과 동일한 과정을 거친다.
	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	// 두 거래 내역의 ISBN을 비교하여 같은 책인지를 확인한다.
	if (data1.bookNo == data2.bookNo)
	{
		unsigned totalCnt = data1.units_sold + data2.units_sold; // 판매한 책의 전체 부수
		double totalRevenue = data1.revenue + data2.revenue; // 책을 판매해서 얻은 수익 총합

		// ISBN, 종 판매 부수, 총 판매 수익을 출력.
		// print: ISBN, total sold, total revenue, average price per book
		cout << data1.bookNo << " " << totalCnt	<< " " << totalRevenue << " ";
		
		if (totalCnt != 0) // 1권이라도 판매가 되었다면
			cout << totalRevenue / totalCnt << endl; // 전체 수익 / 판매 부수만큼 나눠서 평균가를 출력
		else // 1권도 판매가 안되었다면
			cout << "(no sales)" << endl; // 판매 내역이 없으므로 (no sales)를 출력 

		return 0;  // 성공적으로 수행이 되었으므로 0 반환
	}
	else // 같은 책이 아닐 경우
	{
		// ISBN이 같이 않음을 출력
		cerr << "Data must refer to the same ISBN" << endl;
		return -1; // 성공적으로 수행되지 않았으므로 -1 반환
	}
}
