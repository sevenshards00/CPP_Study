/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: A.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: 실행 공간과 오브젝트 공간 개념 예제 - ODR(One Definition Rule)
* 이전 버전 내용:
*/

int g_ValA;				// A.cpp의 전역 변수 선언 및 정의 -> 문제 없음.
int g_ValCommon;		// A.cpp와 B.cpp 양쪽에서 선언 -> 중복 정의: 같은 이름의 전역 변수는 실행파일(실행공간) 내에서 단 한 번만 정의되어야 함 -> Link Error
static int s_ValCommon;	// A.cpp의 전역 static 변수 -> 문제 없음. 각 소스 파일(오브젝트 공간) 별로 독립적

static int s_ValA;		// A.cpp의 전역 static 변수 -> 여기서는 문제 없음
//static int s_ValA;	// 여기서 문제. 같은 소스 파일(오브젝트 공간) 내에서 같은 이름의 전역 static 변수는 존재할 수 없음. -> Compile Error

// int를 인자로 받는 Func1
// B.cpp에도 Func1이 정의되어 있으나, 인자의 타입이 다름
// 따라서 문제 없음
int Func1(int arg)
{
	return 1;
}

// 반환형이 int인 Func2
// B.cpp에도 Func2가 정의되어 있으나, 반환형이 다름
// 따라서 문제 없음
int Func2(int arg)
{
	return 2;
}

// B.cpp에도 동일한 함수가 정의되어 있으며, 어떤 함수를 호출해야할지 모호해짐
// Link Error
int Func3(int arg)
{
	return 31;
}

// 반환형이 int인 FuncA
int FuncA(int arg)
{
	return 4;
}

// 반환형이 double인 FuncA
// 인자의 타입이 다르거나, 인자의 갯수가 달라야 함수 오버로딩
// 반환형만 다르면 함수 오버로딩이 아님
// Compile Error
//double FuncA(int arg)
//{
//	return 4;
//}

// A.cpp에서 정의한 CTest1 클래스
// 멤버 변수가 char형
// 클래스의 중복 정의는 문제가 없음.
// 컴파일 시 에러는 없지만, 다른 소스 파일에서 클래스의 정의가 다를 경우 실행 중(Run-time)에 문제가 발생한다.
class CTest1
{
public:
	char m_Char;
};

// A.cpp에서 정의한 CTest2 클래스
// 멤버 변수가 int형
// 클래스의 중복 정의는 문제가 없음.
// 또한 B.cpp의 클래스 정의와 일치하므로 실행 중(Run-time) 문제도 발생하지 않음.
class CTest2
{
public:
	int m_Val;
};

// A.cpp에서 정의한 CTestA 클래스
class CTestA
{
public:
	int m_Val;
};

// 클래스의 중복 정의는 가능하지만, 같은 소스 파일 내에서 재정의는 안된다.
// Compile Error
//class CTestA
//{
//public:
//	int m_Val;
//};