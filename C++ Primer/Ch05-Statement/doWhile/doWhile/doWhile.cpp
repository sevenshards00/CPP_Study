/*
* C++ Primer - Statement (문장)
* 파일명: doWhile.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 간단한 do-while문 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int main(int argc, const char* argv[])
{
	string rsp;

	do
	{
		cout << "Please Enter two values: ";
		int val1 = 0, val2 = 0;
		cin >> val1 >> val2;
		cout << "The sum of " << val1 << " and " << val2 << " = " << val1 + val2 << "\n\n";
		cout << "More? Enter \"yes\" or \"no\" : ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');

	cout << endl;

	return 0;
}