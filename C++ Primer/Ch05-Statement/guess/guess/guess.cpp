/*
* C++ Primer - Statement (문장)
* 파일명: guess.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: do-while문과 조건문을 이용한 up-down 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	do
	{
		cout << "Guess a number between 0 ~ 9" << endl;
		unsigned i, mynum = 7;
		cin >> i;

		// ==으로 조건을 판별할 경우
		if (i == mynum)
		{
			cout << "Congrats you guessd right!" << endl;
			break;
		}
		else if (i < mynum)
			cout << "too low" << endl;
		else
			cout << "too high" << endl;

		// !=으로 조건을 판별할 경우
		if (i != mynum)
		{
			if (i < mynum)
				cout << "too low" << endl;
			else
				cout << "too high" << endl;
		}
		else
		{
			cout << "Congrats you guessd right!" << endl;
			break;
		}
	} while (true);

	return 0;
}