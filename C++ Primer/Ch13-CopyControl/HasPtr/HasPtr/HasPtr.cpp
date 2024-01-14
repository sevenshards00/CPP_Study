/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: HasPtr.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-14
* 이전 버전 작성 일자:
* 버전 내용: 복사 생성자, 복사 대입 생성자, 소멸자에 대한 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

class HasPtr
{
private:
	string *ps;
	int i;
public:
	// 생성자
	HasPtr(const string &s = string())
		:ps(new string(s)), i(0) { cout << "Call Constructor" << endl; }
	// 복사 생성자
	HasPtr(const HasPtr &rhs)
		:ps(new string(*rhs.ps)), i(rhs.i) { cout << "Call Copy Constructor" << endl; }
	// 대입 연산자(오버로딩, 복사 대입)
	// 신경써야 할 부분이 좀 있다.
	HasPtr& operator=(const HasPtr &rhs)
	{
		// 자기 자신을 복사하는 경우
		if (this == &rhs)
		{
			cout << "Self Copy" << endl;
			return *this;
		}

		// 이 부분이 좀 중요한 부분이다.
		auto new_ps = new string(*rhs.ps); // 임시로 새로운 string 객체를 복사 대상 객체의 string으로 초기화.
		delete ps; // 복사하기 이전에 동적으로 할당한 string을 해제.
		ps = new_ps; // 새로운 string 객체를 가리키게 한다.
		i = rhs.i;

		cout << "Call Copy operator=()" << endl;

		return *this;
	}
	// 소멸자
	// 동적으로 할당하는 멤버에 대한 할당 해제가 필요
	~HasPtr()
	{
		cout << "Call Destructor" << endl;
		delete ps;
	}
};

int main(int argc, const char *argv[])
{
	HasPtr hasPtr("Hello there!"); // 생성자 호출
	HasPtr copyPtr1(hasPtr); // 복사 생성자 호출
	HasPtr copyPtr2 = hasPtr; // 복사 대입 생성자가 호출될 것 같지만, 복사 생성자 호출. (초기화되는 시점)
	copyPtr2 = copyPtr2; // 복사 대입 연산자 호출, 단 자기 자신을 복사하는 상황
	copyPtr2 = copyPtr1; // 복사 대입 연산자 호출

	return 0;
}