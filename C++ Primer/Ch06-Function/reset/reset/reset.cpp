/*
* C++ Primer - Function (함수)
* 파일명: reset.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-04
* 이전 버전 작성 일자:
* 버전 내용: 함수에 인자를 전달하는 방식 (Call-By-Value, Call-By-Reference)
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// Call-By-Reference
void reset(int& i)
{
	i = 0;
}

//Call-By-Value, 포인터 사용
void reset(int* ip)
{
	*ip = 0; // 역참조를 통해 값에 접근, 인자로 전달된 값이 가리키는 값을 변경
	ip = 0; // 매개변수 ip의 값을 변경, 함수로 전달된 인자가 바뀌지는 않음.
}

int main(int argc, const char* argv[])
{
	int j = 42;
	reset(j); // Call-By-Reference, reset(int& i)를 호출하게 된다.
	cout << "j = " << j << endl;

	j = 42;
	reset(&j); // Call-By-Value, 주소값을 인자로 전달하고 있으므로 reset(int* ip)를 호출.
	cout << "j = " << j << endl;

	j = 42;
	int* p = &j;
	reset(p); // Call-By-Value, 위와 동일하다.
	cout << "j = " << *p << endl;

	return 0;
}