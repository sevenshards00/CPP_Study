/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: Main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: 실행 공간과 오브젝트 공간 개념 예제 - ODR(One Definition Rule)
* 이전 버전 내용:
*/

// 반환 타입은 다르지만 동일한 함수 선언
// 따라서 Compile Error 발생
// 중복 정의가 되어있다면 사용할 함수의 선언만 사용한다.
int Func2(int arg);
//double Func2(int arg);

int main()
{
	Func2(1);

	return 0;
}