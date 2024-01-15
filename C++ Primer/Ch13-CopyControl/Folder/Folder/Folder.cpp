/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: Folder.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-15
* 이전 버전 작성 일자:
* 버전 내용: 복사 제어 예제 - 메일 처리 응용 프로그램 (class 구현)
* 이전 버전 내용:
*/

#include <set>
using std::set;

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include "Folder.h"

// Message 전용 swap
void swap(Message &lhs, Message &rhs)
{
	using std::swap; // 꼭 필요한 using 선언은 아니지만 좋은 습관이다.

	// 각각의(원럐) Folder에서 각 Message를 제거
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	// contents와 Folder의 포인터 set을 교환(swap)
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);

	// 각각의 (새) Folder에 각 Message에 대한 포인터를 추가.
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

/*
* Message Class Part 시작
*/
// 유틸리티 멤버 함수
void Message::add_to_Folders(const Message &m) // 해당 매개변수를 가리키고 있는 Folder에 Message를 추가
{
	for (auto f : m.folders) // m을 담고 있는 각 Folder에 대해 그 Folder에 해당 Message 객체에 대한 포인터를 추가.
		f->addMsg(this);
}

void Message::remove_from_Folders() // folders의 모든 Folder에서 Message를 제거.
{
	for (auto f : folders) // folders 내부의 각 포인터에 대해서
		f->remMsg(this); // 해당 Folder에서 Message를 제거.
	folders.clear(); // 해당 Message를 가리키는 Folder는 이제 없음.
}

// 복사 생성자
Message::Message(const Message &m)
	:contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}
// 대입 연산자(오버로딩, 복사)
Message &Message::operator=(const Message &rhs)
{
	remove_from_Folders(); // Message에 대한 포인터를 추가하기 전에 자기 대입 처리를 위해 기존 Folder를 갱신.
	// 이후에 하는 일은 복사 생성자와 동일.
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
// 소멸자
Message::~Message()
{
	remove_from_Folders(); // 유틸리티 함수를 이용하여 소멸.
}

// 지정한 Folder의 Message set에서 Message를 추가/제거
// Message 추가
void Message::save(Folder &f)
{
	folders.insert(&f); // Folder의 set에 지정한 Folder를 추가
	f.addMsg(this); // f의 Message set에 Message를 추가.
}

void Message::remove(Folder &f)
{
	folders.erase(&f); // Folder의 set에 지정한 Folder를 제거
	f.remMsg(this); // f의 Message set에 Message를 제거
}
// 디버깅용, 폴더의 목록과 각 폴더에 있는 메시지를 출력하는데 사용
void Message::debug_print()
{
	cerr << "Message:\n\t" << contents << endl;
	cerr << "Appears in " << folders.size() << " Folders" << endl;
}
/*
* Message Class Part 끝
*/

/*
* Folder Class Part 시작
*/
Folder::Folder(const Folder &f) // 복사 생성자
	:msgs(f.msgs)
{
	add_to_Messages(f);
}

Folder &Folder::operator=(const Folder &f) // 대입 연산자 오버로딩(복사)
{
	remove_from_Msgs();
	msgs = f.msgs;
	add_to_Messages(f);
	return *this;
}

Folder::~Folder() // 소멸자
{
	remove_from_Msgs();
}

void Folder::save(Message &m) // Message를 Folder에 저장
{
	// add m and add this folder to m's set of Folders
	msgs.insert(&m);
	m.addFldr(this);
}

void Folder::remove(Message &m) // Message를 Folder에서 제거
{
	// erase m from msgs and remove this folder from m
	msgs.erase(&m);
	m.remFldr(this);
}

void Folder::debug_print() // 디버깅용 print, contents와 Folder의 목록을 출력
{
	cerr << "Folder contains " << msgs.size() << " messages" << endl;
	int ctr = 1;
	for (auto m : msgs) {
		cerr << "Message " << ctr++ << ":\n\t" << m->contents << endl;
	}
}

// 복사 생성자, 대입, 소멸자에서 사용할 유틸리티 함수
void Folder::add_to_Messages(const Folder &f) // 해당 Folder에 각 Message를 추가하는 함수
{
	for (auto msg : f.msgs)
		msg->addFldr(this);   // add this Folder to each Mess
}

void Folder::remove_from_Msgs() // 해당 Folder에 각 Message를 제거하는 함수
{
	while (!msgs.empty())
		(*msgs.begin())->remove(*this);
}
void Folder::addMsg(Message *m) { msgs.insert(m); }
void Folder::remMsg(Message *m) { msgs.erase(m); }
/*
* Folder Class Part 끝
*/