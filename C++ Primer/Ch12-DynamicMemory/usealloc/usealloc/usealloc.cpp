/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: usealloc.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자:
* 버전 내용: allocator 사용 예제 (1)
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <memory>
using std::allocator;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

int main(int argc, const char *argv[])
{
	const size_t n = 100;
	allocator<string> alloc; // string에 대한 allocator 객체 생성
	auto p = alloc.allocate(n); // string 객체 100개에 대한 메모리 공간만 할당. string 객체는 생성되지 않았음.
	
	// q는 마지막으로 생성된 요소 바로 다음 (끝 지난) 위치를 가리키는 포인터로 사용.
	// 현재 q == p이므로 동적 할당한 메모리 공간에 아무런 것도 없는 상황.
	auto q = p;
	alloc.construct(q++); // 실제 객체 생성. *q는 빈 string.
	cout << *(q - 1) << endl;

	// construct의 추가 인자는 해당 객체의 생성자와 일치해야 한다.
	// 여기서는 해당 객체가 string이므로 string의 생성자에 맞춰서 객체를 생성
	alloc.construct(q++, 10, 'c'); // c가 10개인 string인 객체 생성. *q는 cccccccccc이 된다.
	cout << *(q - 1) << endl;

	alloc.construct(q++, "hi"); // "hi"인 string 객체 생성, *q는 hi가 된다.
	cout << *(q - 1) << endl;

	cout << *p << endl; // 첫 번째 string 객체를 가리키고 있으므로 문제없이 출력.
	// cout << *q << endl; // q는 객체를 생성하지 않은 메모리 공간만을 가리키고 있다. -> 컴파일 에러는 없지만 무슨 일이 발생할지 모른다.

	while (q != p)
		alloc.destroy(--q); // 실제로 할당한 string 객체를 가장 마지막에 생성한 것부터 처음 생성한 순서대로 객체를 소멸한다.

	// 할당한 메모리를 시스템에 반환.
	// 여기서 전달하는 p는 nullptr이면 안되며, allocate로 할당한 메모리를 가리켜야 함.
	// 전달하는 크기 인자 또한 allocate 호출 시 사용한 크기와 동일해야 함.
	alloc.deallocate(p, n);

	// 미초기화 메모리를 복사하고 채우는 알고리즘
	p = alloc.allocate(n); // 다시 string 100개만큼의 메모리 공간을 할당.
	string s;
	q = p; // 현재 q는 맨 첫번쨰 string 객체가 생성될 위치를 가리킨다.
	ifstream in("data\\storyDataFile"); // 파일 입력 스트림 생성
	//ifstream in(argv[1]); // 파일 입력 스트림 생성
	cout << in.is_open() << endl;
	while (in >> s && q != p + n)
		// 파일에서 string을 가져와서 string 객체를 생성.
		// 실제로 필요한 만큼의 string 객체만 생성한다.
		alloc.construct(q++, s); 

	size_t size = q - p; // 전체 string 객체의 갯수

	cout << "read " << size << " strings" << endl;

	for (q = p + size - 1; q != p; --q)
		alloc.destroy(q); // 생성한 객체를 역순으로 소멸

	// 동적으로 string 배열을 사용하는 경우
	alloc.deallocate(p, n); // 할당한 메모리를 시스템에 반환한다.
	in.close();

	in.open("data\\storyDataFile"); // 파일 입력 스트림을 다시 개방.
	//in.open(argv[1]);
	p = new string[n]; // 100개의 string 배열을 할당, 동시에 빈 string 객체도 100개가 생성된다.
	q = p; // 마찬가지로 맨 처음 요소(string)를 가리키게 된다.

	while (in >> s && q != p + n)
		*q++ = s;

	size = q - p;

	cout << "read " << size << " strings" << endl;
	
	delete [] p; // 동적으로 할당한 배열이므로 delete []를 사용하여 메모리 할당을 해제해야 한다.
	return 0;
}