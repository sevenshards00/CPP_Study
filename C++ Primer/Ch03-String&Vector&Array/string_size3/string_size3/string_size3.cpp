/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: string_size3.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(7) - string 클래스의 멤버 함수 empty()
* 이전 버전 내용:
*/

#include <string> 
using std::string;
using std::getline;

#include <iostream> 
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	string line;

	while (getline(cin, line)) // EOF를 입력받기 전까지 한 줄씩 문자열을 읽어들인다.
		if (!line.empty()) // 다만 문자열이 비어있는 경우, 아무런 입력도 하지 않았을 경우는 출력하지 않는다.
			cout << line << endl;

	return 0;
}