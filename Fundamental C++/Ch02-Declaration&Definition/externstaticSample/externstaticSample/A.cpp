/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: A.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: extern과 static 키워드 사용 예제
* 이전 버전 내용:
*/

// 이 부분은 A.cpp와 Main.cpp
// 전역 객체 선언 및 정의
// 정의까지 하는 경우에는 extern을 생략할 수도 있음
// 하지만 선언만 하는 경우에는 extern 생략 불가
int g_Val;

// extern과 static의 차이
// 전역 객체로 사용할 경우 extern은 외부에서도 사용할 수 있는 전역 객체
// 반면에 전역 static 객체일 경우 A.cpp로만 유효 범위가 정해지는 정적 객체.
// 요약하자면 다음과 같음
// extern 키워드는 다른 소스 파일에서도 접근 가능하도록 링크를 허용하는 것.
// 반대로 static 키워드는 다른 소스 파일에서 접근할 수 없도록 링크를 허용하지 않는 것.
extern int g_Val2 = 0;
static int s_Val = 0;

// 함수 선언 및 정의
int Func()
{
	return 1;
}
// 이 부분은 A.cpp와 Main.cpp


// 이 부분은 A.cpp와 B.cpp
int g_Val3;		// 전역 객체 선언 및 정의 -> 이 경우에는 extern 생략 가능

//int g_Val3;	// 전역 객체를 재정의 -> Compile Error

extern int g_Val4 = 1;		// 전역 객체 선언 및 정의 (extern 키워드로 명시)

//extern int g_Val4 = 1;	// 전역 객체를 재정의 -> Compile Error

extern int g_Val5;			// 전역 객체 g_Val5에 대한 선언(extern)

// 이 부분은 A.cpp와 B.cpp

