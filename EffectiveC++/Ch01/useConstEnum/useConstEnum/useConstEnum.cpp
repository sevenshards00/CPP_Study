/*
* Effective C++ - Ch01
* 파일명: useConstEnum.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-30
* 이전 버전 작성 일자:
* 버전 내용: const(또는 constexpr), enum이 유용한 경우
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;

#include <Windows.h>
#include <tchar.h>

/*
* 전처리기를 이용하여 상수를 정의하는 방법
* 그런데 이 ASPECT_RATIO는 사실 변수명은 아님
* 이 값이 들어가면 이걸 그대로 치환해서 박아버림
* 지금 VS에서는 개발환경이 좋아서 에디터에서 매크로를 써도 잘 나오긴 한다.
* 하지만 디버깅을 한다고 생각하면 이 값에 대한 심볼(Symbol)을 유추할 수가 없다. -> 값으로 치환되기 때문
* 프로그램의 분석을 난해하게 할 수 있으므로 심볼로 찾을 수 있는 상수를 쓰는 것이 훨씬 유익하다.
*/

#define ASPECT_RATIO 1.653

/*
* 실제로 VS에서는 매크로로 상수를 정의하게 되면 해당 값을 constexpr로 바꿀 수 있다는 제안을 한다.
* 마찬가지로 const나 consexpr로 컴파일 타임에 값을 정할 수 있는 상수의 경우에는 매크로보다 상수로 쓰는 것이 낫다.
* 프로그램을 컴파일한 결과에 대해서도 다르다.
* 매크로로 상수를 사용할 경우 사용한 빈도만큼 복사본이 나오기 때문에 컴파일한 최종 코드가 늘어나게 된다.
* 하지만 상수를 사용하게 되면 딱 하나만 생성되기 때문에 최종 코드의 크기가 늘어나지 않는다.
*/
// 이렇게 써도 된다.
// const double AspectRatio = 1.653;
constexpr double AspectRatio = 1.653;

class GamePlayer
{
private:
	/*
	// 과거 일부 컴파일러에서는 이걸 허용하지 않았다고 하는데 지금은 다 허용하므로 크게 신경쓸 필요 없음.
	// static const int NumTurns = 5; // 마찬가지로 이렇게 써도 됨
	// static constexpr int NumTurns = 5; // 클래스의 static 상수 '선언'
	여기서 잘못 알면 안되는 것은 NumTurns는 상수를 정의(definition)한 것이 아니라 '선언(declaration)'한 것.
	정적 멤버로 만들어지는 정수류 타입의 클래스 내부 상수는 예외로 친다. 그래서 정의가 아니라 '선언'이라고 한 것.
	*/
	static constexpr double FudgeFactor = 1.35; // 지금은 굳이 정수형 뿐만이 아니라 실수형도 정의를 하면서 초기값을 줄 수 있음.
	
	/*
	* 열거형을 사용한 극한의 꼼수.
	* 1) 이 방식은 const나 constexpr과 달리 #define과 같이 동작.
	* 선언한 정수 상수를 가지고 주소값을 얻는다거나 참조자를 쓰는 것도 허용하지 않겠다는 의도라면 이 방식을 사용할 수 있음.
	* 특히 #define처럼 별도의 메모리를 추가로 할당하는 경우도 없음.
	* 2) 실제로 많은 코드들을 보면 이런 방법을 많이 애용하고 있음.
	* 그래서 이런 식으로 쓰여진 코드를 보면 당황하지 말고 이렇게 쓰이고 있음을 알아둘 것.
	* TMP(Template Meta Programming, 흑마법)의 핵심 기법 중 하나
	*/
	enum { NumTurns = 5 }; // enum hack(나열자 둔갑술 또는 열거형 둔갑술) -> 클래스 내에서 멤버로 배열을 선언하는 경우 배열의 크기를 이런 식으로 쓸 수 있음
	int scores[NumTurns];
};


int _tmain(int argc, TCHAR *argv[])
{
	cout << ASPECT_RATIO << '\n';
	cout << AspectRatio << '\n';

	return 0;
}