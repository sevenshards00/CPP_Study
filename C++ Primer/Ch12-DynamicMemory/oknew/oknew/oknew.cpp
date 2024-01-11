/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: oknew.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: 동적 할당 (new, delete) 기본 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

#include <new>
using std::nothrow;

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

size_t get_size() { return 42; }

int main(int argc, const char *argv[])
{
	// 위치 지정 new 사용 예시
	int *p1 = new int; // 위치 지정 new를 사용하지 않음 -> 기본적으로 new에서 요청한 저장 공간 할당이 불가능하면 bad_alloc타입 예외를 발생
	int *p2 = new (nothrow) int; // 위치 지정 new를 사용 -> 예외를 발생시키지 않으며 저장 공간 할당이 불가능하면 널 포인터 반환.

	int i0; // 초기화가 되지 않은 이름이 있는 int형 변수

	int *p0 = new int; // p0은 동적으로 할당된 이름이 없는, 초기화되지 않은 int를 가리킨다.

	delete p0; // p0가 가리키고 있는 동적 할당된 메모리 공간을 해제한다.

	// 이름이 있는 변수 초기화 방법
	int i(1024); // i는 1024
	string s(10, '9'); // s는 '9'를 10개 가지는 string

#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#endif

	// 이름이 없는 동적 할당된 변수 (또는 객체) 초기화 방법
	int *pi = new int(1024); // pi가 가리키는 변수(또는 객체)의 값은 1024
	string *ps = new string(10, '9'); // *ps는 9를 10개 가지고 있는 string을 가리킨다.

#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	vector<int> *pv = new vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // *pv는 0~9까지 10개의 원소를 지닌 vector를 가리킨다.
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	vector<int> *pv = new vector<int>;
	for (int i = 0; i != 10; ++i)
		pv->push_back(i);
#endif
	cout << "*pi: " << *pi
		<< "\ti: " << i << endl
		<< "*ps: " << *ps
		<< "\ts: " << s << endl;

	// vector의 값을 출력
	for (auto b = pv->begin(); b != pv->end(); ++b)
		cout << *b << " ";
	cout << endl;

	// 동적 할당한 변수 및 객체의 메모리 해제
	delete pi;
	delete ps;
	delete pv;

	// 배열을 동적으로 할당하는 경우
	int *pia = new int[get_size()]; // pia는 int[42]만큼의 배열을 가리키는 포인터, 값은 초기화되어 있지 않음
	delete[] pia; // 동적 할당한 배열의 메모리를 해제, 배열을 해제할 때에는 []를 포함해야 한다.
	typedef int arrT[42]; // arrT를 int가 42개인 배열 타입으로 별칭 부여
	int *p = new arrT; // p는 int가 42개인 배열을 가리키는 포인터
	delete[] p; // 동적 할당한 배열의 메모리를 해제.

	return 0;
}