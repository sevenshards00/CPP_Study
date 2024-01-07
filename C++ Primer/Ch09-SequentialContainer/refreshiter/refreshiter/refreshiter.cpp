/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: refreshiter.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: 반복문을 이용한 컨테이너의 변경과 반복자 갱신 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#define LIST_INIT // 목록 초기화 사용할 경우(C++11 이상)

#ifndef LIST_INIT // 목록 초기화를 사용하지 않을 경우
#include <itreator>
using std::begin;
using std::end;
#endif

void printVec(const vector<int>& vi)
{
	auto iter = vi.begin();
	while (iter != vi.end())
		cout << *iter++ << endl;
}

int main(int argc, const char* argv[])
{
#ifdef LIST_INIT // 목록 초기화 사용할 경우(C++11 이상)
	vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
#else // 목록 초기화를 사용하지 않을 경우
	int temp[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vi(begin(temp), end(temp));
#endif
	printVec(vi);

	auto iter = vi.begin();
	// 짝수 값은 제거하고 홀수 값 요소만 중복해서 삽입하는 while
	while (iter != vi.end())
	{
		if (*iter % 2) // 홀수일 경우
		{
			iter = vi.insert(iter, *iter); // vector에 insert
			iter += 2; // 현재 요소와 그 요소 앞에 삽입한 값을 건너뛴다.
		}
		else // 짝수일 경우
			iter = vi.erase(iter); // 해당 요소를 제거한다.
		// 여기서는 반복자를 따로 갱신하지 않는다.
		// 삭제한 요소 바로 다음을 나타내기 때문.
	}
	printVec(vi);

	return 0;
}