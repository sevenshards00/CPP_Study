/*
* C++ Primer - Introduction (서론)
* 파일명: mysum.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-30
* 이전 버전 작성 일자:
* 버전 내용: C++ 맛보기 - 조건문(if)을 이용한 입력받은 숫자 횟수 기록하기
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	// currVal은 현재 입력받은 값, val은 새롭게 입력받게 될 값.
	int currVal = 0, val = 0;

	if (cin >> currVal) // 최초로 값을 읽어들이고
	{
		int cnt = 1;
		while (cin >> val) // val에 값을 읽어들인다
		{
			if (val == currVal) // val과 currVal이 같다면
				cnt++; // 입력 횟수 증가
			else // 그게 아니라면
			{
				cout << currVal << " occurs " << cnt << " times" << endl; // 지금까지 입력받은 횟수를 출력하고
				currVal = val; // 새로운 값을 currVal에 대입
				cnt = 1; // 입력 회수는 1부터 다시 초기화
			}
		}
		cout << currVal << " occurs " << cnt << " times" << endl; // EOF를 받았다면 마지막으로 읽어들인 값에 대한 횟수 출력
	}
	return 0;
}