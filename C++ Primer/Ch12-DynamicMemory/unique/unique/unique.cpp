/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: unique.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: shared_ptr의 unique 사용 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;

int main(int argc, const char *argv[])
{
	// shared_ptr<string> p = new string("Hello!"); -> 안된다.
	// 위와 같이 암시적으로 내장 포인터를 스마트 포인터로 초기화하는 것은 불가능하다.
	// shared_ptr의 생성자는 explicit으로 되어있기 때문에 명시적으로 직접 초기화를 해야한다.
	// 그리고 기존의 내장 포인터를 스마트 포인터를 초기화하는 것이 가능하다.
	shared_ptr<string> p(new string("Hello!"));
	shared_ptr<string> p2(p);
	// 현재 p와 p2가 할당된 string을 가리키는 상황(공유 중)
	string newVal(" World!");

	cout << "before p.use_count(): " << p.use_count() << endl;
	cout << "before p2.use_count(): " << p2.use_count() << endl;

	// unique는 shared_ptr의 use_count가 1이면 true, 아니면 false
	if (!p.unique()) // use_count가 1이 아니라면 다른 곳에서 참조를 하고 있는 것이므로 p를 reset해도 된다.
		p.reset(new string(*p)); // reset 후 새로운 복사본을 할당한다. 여기서는 다시 Hello!를 복사.
	*p += newVal;

	cout << "after p.use_count(): " << p.use_count() << endl;
	cout << "after p2.use_count(): " << p2.use_count() << endl;

	cout << "*p: " << * p << "\n*p2: " << *p2 << endl;
}