/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: Main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: 클래스 중복 정의로 인한 문제 발생 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

// Main.cpp에서의 CTest 클래스 정의
// 멤버 변수의 위치에 주목.
class CTest
{
public:
	// 생성자
	CTest(int a, int b) :m_ValA(a), m_ValB(b) { }

	int m_ValA;	// m_ValA
	int m_ValB;	// m_ValB
};

CTest g_Test(1, 2);		// 전역 CTest 객체를 정의

int GetValA();			// 함수 선언

int main()
{
	cout << GetValA() << '\n';	// 예상과 다른 값이 나온다.

	return 0;
}

/*
* 예상과 다르게 2가 나온 이유에 대해서
* 
* A.cpp와 Main.cpp에서 클래스의 정의를 할 때, 멤버 변수의 위치를 바꿔서 놓았음.
* C의 구조체에서도 동일하게 적용할 수 있는 부분.
* 실제로 구조체의 멤버 변수를 선언하면 그 변수 자체가 고정적인 영역이 되는 것이 아님.
* 클래스(또는 구조체)의 멤버 변수에 접근하는 것은 해당 멤버 변수의 메모리 offset에 의해서 계산된 위치에 따라 접근하게 되는 것.
* 그래서 멤버 변수의 이름은 어디까지나 offset 계산을 위해서 사용되는 것일 뿐, 고정된 메모리 영역이 아니라는 점이다.
* g_Test(1, 2)에 의해 Main.cpp의 클래스 정의에 따라 m_ValA는 1, m_ValB에는 2가 저장되어 있는 상황이다.
* 그런데 A.cpp의 클래스 정의는 m_ValB, m_ValA로 정의가 되어 있다.
* A.cpp의 GetValA()를 호출하여 m_ValA의 값을 가져오게 되면 여기서는 A.cpp의 클래스 정의에 따라 m_ValA의 값을 가져오게 된다.
* 앞에서 offset 계산을 통해 위치에 접근한다 했으므로, 실제 멤버를 접근할 때에는 두 번째 멤버에 접근하게 되는 것.
* 그래서 결과가 2가 나오게 된 것이다.
* 
* 해당 예제는 어디까지나 클래스(또는 구조체)의 멤버에 접근하는 것은 offset에 의해서 접근한다는 사실을 확인한 것.
* 또한 클래스 정의가 달라졌을 때의 극단적인 상황을 재현한 것이다.
* 코드 작성도 중요하지만 소스 파일 관리도 잘해야된다는 점.
* 중요한 개념이므로 잘 이해해둘 것.
*/