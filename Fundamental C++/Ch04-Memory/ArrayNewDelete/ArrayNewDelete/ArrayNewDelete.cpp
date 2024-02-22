/*
* Fundamental C++ - Ch04-Memory
* 파일명: ArrayNewDelete.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-22
* 이전 버전 작성 일자:
* 버전 내용: new[]와 delete[]의 내부 동작 이해
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

class CTest
{
public:
	CTest() { cout << "Call Constructor\n"; }
	~CTest() { cout << "Call Destructor\n"; }
};

int main()
{
	// 실제로 new[]가 호출되기 전에 Stack에 인자가 추가로 전달된다.
	// malloc에 전달되는 인자는 실제로 다음과 같다.
	// x86 => (클래스 크기 * 배열 요소 개수) + 4byte
	// x64 => (클래스 크기 * 배열 요소 개수) + 8byte
	// 이 4byte와 8byte는 배열 요소의 갯수만큼 소멸자를 호출하기 위해 배열 요소 개수를 저장하기 위한 공간을 추가로 할당한 것.
	// 
	// 실제로 malloc()을 하고 나면 HeapManager에 의해 메모리가 할당이 되고, 배열 요소 개수를 추가로 할당한 공간에 기록
	// 이후 배열의 요소 개수만큼 반복해가며 생성자를 호출한다.
	// 
	// 이 추가된 공간은 delete[]를 할 때 의미가 있는데, delete[]가 내부적으로 동작할 때는 추가했던 공간에서 배열 요소의 개수를 확인한다.
	// 배열 요소의 개수만큼 소멸자를 호출하고, 마지막으로 HeapManager에 할당받은 포인터의 주소를 넘겨준다.
	// 그래서 배열 요소 개수만큼 소멸자 호출이 가능함과 동시에 할당된 메모리를 해제하게 되는 것.
	// 
	// 만약 new[]를 했는데 delete를 하는 경우에는?
	// 일단 소멸자 호출은 딱 한 번 일어난다.
	// 다만 할당 해제를 하기 위해 넘겨주는 포인터의 주소값이 일치하지 않게 된다.
	// 그래서 HeapManager는 할당 내역을 확인하려고 하는데 해당 주소를 찾지 못하게 되므로 메모리 할당 해제가 되지 않는다.
	// Debug 빌드에서는 안전 장치가 있어서 유효하지 않은 HeapPointer라는 경고를 받을 수 있다.
	// 메모리 해제 부분에서 오류가 나는 것이며, 이런 상황을 힙 충돌이 발생했다고 함.

	CTest *pArr = new CTest[2];
	delete[] pArr;

	return 0;
}
