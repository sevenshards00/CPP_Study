/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: DeclarationDefinitionSample.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: C++에서의 선언과 정의 예제
* 이전 버전 내용:
*/

/*
* 선언: 해당 객체를 사용하기 위하여 객체의 존재를 알리기 위함
* 정의: 객체를 만드는 것. 더 정확하게 말하면 해당 객체를 만들기 위한 메모리 공간을 할당한다는 것을 의미.
* 정의에는 선언이 포함됨. -> 즉 정의를 하면 선언도 동시에 되는 것. 역은 성립하지 않음.
*/

/*
// 클래스 선언
class CTest	
{

};
*/

/*
* 클래스 선언 및 정의
* 클래스가 정의 == 클래스의 설계도
* 클래스가 정의되는 경우 일반적인 변수와는 좀 다르다.
* 일반적인 변수는 '프로세스가 사용하는 가상 메모리'를 사용.
* 클래스는 '프로세스의 가상 메모리'가 아닌 '컴파일러의 메모리 공간'을 사용한다.
* 그래서 클래스를 정의할 때는 '컴파일러가 사용하는 메모리 공간'에 할당된다.
*/
class CTest
{
public:
	// 멤버 함수의 선언 및 정의
	int MFunc(int arg)
	{
		return arg;
	}
private:
	int m_value; // 멤버 변수의 선언
};

// 전역 객체 선언 및 정의
// 데이터(DATA) 영역의 메모리 공간에 할당
// 정확히는 초기화되지 않았으므로 bss(Block Started by Symbol) 영역에 메모리가 할당
int g_Val;		 
int g_Arr[2];
CTest g_T;

int main()
{
	// 지역 객체 선언 및 정의
	// 지역 객체는 스택(STACK) 영역의 메모리 공간에 할당
	int i;
	int iarr[2];
	CTest t;

	return 0;
}

// 함수 선언 및 정의
// 함수는 코드(CODE) 영역에 어셈블리로 변경되어 저장
int Add(int a, int b)
{
	return a + b;
}