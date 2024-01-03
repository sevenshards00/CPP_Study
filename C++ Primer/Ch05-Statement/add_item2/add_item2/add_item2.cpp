/*
* C++ Primer - Statement (문장)
* 파일명: add_item2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: C++의 예외처리 메커니즘 사용 예제(try-catch, throw)
* 이전 버전 내용:
*/

#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Sales_item.h"

int main(int argc, const char* argv[])
{
	Sales_item item1, item2;

	while (cin >> item1 >> item2)
	{
		try // 예외가 발생할 수 있는 프로그램 실행 블록
		{
			if (item1.isbn() != item2.isbn()) // isbn 번호가 같지 않다면
				throw runtime_error("Data must refer to same ISBN"); // 예외를 발생시킨다.

			// 예외가 발생하면 이 부분은 수행하지 않고 catch 블록으로 넘어간다.
			cout << item1 + item2 << endl;
		}
		catch (runtime_error err) // 예외 발생 시 처리 블록
		{
			cout << err.what() // 표준 예외 클래스에서 사용하는 멤버 함수, 발생한 예외에 대한 C형식 문자열을 반환한다.
				<< "\nTry Again? Enter \"y\" or \"n\"" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n') // 입력값이 EOF거나 n을 입력받으면
				break; // while 루프를 빠져나온다.
		}
	}

	return 0;
}