/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: string_size2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(6) - string 클래스의 멤버 함수 size() 응용
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

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

	while (getline(cin, line)) // getline 함수를 통해 한 줄을 읽어들인다. EOF를 받을 경우 반복문 종료.
		if (line.size() > 80) // 입력 받은 문자열의 문자 개수가 80개가 넘으면 출력하도록 조건을 설정.
			cout << line << endl;

	return 0;
}