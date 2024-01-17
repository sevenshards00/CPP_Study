/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: moveHP.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-17
* 이전 버전 작성 일자:
* 버전 내용: 이동 생성자를 추가한 HasPtr 클래스
* 이전 버전 내용:
*/

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <utility>

#define NOEXCEPT

class HasPtr
{
	friend void swap(HasPtr &, HasPtr &);
public:
	// 생성자
	HasPtr(const string &s = string())
		:ps(new string(s)), i(0)
	{
		cout << "Call Constructor" << endl;
	}
	// 복사 생성자
	HasPtr(const HasPtr &rhs)
		:ps(new string(*rhs.ps)), i(rhs.i)
	{
		cout << "Call Copy Constructor" << endl;
	}

	// 이동 생성자
#ifdef NOEXCEPT // C++11 표준 이상 noexcept를 지원하는 경우
	HasPtr(HasPtr &&p) noexcept
		:ps(p.ps), i(p.i)
	{
		p.ps = 0;
		cout << "Call Move Constructor" << endl;
	}
#else // C++11 표준 미만 noexcept를 지원하지 않는 경우
	HasPtr(HasPtr &&p) throw()
		:ps(p.ps), i(p.i)
	{
		p.ps = 0;
	}
#endif
	// 대입 연산자
	// 복사 대입과 이동 대입을 둘 다 한다.
	HasPtr &operator=(HasPtr rhs)
	{
		swap(*this, rhs);
		return *this;
	}
	// 소멸자
	// 동적으로 할당하는 멤버에 대한 할당 해제가 필요
	~HasPtr()
	{
		cout << "Call Destructor" << endl;
		delete ps;
	}
private:
	string *ps;
	int i;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps); // string이 아닌 포인터를 swap
	swap(lhs.i, rhs.i); // int 멤버를 swap
}

int main(int argc, const char *argv[])
{
	HasPtr hasPtr("Hello there!"); // 생성자 호출
	HasPtr copyPtr1(hasPtr); // 복사 생성자 호출
	HasPtr copyPtr2 = hasPtr; // 복사 대입 생성자가 호출될 것 같지만, 복사 생성자 호출. (초기화되는 시점)
	copyPtr2 = copyPtr1; // 복사 생성자 호출
	copyPtr2 = std::move(copyPtr1); // 이동 생성자를 호출

	return 0;
}