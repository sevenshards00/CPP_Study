/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: string_io.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제 - 기본적인 입출력
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
    string s;          // 빈 string 객체
    cin >> s;          // 공백 문자(Whitespace)는 읽지 않고 버린다. -> 공백문자 이전까지 읽어들인다
    cout << s << endl; // 읽어들인 문자열을 출력
    return 0;
}
