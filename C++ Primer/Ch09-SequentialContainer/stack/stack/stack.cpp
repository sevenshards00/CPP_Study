/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: stack.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: 컨테이너 어댑터 예제 - stack
* 이전 버전 내용:
*/

// 자료구조에 대해서 공부하고 나면 STL을 왜 공부하라고 하는지 이해가 된다.
// 자료구조를 모르는 상태에서 컨테이너 어댑터에 대한 공부는 잠시 뒤로 미루는 것이 좋다고 본다.

#include <cstddef>
using std::size_t;

#include <deque>
using std::deque;

#include <stack>
using std::stack;

#include <iostream>
using std::cout; using std::cerr; using std::endl;

int main(int argc, const char* argv[])
{
	stack<int> intStack;  // 빈 스택

	// 스택을 채운다.
	for (size_t ix = 0; ix != 10; ++ix)
		intStack.push(ix);   // stack의 push연산과 마찬가지로 0부터 9까지 스택에 채운다.

	// while문의 조건 역시 stack에서의 empty연산을 이용
	while (!intStack.empty()) {
		int value = intStack.top(); // top()은 stack의 peek와 같다. 값을 삭제하지 않고 요소의 값만 확인
		cout << value << endl;
		intStack.pop(); // stack의 pop연산과 동일. stack의 가장 위에 있는 요소를 꺼내어 삭제한다.
	}

	return 0;
}