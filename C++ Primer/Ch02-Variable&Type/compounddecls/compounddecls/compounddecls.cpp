/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: compounddecls.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: 복합 타입(참조자, 포인터)에 대한 변수 선언 및 정의 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	/*
	* 아래의 변수 선언과 정의를 정리하면 이렇게 된다.
	* int i = 1024;
	* int* p = &i;
	* int& r = i;
	* p는 int형 변수 i를 가리키는 포인터다.
	* r은 int형 변수 i를 참조하는 참조자다.
	*/
	int i = 1024, * p = &i, & r = i;

	/*
	* i를 참조하는 세 가지 방식
	* 1) i를 그대로 참조하여 사용한다.
	* 2) 포인터의 역참조를 통해 i에 접근한다.
	* 3) 참조자를 통해 i를 참조한다.
	*/
	cout << i << " " << *p << " " << r << endl;

	/*
	* 아래의 변수 선언과 정의를 정리하면 이렇게 된다.
	* int j = 42;
	* int* p2 = &j;
	* int*& pref = p2;
	* p2는 int형 변수 j를 가리키는 포인터다.
	* pref는 int형 포인터 p2를 참조하는 참조자다.
	*/
	int j = 42, * p2 = &j;
	int*& pref = p2;

	// j값을 출력하기 위해 참조자를 통한 역참조를 통해 j값에 접근한 예시
	cout << *pref << endl;

	// pref는 포인터를 참조하고 있다.
	// 그래서 &i를 참조자에 대입하면 포인터가 가리키는 변수를 i로 바꾼다.
	pref = &i;
	cout << *pref << endl; // i값이 출력

	// 역참조를 통해서 포인터가 가리키는 값에 접근하여 값을 변경.
	// 여기서는 i의 값이 0으로 바뀐다. 
	*pref = 0;

	cout << i << " " << *pref << endl;

	return 0;
}