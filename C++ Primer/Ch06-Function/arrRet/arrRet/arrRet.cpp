/*
* C++ Primer - Function (함수)
* 파일명: arrRet.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: 배열에 대한 포인터 반환 예제
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

int arr[10]; // int 형 요소가 10개인 배열 arr
int* p1[10]; // int* 형 요소가 10개인 배열 p1
int(*p2)[10] = &arr; // 배열 포인터, 데이터는 int형이고 요소는 10개를 가지고 있는 배열을 가리킨다. 여기서 p2는 arr을 가리킴

// 타입 별칭을 사용해서 반환형을 간략화
#ifdef TYPE_ALIAS_DECLS // using을 사용할 경우
using arrT = int[10];
#else // 아닌 경우, typedef를 사용
typedef int arrT[10];
#endif

// 타입 별칭을 사용하면 다음과 같이 함수의 반환형을 사용 가능
arrT* func(int i); // 타입 별칭을 이용한 경우
auto func(int i) -> int(*)[10]; // 후행 반환(trailing return type)을 사용한 경우
int(*func(int i))[10]; // 타입 별칭 없이 직접 선언하는 경우 -> 위와 동일하다.
auto func2(int i) -> int(&)[10]; // 후행 반환을 사용한 경우, 여기서는 배열의 참조형을 반환.

// 홀수와 짝수 배열을 정의
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };

// elemPtr 함수는 int*을 반환하는 함수
int* elemPtr(int i)
{
	// 입력받은 인자를 통해 배열의 첫 번째 요소(배열의 주소값)을 반환
	return (i % 2) ? odd : even;
}

// 5개의 int형 데이터를 가지는 배열에 대한 포인터를 반환
decltype(odd)* arrPtr(int i)
{
	return (i % 2) ? &odd : &even; // 배열에 대한 포인터를 반환. 
}

// 5개의 int형 데이터를 가지는 배열에 대한 참조자를 반환
int(&arrRef(int i))[5]
{
	return (i % 2) ? odd : even;
}
int main()
{
	int* p = elemPtr(6); // p는 int형 포인터
	int(*arrP)[5] = arrPtr(5); // arrP는 5개의 int형 데이터를 가지는 배열을 가리키는 포인터.
	int(&arrR)[5] = arrRef(4);  // arrR은 5개의 int형 데이터를 가지는 배열을 참조하는 참조자.
	for (size_t i = 0; i < 5; ++i)
		cout << p[i] << endl; // p는 배열의 첫 번째 요소(주소값)을 가지고 있으므로 첨자([])를 통해 접근 가능
	for (size_t i = 0; i < 5; ++i)
		// arrP는 배열을 가리키는 포인터다. 그래서 역참조를 통해 아래와 같이 접근한다.
		cout << (*arrP)[i] << endl;
	for (size_t i = 0; i < 5; ++i)
		// arrR은 배열에 대한 참조자이므로 첨자([])를 통해 접근 가능.
		cout << arrR[i] << endl;
	return 0;
}