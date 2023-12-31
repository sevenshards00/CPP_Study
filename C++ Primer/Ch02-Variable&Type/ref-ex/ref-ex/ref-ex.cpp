/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: ref-ex.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: 참조자(Reference) 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int i = 0, & ref_i = i;  // ref_i는 변수 i를 참조하는 참조자다.
	/*
	* 이렇게 변수를 선언하고 정의한 것과 동일.
	* int i = 0;
	* int& ref_i = i;
	*/

	// ref_i는 단지 변수 i에 또 다른 이름을 부여한 것이다.
	// 여기서 참조자는 참조자일 뿐, 변수(또는 객체)는 아니다. 
	
	cout << i << " " << ref_i << endl;

	i = 5; // i의 값을 변경하면 참조자에도 반영이 된다.
	cout << i << " " << ref_i << endl;

	ref_i = 10; // 마찬가지로 참조자를 통해서 값을 변경하면 원래 참조하던 대상에도 반영된다.
	cout << i << " " << ref_i << endl;

	return 0;
}
