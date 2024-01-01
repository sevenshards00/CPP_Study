/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: getline.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(4) - 공백 문자를 포함한 한 줄씩 읽어들이기 (getline)
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

	// EOF를 입력받기 전까지 문자열을 줄 단위로 읽어들인다.
	while (getline(cin, line))
		cout << line << endl;

	return 0;
}