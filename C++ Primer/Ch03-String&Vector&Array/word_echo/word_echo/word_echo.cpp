/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: word_echo.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(3) - echo
* 이전 버전 내용:
*/

#include <iostream> 
using std::cin;
using std::cout;
using std::endl;

#include <string> 
using std::string;

int main(int argc, const char* argv[])
{
	string word;
	while (cin >> word)       // EOF가 입력될 때까지 계속 입력을 받는다. 
		cout << word << endl; // 입력 받은 단어를 그대로 화면에 다시 출력한다.
	return 0;
}