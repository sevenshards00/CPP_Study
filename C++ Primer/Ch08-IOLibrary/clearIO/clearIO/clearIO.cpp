/*
* C++ Primer - I/O Library (I/O 라이브러리)
* 파일명: clearIO.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: I/O 스트림 상태 요청 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

void read()
{
	// cin의 스트림 상태를 badbit, eofbit, failbit를 활성화.
	cin.setstate(cin.badbit | cin.eofbit | cin.failbit);
}

void off()
{
	// cin의 스트림 상태에서 failbit와 badbit만 비활성화, eofbit는 그대로 활성화된 상태로 놔둔다.
	cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
}

int main(int argc, const char* argv[])
{
	cout << "before read" << endl;
	if (cin.good())
		cout << "cin's good" << endl;
	if (cin.bad())
		cout << "cin's bad" << endl;
	if (cin.fail())
		cout << "cin's fail" << endl;
	if (cin.eof())
		cout << "cin's eof" << endl;

	read();
	cout << "after read" << endl;
	if (cin.good())
		cout << "cin's good" << endl;
	if (cin.bad())
		cout << "cin's bad" << endl;
	if (cin.fail())
		cout << "cin's fail" << endl;
	if (cin.eof())
		cout << "cin's eof" << endl;

	off();
	cout << "after off" << endl;
	if (cin.good())
		cout << "cin's good" << endl;
	if (cin.bad())
		cout << "cin's bad" << endl;
	if (cin.fail())
		cout << "cin's fail" << endl;
	if (cin.eof())
		cout << "cin's eof" << endl;
	return 0;
}