/*
* Fundamental C++ - Ch04-Memory
* 파일명: DestructorCall.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-22
* 이전 버전 작성 일자:
* 버전 내용: delete의 동작 방식 이해하기
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

class CTestA
{
public:
	CTestA() { cout << "Call Constructor A\n"; }
	~CTestA() { cout << "Call Destructor A\n"; }
};

class CTestB
{
public:
	CTestB() { cout << "Call Constructor B\n"; }
	~CTestB() { cout << "Call Destructor B\n"; }
};

int main()
{
	CTestA *pA = new CTestA;

	CTestB *pB = (CTestB *)pA;
	
	delete pB;
	
	/*
	* 실제로 이런 정신 나간 코드를 쓰면 안되지만, 이론상 알아둘만한 부분이 있어서 작성.
	* delete의 동작 방식은 간단함.
	* delete 대상 포인터의 타입만 가지고 판단을 함.
	* 
	* 다시 말하지만 위와 같이 정신나간 코드는 쓰면 안됨.
	* 현재 클래스에는 멤버 변수가 없음.
	* 그리고 생성자나 소멸자에서 멤버 변수에 접근하지 않기 때문에 아무런 문제가 없는 것뿐임.
	* 실제로 멤버 변수나 함수가 있는 클래스였고, 생성자나 소멸자 부분에서 멤버 변수에 접근하는 부분이 있다면 뻑나는 코드가 되었을 것.
	*/

	return 0;
}