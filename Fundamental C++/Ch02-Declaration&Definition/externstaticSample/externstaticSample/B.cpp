/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: B.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: extern과 static 키워드 사용 예제
* 이전 버전 내용:
*/

extern int g_Val3;	// A.cpp의 전역 객체 g_Val3에 대한 선언(extern)

//int g_Val3;		// A.cpp의 전역 객체 g_Val3을 재정의 -> Compile Error

extern int g_Val4;			// A.cpp의 전역 객체 g_Val4에 대한 선언(extern)

extern int g_Val5;			// 전역 객체 g_Val5에 대한 선언(extern)

//extern int g_Val4 = 2;	// A.cpp의 전역 객체 g_Val4를 재정의 -> Compile Error

