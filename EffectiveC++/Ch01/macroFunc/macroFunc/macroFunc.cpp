/*
* Effective C++ - Ch01
* 파일명: macroFunc.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-30
* 이전 버전 작성 일자:
* 버전 내용: 매크로 함수보다 인라인 함수를 사용하는 것이 나은 예시
* 이전 버전 내용:
*/

#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))

#include <iostream>
using std::cin;
using std::cout;

#include <Windows.h>
#include <tchar.h>

/*
* 함수 호출을 줄일 수 있지만 매크로 함수는 생각처럼 동작하지 않을 가능성이 크다.
* 그러므로 가능하다면 inline을 이용한 template을 쓰는 방향을 생각해라.
*/
template <typename T>
inline void callWithMax(const T &a, const T &b)
{
	a > b ? a : b;
}

int _tmain(int argc, TCHAR *argv[])
{
	DWORD a = 5;
	DWORD b = 0;

	/*
	* 이런 코드를 쓸 일은 거의 지양해야 하겠지만 그래도 재밌는 예시라서 정리해둔다.
	* 위의 매크로 함수를 대입해보면 다음과 같이 볼 수 있다.
	* CALL_WITH_MAX(++a, b) ((++a) > (b) ? (++a) : (b))
	* 일반적인 함수가 아니라 매크로 함수는 값을 치환해서 그대로 때려박는 개념이다.
	* 그래서 결과에 따라 증가하는 값이 달라지는데 a가 더 클 경우에는 비교하면서 한 번, 그리고 결과 값으로 한 번 더 증가하게 된다.
	* 반대로 a가 작아서 b가 결과로 나오는 경우에도 한 번은 증가하게 된다.
	*/

	CALL_WITH_MAX(++a, b); // a가 2번 증가
	cout << a << '\n';
	CALL_WITH_MAX(++a, b + 10); // a가 1번만 증가
	cout << a << '\n';

	a = 5;
	b = 0;

	callWithMax(++a, b);
	cout << a << '\n';
	callWithMax(++a, b + 10);
	cout << a << '\n';


	return 0;
}