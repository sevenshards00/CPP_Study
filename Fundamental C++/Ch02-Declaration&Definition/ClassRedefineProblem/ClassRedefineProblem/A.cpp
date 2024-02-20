/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: A.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: 클래스 중복 정의로 인한 문제 발생 예제
* 이전 버전 내용:
*/

// A.cpp에서의 CTest 클래스 정의
// 멤버 변수의 위치에 주목하자.
class CTest
{
public:
	// 생성자
	CTest(int a, int b):m_ValA(a), m_ValB(b) { }
	
	int m_ValB;	// m_ValB
	int m_ValA;	// m_ValA
};

extern CTest g_Test;	// 전역 CTest 객체 선언

// 간단한 멤버 변수 getter
int GetValA()
{
	return g_Test.m_ValA;
}