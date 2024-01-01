/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: string_size.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(5) - string 클래스의 멤버 함수 size()
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

string st1;       // string 객체 st1, 현재 비어있는 상태
string st2(st1);  // string 객체 st2를 st1 객체를 복사하여 초기화

int main()
{
    string st("The expense of spirit\n");
    // size 함수는 string 객체의 문자열에 있는 문자 갯수를 세는 데에 사용.
    // 개행 문자를 포함해서 총 22개의 문자를 가지고 있다.
    // C에서의 문자열일 경우에는 마지막 널 문자('\0')가 포함되지만 string 클래스는 아니다.
    cout << "The size of " << st << "is " << st.size() << " characters, including the newline" << endl;
    
    return 0;
}
