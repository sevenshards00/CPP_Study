/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: string_size3.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(8) - string 클래스 비교 연산
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";

    if (str < phrase) cout << "str is smaller" << endl; // 이 경우는 문자열의 길이를 비교하는 경우
    if (slang > str) cout << "slang is greater" << endl; // 사전 편찬 순서로 비교
    if (slang > phrase) cout << "slang is greater" << endl; // 사전 편찬 순서로 비교

    return 0;
}