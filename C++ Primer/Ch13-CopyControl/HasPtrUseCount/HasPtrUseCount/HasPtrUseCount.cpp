/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: HasPtrValueLike.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-14
* 이전 버전 작성 일자:
* 버전 내용: HasPtr을 포인터처럼 행동하는 클래스로 만들기 - shared_ptr 따라하기
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

class HasPtr
{
private:
	string *ps;
	int i;
	size_t *use; // *ps를 공유하는 객체가 얼마나 많은지 추적하는 멤버 -> 참조 횟수(Reference Count)
public:
	// 생성자
	HasPtr(const string &s = string())
		:ps(new string(s)), i(0), use(new size_t(1)) // 최초 생성 시 참조 횟수는 1로 초기화.
	{
		cout << "Call Constructor" << endl;
		cout << "Reference Count: " << *use << endl;
	}
	// 복사 생성자
	HasPtr(const HasPtr &rhs)
		:ps(new string(*rhs.ps)), i(rhs.i), use(rhs.use) // 복사 생성자에서는 세 멤버 데이터를 모두 '복사'한다.
	{
		++(*use); // 참조 횟수를 증가.
		cout << "Call Copy Constructor" << endl;
		cout << "Reference Count: " << *use << endl;
	}
	// 대입 연산자(오버로딩, 복사 대입)
	// 마찬가지로 신경써야 할 부분이 좀 있다.
	HasPtr &operator=(const HasPtr &rhs)
	{
		// 중요한 부분.
		++(*rhs.use); // 오른쪽 피연산자의 참조 횟수를 먼저 증가.
		if (--(*use) == 0) // 왼쪽 객체의 참조 횟수를 감소시켰을 때 0이라면 -> 더 이상 공유하는 객체가 없는 것
		{
			// 소멸자와 동일한 일을 수행한다.
			delete ps;
			delete use;
		}

		// 이후에는 복사 대입 연산자의 일을 수행한다.
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;

		cout << "Call Copy operator=()" << endl;
		cout << "Reference Count: " << *use << endl;
		return *this;
	}
	// 소멸자
	// 동적으로 할당하는 멤버에 대한 할당 해제가 필요
	~HasPtr()
	{
		// shared_ptr처럼 행동하므로 무조건 할당을 해제하면 안된다.
		// 참조 횟수를 확인하고 0이 되었을 때 할당을 해제한다.
		
		cout << "Call Destructor" << endl;
		
		if (--(*use) == 0)
		{
			delete ps;
			delete use;
			cout << "Reference Count: 0" << endl;
		}
	}
};

HasPtr f(HasPtr hp) // 값으로 객체가 전달되기 때문에 이때 복사 초기화가 일어난다 -> 복사 생성자 호출
{
	HasPtr ret = hp; // 대입 연산자(=)를 사용할 때에도 복사 초기화가 일어난다 -> 복사 생성자 호출

	return ret; // 반환형이 참조자 타입이 아니므로 여기서도 복사 초기화가 일어난다. -> 복사 생성자가 호출
	// retern을 하면서 ret과 hp는 소멸 -> 유효 구간이 끝남.
	// 단, 컴파일러에서는 복사 생성자를 무시할 수도 있음 (Copy Ellision)
	// 그래서 여기서는 return에 의한 복사 생성자 호출이 확인되지 않는다.
}


int main(int argc, const char *argv[])
{
	HasPtr hasPtr("Hello there!"); // 생성자 호출
	HasPtr copyPtr1(hasPtr); // 복사 생성자 호출
	HasPtr copyPtr2 = hasPtr; // 복사 대입 생성자가 호출될 것 같지만, 복사 생성자 호출. (초기화되는 시점)
	copyPtr2 = copyPtr2; // 복사 대입 연산자 호출, 단 자기 자신을 복사하는 상황
	copyPtr2 = copyPtr1; // 복사 대입 연산자 호출

	f(hasPtr); // f를 호출하면서 복사 생성자는 hasPtr을 복사하게 된다.
	// 그리고 복사본은 f 함수를 빠져나오면서 소멸한다.

	return 0;
}