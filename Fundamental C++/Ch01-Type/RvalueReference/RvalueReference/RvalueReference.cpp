/*
* Fundamental C++ - Ch01-Type
* 파일명: RvalueReference.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: C++의 우측 값 참조(RValue Reference) 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

// RValue Return
int GetValue()
{
	int a = 1;
	return a;
}

// LValue Return
int &GetReference()
{
	int a = 2;
	return a;
}

// LValue Reference
void Func(int &arg)
{
	cout << "LValue Reference\n";
}

// RValue Reference
void Func(int &&arg)
{
	cout << "RValue Reference\n";
}

int main()
{
	Func(1);	// RValue Reference
	
	int a = 1;
	Func(a);	// LValue Reference

	Func(GetValue());		// RValue Reference
	
	Func(GetReference());	// LValue Reference

	return 0;
}