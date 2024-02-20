/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: Main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-20
* 이전 버전 작성 일자:
* 버전 내용: VS2022의 디버그 빌드에서의 변수 초기값 확인 예제
* 이전 버전 내용:
*/

// 해당 코드를 실행하려면 VS의 안전 장치를 모두 끄고 실행해야 한다.

#pragma warning (disable : 4700);

#include <iostream>
using std::cout;
using std::hex;

int main()
{
	int i;
	cout << hex << i << '\n';			// 초기화되지 않은 지역 변수의 초기값
										// VS2022 기준 cccccccc로 나옴
										// 실제로 int로 4byte만 할당했지만 디버그 빌드에서는 실제 변수의 메모리 앞뒤로 4바이트씩 더 잡는다.

	int *p = new int;
	cout << hex << *p << '\n';			// 동적 할당 이후 초기화되지 않은 지역 변수의 초기값 -> cdcdcdcd
	cout << hex << *(p - 1) << '\n';	// 동적 할당 이후 해당 포인터의 이전 위치의 값 -> fdfdfdfd
	cout << hex << *(p + 1) << '\n';	// 동적 할당 이후 해당 포인터의 다음 위치의 값 -> fdfdfdfd

	delete p;
	cout << hex << *p << '\n';			// 동적 할당 한 메모리 해제 이후의 값 -> dddddddd

	return 0;
}