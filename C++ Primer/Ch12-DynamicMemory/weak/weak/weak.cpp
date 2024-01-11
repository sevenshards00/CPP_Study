/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: weak.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: weak_ptr 사용 예제
* 이전 버전 내용:
*/

#include <memory>
using std::make_shared;
using std::weak_ptr;
using std::shared_ptr;

int main(int argc, const char *argv[])
{ 
	auto p = make_shared<int>(42); // make_shared를 통해 동적으로 할당된 42를 가리키는 shared_ptr을 생성.

	// shared_ptr p를 공유한다.
	// 단, weak_ptr은 '약한' 공유를 한다. -> use_count(또는 reference count)가 증가하지 않는다.
	weak_ptr<int> wp(p); 

	// 만약 p.unique()의 결과가 true라면 -> use_count가 1이라면
	// reset()은 p가 가리키는 객체 할당 해제한다(삭제된다).
	p.reset(); 

	// wp.lock() 호출의 결과에 따라 달라진다.
	// p가 이미 메모리 할당을 해제했다면 null인 shared_ptr이 반환
	// 그게 아니라면 wp가 가리키는 객체에 대한 shared_ptr을 반환
	if (shared_ptr<int> np = wp.lock())
	{
		// 만약 if문 안에 들어왔다면 np는 null이 아니며, p와 해당 객체를 공유하게 된다.
	}

	return 0;
}