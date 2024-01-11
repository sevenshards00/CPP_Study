/*
* C++ Primer - Dynamic Memory & Smart Pointer (동적 메모리와 스마트 포인터)
* 파일명: release.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-11
* 이전 버전 작성 일자:
* 버전 내용: unique_ptr의 release, reset 연산 사용 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	unique_ptr<string> p1(new string("Stegosaurus")); // p1은 동적 할당한 string 객체를 가리킨다.
	// p1의 소유권을 p2로 넘기는 과정
	// p1.release()는 p1에 담고 있는 포인터에 대한 제어를 포기한다.
	// 그리고 p1에 담겨있던 포인터를 반환하면서 p1은 nullptr을 가리키게 된다.
	// 여기서는 p2에 p1의 포인터가 담기게 된다.
	unique_ptr<string> p2(p1.release());
	cout << *p2 << endl;

	unique_ptr<string> p3(new string("Trex")); // p3에 동적 할당한 string 객체를 가리킨다.

	// p3의 소유권을 p2로 소유권을 넘기는 과정
	// p2.reset()일 경우에는 p2가 가리키는 객체를 삭제한다.
	// p2.reset(p3.release()) 일 경우에는 다음과 같다.
	// p3.release()에 의해서 p3의 포인터가 반환된다.
	// 그리고 p2는 p3가 가리키는 객체를 가리키게 된다.
	// 결과적으로는 p3 = nullptr, p2에는 p3의 "Trex"가 들어있는 string 객체를 가리키게 된다.
	p2.reset(p3.release());
	cout << *p2 << endl;

	// p1과 p3가 null이 아니라면 아래의 if문에 있는 출력문이 실행.
	if (p1)
		cout << "p1 not null?" << endl;
	if (p3)
		cout << "p2 not null?" << endl;

	cout << *p2 << endl;
	return 0;
}