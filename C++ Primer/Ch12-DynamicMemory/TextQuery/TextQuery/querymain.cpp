/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: querymain.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-14
* 이전 버전 작성 일자: 2024-01-12
* 버전 내용: 프로그램 이해를 위한 주석 추가
* 이전 버전 내용: 본문 조회 프로그램 - main
*/

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <cstdlib> // EXIT_FAILURE 매크로 사용을 위해

#include "TextQuery.h"
#include "make_plural.h"

// 파일 스트림을 인자로 받아서 질의를 수행하기 위한 함수.
void runQueries(ifstream &infile)
{
	// 파일 스트림을 TextQuery의 생성자 인자로 전달하여 tq 객체를 생성한다.
	TextQuery tq(infile); // tq 객체에는 파일의 내용이 저장되고, 조회를 하기 위한 map을 생성하게 된다.

	// 사용자에게서 q(또는 Q)를 입력받을 때까지 파일에 단어 내용을 찾는 질의를 수행.
	while (true)
	{
		cout << "enter word to look for, or Q(q) to quit: ";
		string s;

		// 반복문 탈출 조건, EOF를 받거나, q(또는 Q)를 입력받으면 종료.
		if (!(cin >> s) || s == "q" || s == "Q")
			break;
		// 그게 아니라면 결과를 출력한다.
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, const char *argv[])
{
	ifstream infile;
	// 이 부분에서 조건식 코드만 수정했다.
	// 좋은 코드는 아니라고 생각하여 바꿨다.
	// 예제가 조금 난해하게 써놨었음.
	// 원래 조건식 부분은 이렇게 쓰여져있음.
	// if(argc < 2 || !(infile.open(argv[1]), infile))
	// 파일 스트림을 개방하면서 반환하게 되는 값은 void이기 때문에 조건식에서는 아무런 의미가 없음.
	// 저자는 콤마 연산자(,)를 사용하여 그 다음 값을 비교조건으로 사용하는 식으로 해놨다.
	// 이럴거면 차라리 if 전에 파일 스트림을 먼저 개방하고 그 뒤에 조건식으로is_open()을 확인하는 것이 더 맞다고 봄.
	infile.open(argv[1]);
	if (argc < 2 || !infile.is_open())
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	runQueries(infile);
	return 0;
}