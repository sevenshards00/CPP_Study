/*
* C++ Primer - Function (함수)
* 파일명: printFcns.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: 함수 다중 정의(함수 오버로딩) 예제 - 소스 코드
* 이전 버전 내용:
*/
#include <iostream>
using std::endl; using std::cout;

#include <vector>
using std::vector;

#include <iterator>
using std::begin; using std::end;

// 소스 코드 순서가 복잡하게 되어 있어 임의로 정리.
// C++ Primer에서 제공하는 good_printmain.cpp와 stl-arr-fcns.cpp를 정리한 소스 코드

void print(const char* cp)
{
	if (cp)          // cp가 널 포인터가 아니라면
		while (*cp)  // 널 문자를 만날 때까지 반복
			cout << *cp++;  // 화면에 문자를 출력, 포인터 연산을 통해 다음 위치로 이동.
}
void print(const int* beg, const int* end)
{
	// 범위를 인자로 받은 경우이므로, 시작부터 끝까지 반복
	while (beg != end)
		cout << *beg++ << " "; // 현재 원소를 출력, 포인터 연산을 통해 다음 위치로 이동.
}

void print(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
	// vector라고 달라질 부분은 없다.
	// 마찬가지로 범위를 인자로 받은 경우이므로, 시작부터 끝까지 반복
	while (beg != end)
		cout << *beg++ << " "; // 현재 원소를 출력, 반복자를 다음 위치로 이동.
}

void print(const int ia[], size_t size) // 인자로 배열과 배열의 크기를 받는다.
{
	for (size_t i = 0; i != size; ++i) // 크기만큼 반복
	{
		cout << ia[i] << endl;
	}
}

void print(const vector<int>& beg)
{
	for (auto i : beg)
		cout << i << endl;
}