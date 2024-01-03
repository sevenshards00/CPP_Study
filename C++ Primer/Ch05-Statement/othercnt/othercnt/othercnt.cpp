/*
* C++ Primer - Statement (문장)
* 파일명: othercnt.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: switch-case 예제(2) - 모음과 모음이 아닌 것 갯수 구하기
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	char ch;
	unsigned vowelCnt = 0;
	unsigned otherCnt = 0;

	while (cin >> ch)
	{
		switch (ch)
		{
		case 'a': case 'e': case 'i': case 'o': case 'u':
			++vowelCnt;
			break;
		default:
			++otherCnt;
			break;
		}
	}

	cout << "Number of vowels: \t" << vowelCnt << '\n';
	cout << "Total non-vowels: \t" << otherCnt << endl;

	return 0;
}