/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: UP.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: 스마트 포인터(unique_ptr, shared_ptr)과 동적 배열
* 이전 버전 내용:
*/

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	// unique_ptr
	// unique_ptr은 new로 할당한 배열을 관리하는 것이 가능.
	// unique_ptr에서 배열을 가리킬 때에는 . 과 -> 로 접근하는 것이 불가능
	// 객체가 아닌 배열 그 자체를 가리키기 때문에 위의 연산자를 사용할 필요가 없음.
	unique_ptr<int[]> up(new int[10]); // up는 초기화하지 않은 10개의 int를 가지는 동적할당 배열을 가리킨다.
	for (size_t i = 0; i != 10; ++i)
		up[i] = i; // 배열 그 자체를 가리키기 때문에 첨자([]) 연산이 가능.

	for (size_t i = 0; i != 10; ++i)
		cout << up[i] << " ";
	cout << endl;
	up.release(); // 해당 포인터를 삭제하면서 자동으로 delete[]를 사용하여 할당을 해제.

	// shared_ptr
	// shared_ptr는 unique_ptr과 달리 동적 배열을 직접 관리할 수 없음.
	// 그래서 별도로 삭제자(deleter)를 만들어서 지정해줘야 한다.
	// unique_ptr과 달리 배열이 아닌 객체 자체를 가리키므로 . 과 -> 로 접근하는 것이 가능
	// share_ptr은 첨자 연산자가 없으므로 직접 첨자 연산이 불가능. 마찬가지로 포인터 연산을 이용한 배열 접근도 불가능.
	shared_ptr<int> sp(new int[10], [](int *p) {delete[] p; }); // 삭제자로 함수 호출성 객체를 인자로 전달, 여기서는 람다 표현식을 이용.
	for (size_t i = 0; i != 10; ++i)
		*(sp.get() + i) = i; // get()을 이용하여 내장 포인터를 사용. 배열을 포인터 연산으로 접근하듯이 사용 가능.
	for (size_t i = 0; i != 10; ++i)
		cout << (sp.get())[i] << " "; // 내장 포인터를 이용해서 첨자 연산도 가능하다.
	cout << endl;
	sp.reset(); // 삭제자로 전달한 함수 호출성 객체를 사용하여 배열을 해제한다.

	return 0;
}