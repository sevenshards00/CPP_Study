/*
* Fundamental C++ - Ch03-Build
* 파일명: Main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-22
* 이전 버전 작성 일자:
* 버전 내용: 사전 정의 매크로 사용 예제 - 매크로 전개 순서 이해하기
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

#include "Macro.h"

int main()
{
	cout << D_FILE_NAME << '\n';
	cout << S1_FILE_NAME << '\n';
	cout << S2_FILE_NAME << '\n';

	return 0;
}