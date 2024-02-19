/*
* Fundamental C++ - Ch01-Type
* 파일명: SimpleUnicodeSample.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: 한글 [은(는)] 처리 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

bool HasFinalConsonant(wchar_t Letter)
{
	// 문자가 한글 완성형 범위에 있는지 확인
	if (Letter >= 0xAC00 && Letter <= 0xD7A3)
	{
		// 받침이 없는 글자인지 확인
		// 한글의 경우, 받침이 없는 '가'부터 시작해서 28자를 주기로 받침없는 글자가 배치되어 있음.
		if ((Letter - 0xAC00) % 28 == 0)
			return true;
	}

	return false;
}

int main()
{
	if (HasFinalConsonant(L'왕'))
		cout << "왕 - 받침 없음" << '\n';

	if (HasFinalConsonant(L'주'))
		cout << "주 - 받침 없음" << '\n';

	return 0;
}