/*
* Fundamental C++ - Ch01-Type
* 파일명: SimpleCString.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: C++의 string 클래스, VC++의 CString 클래스의 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::wcout;

#include <string>
using std::string;
using std::wstring;

// CString 클래스 사용을 위한 헤더
#include <atlstr.h>

#include <algorithm>
using std::transform;

#include <locale>


int main()
{
	// 한글 출력을 위한 locale 셋팅
	std::locale::global(std::locale("kor"));

	// CString 클래스 (VC++)
	// 기본적으로 wchar_t 셋
	CString str1 = "ABCDEFG";
	wcout << (const wchar_t*)str1 << str1.GetLength() << '\n';

	wchar_t *p1 = str1.GetBuffer();				// str1을 가리키는 포인터
	p1[3] = '\0';								// 값에 접근하여 '\0'로 바꾼다.
	wcout << (const wchar_t *)str1 << str1.GetLength() << '\n';	// 바뀐 결과 확인

	// C++ 라이브러리인 string 클래스
	string str2 = "ABCDEFG";
	cout << str2.c_str() << str2.size() << '\n';	// 멤버함수 c_str()을 통해 C형식 문자열로(const char*) 변환

	char *p2 = (char *)str2.c_str();				// str2의 C형식 문자열을 가리키는 포인터
	p2[3] = '\0';									// 값에 접근하여 '\0'로 바꾼다. 
	cout << str2.c_str() << str2.size() << '\n';	// 바뀐 결과 확인

	// string class로 대소문자 변경 시 문제
	// 한글은 대소문자의 개념이 없다.
	string str3 = "ABC가나다묭DEF";
	transform(str3.begin(), str3.end(), str3.begin(), tolower);
	cout << str3.c_str() << '\n';

	// wstring을 사용하면 문제 해결.
	wstring wstr = L"ABC가나다묭DEF";
	transform(wstr.begin(), wstr.end(), wstr.begin(), tolower);
	wcout << wstr << '\n';

	return 0;
}