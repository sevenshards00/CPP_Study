/*
* Fundamental C++ - Ch06-Class
* 파일명: MemberOffset.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-26
* 이전 버전 작성 일자:
* 버전 내용: 클래스 내의 메모리 배치 규칙 확인 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

class CTest
{
public:
	// 일반 멤버 변수는 클래스 객체의 메모리 영역에 있음.
	char m_Char;
	int m_Int;
	double m_Double;

	// 정적 멤버 변수는 가상 메모리의 Data 영역 -> 클래스를 통해서만 접근
	static int m_SInt;

	// 멤버 함수는 가상 메모리의 Code 영역 -> 마찬가지로 클래스를 통해서만 접근
	int MemberFunc()
	{
		return m_Int;
	}
};

class CEmpty
{
	// 생성자, 소멸자만 있는 클래스
	// 멤버 변수로 취하는 것이 아무것도 없으므로 0바이트일 것 같지만 1바이트가 잡힌다.
public:
	CEmpty() {}
	~CEmpty() {}
};

class CVirtualEmpty
{
	// 소멸자가 가상 소멸자로 있는 클래스
	// 이렇게 될 경우 가상 함수를 위한 가상 함수 테이블이 생성
	// 가상 함수 테이블 포인터가 추가가 되기 때문에 x86(32비트)에서는 4바이트, x64(64비트)에서는 8바이트의 크기가 잡힌다.
public:
	CVirtualEmpty() {}
	virtual ~CVirtualEmpty() {}
};

int main()
{
	CTest t;
	t.m_Char = 'A';
	t.m_Int = 1;
	t.m_Double = 3.14;

	// 클래스 내의 멤버 오프셋을 구하는 방법
	int OffsetC = (int)(&(((CTest *)0)->m_Char));
	int OffsetI = (int)(&(((CTest *)0)->m_Int));
	int OffsetD = (int)(&(((CTest *)0)->m_Double));

	// offsetof로도 구할 수 있으며 위와 동일
	int OffsetC2 = offsetof(CTest, m_Char);
	int OffsetI2 = offsetof(CTest, m_Int);
	int OffsetD2 = offsetof(CTest, m_Double);

	// 실제 결과를 보면 기대했던 것과는 다음 -> 구조체와 마찬가지로 Padding이 붙는다.
	cout << OffsetC << '\t' << OffsetC2 << '\n';
	cout << OffsetI << '\t' << OffsetI2 << '\n';
	cout << OffsetD << '\t' << OffsetD2 << '\n';

	CEmpty e;
	CVirtualEmpty ve;

	cout << sizeof(e) << '\n';
	cout << sizeof(ve) << '\n';

	return 0;
}