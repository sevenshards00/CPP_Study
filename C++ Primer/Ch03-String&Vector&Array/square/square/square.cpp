/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: square.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: vector 템플릿 사용 예제(3) - 배열을 이용한 vector 초기화, 목록 초기화 사용 및 범위 for문에서의 접근 방법
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

#define LIST_INIT // 목록 초기화를 사용할 경우 주석처리하지 않는다.

#ifndef LIST_INIT
#include <iterator>
using std::begin;
using std::end;
#endif

int main(int argc, const char* argv[])
{
#ifdef LIST_INIT // 목록 초기화(List Init)을 하는 경우 -> vector에 값을 목록으로 대입
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
#else // 목록 초기화를 하지 않는 경우 -> 배열을 vector로
	int temp[] = { 1,2,3,4,5,6,7,8,9 };
	// 배열의 처음부터 끝까지 vector를 초기화할 범위를 지정.
	// C++11 표준으로 추가된 라이브러리 함수 begin과 end
	// 반복자와 유사하게 사용하는 것이 가능해진다.
	vector<int> v(begin(temp), end(temp));
#endif
	for (auto& i : v) // 각 요소에 대해 접근, i는 참조자로 정의해야 새 값을 대입할 수 있다.
		i *= i; // i = i * i;

	for (auto i : v)      // vector의 각 요소에 접근.
		cout << i << " "; // 결과를 출력한다.
	cout << endl;

	return 0;
}