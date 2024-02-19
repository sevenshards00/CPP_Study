/*
* Fundamental C++ - Ch01-Type
* 파일명: SimpleStringConverter.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: string 클래스의 대소문자 변환 함수 직접 구현한 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <cstring>

void ToLower(string &ref)
{
	bool bStartExtension = false;		// 확장 문자인지 판별하기 위한 변수, false로 시작

	string::iterator it = ref.begin();	// 반복자

	while (it != ref.end())
	{
		unsigned char c = *it;		// 반복자를 통해 해당 문자 처리

		if (bStartExtension)		// 확장 문자일 경우 처리하지 않고 반복문을 이어서 수행
			bStartExtension = false;
		else
		{
			if (c < 128 && !bStartExtension)	// 128 안쪽일 경우 ASCII 코드, 그게 아니라면 확장 문자
				*it = tolower(c);
			else
				bStartExtension = true;
		}

		++it;
	}
}

int main()
{
	string str = "ABC가나다묭DEF";
	ToLower(str);
	cout << str << '\n';
}