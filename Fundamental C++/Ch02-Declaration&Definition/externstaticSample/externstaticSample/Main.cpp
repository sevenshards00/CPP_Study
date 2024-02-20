/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: Main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: extern과 static 키워드 사용 예제
* 이전 버전 내용:
*/

// A.cpp에서 선언 및 정의한 함수와 객체에 대한 선언이 없으면 main 함수 내에서는 해당 객체가 있는지 인지하지 못함.
// 그래서 아래와 같이 외부에서 선언 및 정의된 객체와 함수임을 선언해야 인식할 수 있음.
extern int g_Val;
int Func();

// A.cpp에서 해당 객체에 접근을 시도
// 컴파일 에러는 나오지 않는다.
extern int g_Val2;
//extern int s_Val;

int main()
{
	g_Val = Func();

	g_Val2 = 1;		// 여기는 문제가 없지만
	//s_Val = 2;		// 여기서 Link Error가 발생한다.
					// A.cpp의 전역 static 객체에 접근하려 했기 때문에 다른 소스 파일에서는 접근을 할 수 없게 했으므로 Linker에서 에러를 띄우게 됨.

	return 0;
}