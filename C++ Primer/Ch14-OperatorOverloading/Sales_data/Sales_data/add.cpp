/*
* C++ Primer - Overloaded Operations & Conversions (다중 정의 연산과 변환)
* 파일명: add.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-18
* 이전 버전 작성 일자:
* 버전 내용: Sales_data 클래스 연산자 오버로딩
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    // 연산자 오버로딩 이전의 함수들을 사용
    read(read(cin, data1), data2);   //read a pair of transactions
    print(cout, add(data1, data2));  // print the sum of two Sales_datas
    cout << std::endl;

    // 연산자 오버로딩 테스트
    cin >> data1 >> data2;
    cout << data1 + data2 << endl;

	return 0;
}