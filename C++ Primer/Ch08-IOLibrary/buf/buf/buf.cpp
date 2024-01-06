/*
* C++ Primer - I/O Library (I/O 라이브러리)
* 파일명: buf.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: 출력 버퍼를 비우는 여러 방법 및 버퍼링 여부 조작 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::flush;
using std::ends;
using std::unitbuf;
using std::nounitbuf;
using std::endl;

int main(int argc, const char* argv[])
{
	// "hi!"와 개행문자(\n)를 출력 버퍼에 넣고 버퍼를 비운다.
	cout << "hi!" << endl;

	// "hi!"를 출력 버퍼에 넣고 버퍼를 비워버린다.(flush)
	cout << "hi!" << flush;

	// "hi!"와 마지막에 널문자(\0)를 출력 버퍼에 넣고 버퍼를 비운다.  
	cout << "hi!" << ends;

	cout << unitbuf; // 모든 출력을 버퍼에 넣지 않고 즉시 내보낸다.

	// 모든 출력이 즉시 비워지며, 버퍼링을 하지 않음
	// 여기서 endl을 안넣어도 콘솔 화면으로 출력이 된다.
	cout << "first" << "second" << endl;

	// 다시 일반적인 버퍼 상태로 되돌린다.
	cout << nounitbuf;

	return 0;
}