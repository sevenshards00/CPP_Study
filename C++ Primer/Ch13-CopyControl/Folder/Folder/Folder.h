/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: Folder.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-15
* 이전 버전 작성 일자:
* 버전 내용: 복사 제어 예제 - 메일 처리 응용 프로그램 (class 정의)
* 이전 버전 내용:
*/

#ifndef __FOLDER_H__
#define __FOLDER_H__

#define DEFAULT_FCNS

#include <set>
#include <string>

class Folder;

class Message
{
	friend void swap(Message &, Message &); // Message 전용 swap
	friend class Folder;
private:
	std::string contents;
	std::set<Folder *> folders;
	// 복사 생성자, 대입, 소멸자에서 사용할 유틸리티 함수
	void add_to_Folders(const Message &); // 해당 매개변수를 가리키고 있는 Folder에 Message를 추가
	void remove_from_Folders(); // folders의 모든 Folder에서 Message를 제거.
	
	// Folder 클래스에서 Message의 Folder set에 자기 대입을 할 경우에 사용.
	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }

public:
	// 생성자 -> 암시적으로 set<Folder*>는 빈 set로 만든다.
	explicit Message(const std::string &str = "")
		:contents(str) {}
	// Message 객체에 대한 포인터를 관리하기 위한 복사 제어 파트
	// 복사 생성자
	Message(const Message &);
	// 대입 연산자(오버로딩, 복사)
	Message &operator=(const Message &);
	// 소멸자
	~Message();

	// 지정한 Folder의 Message set에서 Message를 추가/제거
	void save(Folder &);
	void remove(Folder &);
	void debug_print(); // 디버깅용, 폴더의 목록과 각 폴더에 있는 메시지를 출력하는데 사용
};

// Message에 대한 swap 함수. 비멤버 함수.
void swap(Message &, Message &);

class Folder
{
	friend void swap(Message &, Message &); // Message 전용 swap
	friend class Message;
private:
	std::set<Message*> msgs; // Folder 내에 있는 Message들을 담는 set

	// 복사 생성자, 대입, 소멸자에서 사용할 유틸리티 함수
	void add_to_Messages(const Folder &); // 해당 Folder에 각 Message를 추가하는 함수
	void remove_from_Msgs(); // 해당 Folder에 각 Message를 제거하는 함수
	void addMsg(Message *m);
	void remMsg(Message *m);
public:
	// 생성자 (디폴트 생성자)
#ifdef DEFAULT_FCNS // C++11 표준 이후 합성 기본 생성자(디폴트 생성자)를 사용할 경우
	Folder() = default;
#else // C++11 표준 이후 합성 기본 생성자(디폴트 생성자)를 사용하지 않을 경우
	Folder() { }
#endif
	// 복사 제어 관련
	Folder(const Folder &); // 복사 생성자
	Folder &operator=(const Folder &); // 대입 연산자 오버로딩(복사)
	~Folder(); // 소멸자

	void save(Message &); // Message를 Folder에 저장
	void remove(Message &); // Message를 Folder에서 제거
	void debug_print(); // 디버깅용 print, contents와 Folder의 목록을 출력
};

#endif