/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: StrVec.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-15
* 이전 버전 작성 일자:
* 버전 내용: 복사 제어 예제 - Vector<string> 흉내내기 - StrVec class 구현
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <memory>
using std::allocator;
using std::initializer_list;

#include <utility>
using std::pair;

#include "StrVec.h"

allocator<string> StrVec::alloc;

// 중괄호 목록 초기화를 하는 생성자
#ifdef INIT_LIST // C++11 표준 이상 목록 초기화를 사용하는 경우
StrVec::StrVec(initializer_list<string> il)
{
	auto newData = alloc_n_copy(il.begin(), il.end());
	elements = newData.first;
	first_free = newData.second;
	cap = newData.second;
}
#else
StrVec::StrVec(const std::string *b, const std::string *e)
{
	auto newData = alloc_n_copy(b, e);
	element = newData.first;
	first_free = newData.second;
	cap = newData.second;
}
#endif
// 복사 생성자
StrVec::StrVec(const StrVec &s)
{
	// alloc_n_copy를 사용하여 s의 요소 수만큼 할당.
	auto newData = alloc_n_copy(s.begin(), s.end());
	elements = newData.first;
	first_free = newData.second;
	cap = newData.second;
}

// 대입 연산자 오버로딩(복사 대입)
StrVec &StrVec::operator=(const StrVec &rhs)
{
	// 먼저 오른쪽 값을 복사
	// 자기 대입을 할 수도 있기 때문에 우선 복사부터 한다.
	auto cpy = alloc_n_copy(rhs.begin(), rhs.end());
	free(); // 왼쪽의 값을 할당 해제
	elements = cpy.first;
	first_free = cpy.second;
	cap = cpy.second;
	return *this;
}

// 소멸자
StrVec::~StrVec()
{
	free();
}

// vector에서 제공하는 기본 연산들의 멤버 함수
// push_back -> 요소 복사
void StrVec::push_back(const string &s)
{
	chk_n_alloc(); // capacity가 충분한지 먼저 확인 -> 아니라면 재할당됨
	alloc.construct(first_free++, s); // first_free가 가리키고 있는 위치에 요소를 추가.  -> 여기서 string의 복사 생성자 호출.
}

// alloc_n_copy -> vector간 복사 및 대입에서 사용
// 복사 생성자, 대입 연산자, 소멸자에서 사용할 utility 함수
// 포인터가 아니라 값처럼 행동하는 클래스다 -> Deep Copy
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	// 범위 내의 요소를 담을 수 있을 만큼의 공간을 할당
	auto data = alloc.allocate(e - b);
	// 초기화 이후 data와 uninitialized_copy에서 반환한 값을 pair로 return한다.
	// uninitialized_copy는 미초기화된 메모리 공간을 복사하고 채우는데 사용.
	// 반환하는 값은 생성한 마지막 요소 바로 다음을 가리킨다.
	return { data, uninitialized_copy(b, e, data) };

}
void StrVec::free() // vector의 요소를 소멸, 공간을 해제하는 함수
{
	// elements가 0이라면 빈 vector이므로 할당한 메모리 공간이 없음.
	if (elements)
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p); // 마지막 요소에서부터 역순으로 요소를 destroy
		alloc.deallocate(elements, cap - elements); // StrVec에서 할당한 공간을 실제로 해제
	}
}
// vector의 공간 재할당이 필요할 경우 재할당을 하는 함수
void StrVec::reallocate()
{
	// 현재 요소 크기의 2배만큼 공간을 할당한다.
	// 만약 요소가 아예 없다면 요소 1개에 대한 공간만 할당.
	// 이후 2배씩 키운다.
	auto newCapacity = size() ? 2 * size() : 1;
	// 새로운 메모리를 할당
	auto newData = alloc.allocate(newCapacity);
	// 이전 할당된 메모리 공간에서 새로 할당된 메모리 공간으로 이동한다.
	auto dest = newData; // 새로 할당될 공간을 가리킨다.
	auto elem = elements; // 할당되기 이전의 vector를 가리킨다.

	// 복사가 아닌 이동이다.
	// std::move를 썼음을 확인하자.
	// 라이브러리 함수 move는 string의 이동 생성자를 사용하겠다는 것을 알린다.
	// 만약 move를 호출하지 않으면 복사 생성자를 이용하여 값을 복사하게 된다.
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free(); // 이전 공간은 할당 해제한다.
	// 새로 할당된 공간을 가리킬 수 있도록 vector의 요소 위치를 갱신
	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}