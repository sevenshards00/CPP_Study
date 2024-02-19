/*
* Fundamental C++ - Ch01-Type
* 파일명: SimpleTime.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: tm 구조체 및 mktime 함수 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

#include <ctime>

int main()
{
	time_t ct;
	time(&ct);							// 현재 시간을 받는다.
	tm *pT = (tm *)malloc(sizeof(tm));	// tm 구조체 동적 할당

	if (pT == nullptr)
	{
		cout << "malloc() error";
		return -1;
	}

	errno_t err = localtime_s(pT, &ct);	// 현재 시간을 기준으로 tm 구조체를 설정
	
	if (err != NULL)
	{
		cout << "localtime_s() error";
		return -1;
	}

	pT->tm_mday += 50;			// 현재 날짜로부터 50일 뒤를 더한다.
	mktime(pT);
	cout << pT->tm_year + 1900 << "년\n";
	cout << pT->tm_mon + 1 << "월\n";
	cout << pT->tm_mday << "일\n";

	free(pT); // 동적 할당한 메모리 해제

	return 0;
}