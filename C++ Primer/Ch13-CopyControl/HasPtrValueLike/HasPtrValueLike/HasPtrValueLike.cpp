/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: HasPtrValueLike.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-14
* 이전 버전 작성 일자:
* 버전 내용: HasPtr을 값처럼 행동하는 클래스로 만들기 - 깊은 복사(Deep Copy)
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
		:ps(new string(s)), i(0) {
		cout << "Call Constructor" << endl; // 생성자 호출 확인
	}
	// 복사 생성자
	// 큰 차이는 없다.
	// 복사 생성자에서는 string을 동적으로 할당하여 별도의 string을 가지게 된다.
	HasPtr(const HasPtr &rhs)
		:ps(new string(*rhs.ps)), i(rhs.i) {
		cout << "Call Copy Constructor" << endl;
	}
	// 대입 연산자(오버로딩, 복사 대입)
	// 신경써야 할 부분이 좀 있다.
	HasPtr &operator=(const HasPtr &rhs)
	{
		// 자기 자신을 복사하는 경우
		// 사실 이 부분은 안넣어도 되긴 한다.
		// 단지 아래의 동적 할당과 대입이라는 추가적인 연산을 하는 것을 원하지 않는다면 바로 return을 하면 된다.
		if (this == &rhs)
		{
			cout << "Self Copy" << endl;
			return *this; // 객체를 반환한다.
		}

		// 이 부분이 좀 중요한 부분이다.
		auto new_ps = new string(*rhs.ps); // 임시로 새로운 string 객체를 복사 대상 객체의 string으로 초기화.
		delete ps; // 복사하기 이전에 동적으로 할당한 string을 해제.
		ps = new_ps; // 새로운 string 객체를 가리키게 한다.
		i = rhs.i; // 값이므로 그냥 복사하면 됨.

		cout << "Call Copy operator=()" << endl;

		return *this; // 객체를 반환한다.
	}
	// 소멸자
	// 동적으로 할당하는 멤버에 대한 할당 해제가 필요
	~HasPtr()
	{
		cout << "Call Destructor" << endl;
		delete ps; // 동적으로 할당한 string 객체의 메모리를 해제.
	}
};

// 간단한 복사 생성자와 대입 생성자가 필요함을 이해하기 위한 함수
// 복사 생성자가 호출되는 시점을 이해하기 좋은 예제.
// 여기서만 3회 일어난다.
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
	//HasPtr copyPtr1(hasPtr); // 복사 생성자 호출
	//HasPtr copyPtr2 = hasPtr; // 복사 대입 생성자가 호출될 것 같지만, 복사 생성자 호출. (복사 초기화)
	//copyPtr2 = copyPtr2; // 복사 대입 연산자 호출, 단 자기 자신을 복사하는 상황
	//copyPtr2 = copyPtr1; // 복사 대입 연산자 호출

	f(hasPtr); // f를 호출하면서 복사 생성자는 hasPtr을 복사하게 된다.
	// 그리고 복사본은 f 함수를 빠져나오면서 소멸한다.

	return 0;
}
// main 함수까지 종료되면 그때 hasPtr이 소멸되며, 할당한 메모리도 소멸됨.