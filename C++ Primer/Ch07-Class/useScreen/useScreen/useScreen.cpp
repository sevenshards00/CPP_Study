/*
* C++ Primer - Class (클래스)
* 파일명: useScreen.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: 추가적인 클래스 기능 - main
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Screen.h"

int main(int argc, const char* argv[])
{
	Screen myScreen(5, 3);
	// 해당 위치로 커서를 이동하고 '#' 문자로 설정
	myScreen.move(4, 0).set('#');

	Screen nextScreen(5, 5, 'X');
	nextScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	nextScreen.display(cout);
	cout << endl;

	const Screen blank(5, 3);
	myScreen.set('#').display(cout); // const가 아닌 버전의 display 호출
	cout << endl;
	blank.display(cout); // const 버전의 display 호출
	cout << endl;

	myScreen.clear('Z').display(cout);
	cout << endl;
	myScreen.move(4, 0);
	myScreen.set('#');
	myScreen.display(cout);
	cout << endl;
	myScreen.clear('Z').display(cout);
	cout << endl;

	// 만약 move 함수의 반환형을 참조자로 하지 않았을 경우
	Screen temp = myScreen.move(4, 0);
	temp.set('#');
	myScreen.display(cout);
	cout << endl;

	return 0;
}