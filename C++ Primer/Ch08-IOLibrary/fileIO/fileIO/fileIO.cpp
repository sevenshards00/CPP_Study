/*
* C++ Primer - I/O Library (I/O 라이브러리)
* 파일명: fileIO.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: 파일 I/O 기본 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <stdexcept>
using std::runtime_error;

// 파일을 읽으면 처리하는 함수
void process(ifstream& is)
{
	string s;
	while (is >> s) // 입력 버퍼가 EOF가 아닐때까지 데이터를 읽는다.
		cout << s << endl; // 문자열 단위로 쪼개어가며 출력
}

int main(int argc, const char* argv[])
{
	// main함수의 인자를 통해 파일 입출력을 수행
	// argv[0]은 프로그램명이므로 argv[1]부터 시작
	// 조건식에서 종료되는 조건은 입력받은 파일명 갯수만큼
	for (auto p = argv + 1; p != argv + argc; ++p)
	{
		ifstream input(*p); // 지정한 파일 이름을 대상으로 스트림을 개방한다.
		if (input) // 만약 파일이 있다면
			process(input); // 출력을 수행
		else // 파일이 없다면
			cerr << "couldn't open: " + string(*p);
	}
	// 위의 파일 스트림은 for문 내에서의 지역변수이므로 생성과 소멸을 반복한다.
	// 파일 스트림은 소멸되면서 자동으로 close를 수행한다.

	// for문이 아닌 while문을 쓸 경우
	auto p = argv + 1, end = argv + argc;

	ifstream input; // 비어있는 스트림
	while (p != end)
	{
		input.open(*p); // 파일을 개방한다.
		if (input) // 파일이 있다면
			process(input); // 출력을 수행
		else // 파일이 없다면
			cerr << "couldn't open: " + string(*p);
		input.close(); // 대상 파일에 대한 스트림을 닫는다.
		++p; // 다음 파일명을 가리키기 위해 증감연산
	}
		
	return 0;
}