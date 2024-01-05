/*
* C++ Primer - Function (함수)
* 파일명: refret-ex.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: 참조자를 반환하는 예제 (2) - 참조자는 lvalue(좌변값)
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int& get(int* arry, int index)
{
	return arry[index];
}

int main(int argc, const char* argv[])
{
	int ia[10];

	for (int i = 0; i != 10; ++i)
		get(ia, i) = i;
	// int& arry[i] = i;

	for (auto i : ia) // 범위 for문을 이용하여 처음부터 끝까지 출력
		cout << i << " ";
	cout << endl;

	return 0;
}