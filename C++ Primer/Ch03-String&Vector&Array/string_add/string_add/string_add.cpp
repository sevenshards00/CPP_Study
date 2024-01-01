/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: string_add.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(9) - string 덧셈 연산 (C의 strcat)
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main(int argc, const char* argv[])
{

	string s1 = "hello, ", s2 = "world\n";
	string s3 = s1 + s2;   // s3은 s1과 s2가 연결된 결과가 문자열로 복사되어 저장된다.
	cout << s1 << s2 << s3 << endl;

	s1 += s2;   // s1 = s1 + s2와 동일
	cout << s1;

	string s4 = "hello", s5 = "world";  // 구두점이 없이 문자열을 구성한 경우
	string s6 = s4 + ", " + s5 + '\n'; // 다음과 같이 합치는 것이 가능하다.
	cout << s4 << s5 << "\n" << s6 << endl;

	return 0;
}