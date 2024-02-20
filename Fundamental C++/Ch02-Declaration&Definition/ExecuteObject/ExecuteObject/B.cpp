/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: B.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: 실행 공간과 오브젝트 공간 개념 예제 - ODR(One Definition Rule)
* 이전 버전 내용:
*/

int g_ValB;				// B.cpp의 전역 변수 선언 및 정의 -> 문제 없음.
//int g_ValCommon;		// A.cpp와 B.cpp 양쪽에서 선언 -> 중복 정의: 같은 이름의 전역 변수는 실행파일(실행공간) 내에서 단 한 번만 정의되어야 함 -> Link Error
static int s_ValCommon;	// B.cpp의 전역 static 변수 -> 문제 없음. 각 소스 파일(오브젝트 공간) 별로 독립적

// double을 인자로 받는 Func1
// A.cpp에도 Func1이 정의되어 있으나, 인자의 타입이 다름
// 따라서 문제 없음
int Func1(double arg)
{
	return 1;
}

// 반환형이 double인 Func2
// A.cpp에도 Func2가 정의되어 있으나, 반환형이 다름
// 따라서 문제 없음
double Func2(int arg)
{
	return 2.0;
}

// A.cpp에도 동일한 함수가 정의되어 있으며, 어떤 함수를 호출해야할지 모호해짐
// Link Error
//int Func3(int arg)
//{
//	return 32;
//}

// B.cpp에서 정의한 CTest1 클래스
// 멤버 변수가 int형
// 클래스의 중복 정의는 문제가 없음.
// 컴파일 시 에러는 없지만, 다른 소스 파일에서 클래스의 정의가 다를 경우 실행 중(Run-time)에 문제가 발생한다.
class CTest1
{
public:
	int m_Int;
};

// B.cpp에서 정의한 CTest2 클래스
// 멤버 변수가 int형
// 클래스의 중복 정의는 문제가 없음.
// 또한 B.cpp의 클래스 정의와 일치하므로 실행 중(Run-time) 문제도 발생하지 않음.
class CTest2
{
public:
	int m_Val;
};