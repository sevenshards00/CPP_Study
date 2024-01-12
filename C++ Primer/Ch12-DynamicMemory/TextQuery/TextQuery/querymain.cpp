/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: querymain.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자:
* 버전 내용: 본문 조회 프로그램 - main
* 이전 버전 내용:
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

#include <cstdlib>

#include "TextQuery.h"
#include "make_plural.h"

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);

	while (true)
	{
		cout << "enter word to look for, or Q(q) to quit: ";
		string s;

		if (!(cin >> s) || s == "q" || s == "Q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, const char *argv[])
{
	ifstream infile;
	infile.open(argv[1]);
	if (argc < 2 || !infile)
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	runQueries(infile);
	return 0;
}