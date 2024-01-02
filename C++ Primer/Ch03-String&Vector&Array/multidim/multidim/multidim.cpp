/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: multidim.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 배열(Array) 사용 예제(3) - 다차원 배열(2차원 배열 이상) 다루기
* 이전 버전 내용:
*/

#define CONSTEXPR_VARS
#define TYPE_ALIAS_DECLS

#include <iterator>
using std::begin;
using std::end;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <cstddef>
using std::size_t;

int main(int argc, const char* argv[])
{
	int ia1[3][4]; // 3행 4열의 2차원 배열, 초기화는 하지 않음

	int arr[10][20][30] = { 0 }; // 3차원 배열 예시, 전부 0으로 초기화.

	ia1[2][3] = arr[0][0][0]; // 2행 3열의 요소를 3차원 배열의 첫 번째 요소를 복사

	int(&row)[4] = ia1[2]; // row에 ia1의 3번째 행을 대입.

	// 2차원 배열을 초기화 하는 방법 1 - {}를 사용해서 행별로 구분
	int ia2[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	// 2차원 배열을 초기화하는 방법 2 - 목록 초기화를 하면 알아서 맞춰 초기화됨
	int ia3[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

	// 2차원 배열을 초기화하는 방법 3 - 각 행별로 요소를 모두 0, 4, 8로 초기화
	int ia4[3][4] = { { 0 }, { 4 }, { 8 } };

	// 2차원 배열을 초기화하는 방법 4 - 첫 행만 초기화, 나머지는 0으로 초기화.
	int ix[3][4] = { 0, 3, 6, 9 };

	cout << ix[0][3] << ' ' << ix[1][0] << ' ' << ix[2][0] << endl;

#ifdef CONSTEXPR_VARS // CONSTEXPR을 사용할 경우
	constexpr size_t rowCnt = 3, colCnt = 4;
#else // 사용하지 않는 경우
	const size_t rowCnt = 3, colCnt = 4;
#endif
	int ia[rowCnt][colCnt];   // 3행 4열의 초기화되지 않은 2차원 배열 

	// 각 행에 대한 접근
	for (size_t i = 0; i != rowCnt; ++i)
	{
		// 각 열에 대한 접근
		for (size_t j = 0; j != colCnt; ++j)
		{
			// 각 인덱스에 값을 대입
			ia[i][j] = i * colCnt + j;
		}
	}

	// 2차원 배열을 출력하는 4가지 방법
	// 1. 중첩 범위 for문 사용
	for (const auto& row : ia) // 행을 반복문 처리
		for (auto col : row)   // 열에 대해 반복문 처리
			cout << col << endl; // 배열의 각 요소 출력
	
	cout << ia[0][0] << ' ' << ia[2][3] << endl;


	// 2. 포인터를 사용, 기존의 for문을 이용하여 접근
	// 포인터 연산을 통해서 마지막 포인터 값을 계산하여 사용
	for (auto p = ia; p != ia + rowCnt; p++) // 행에 대한 반복문
	{
		for (auto q = *p; q != *p + colCnt; q++) // 열에 대한 반복문
			cout << *q << ' ';
		cout << endl;
	}

	// 3. 포인터를 기존의 for문을 이용하여 접근
	// 포인터 연산이 아닌 라이브러리 함수인 begin과 end를 사용한다.
	for (auto p = begin(ia); p != end(ia); p++) // 행에 대한 반복문
	{
		for (auto q = begin(*p); q != end(*p); ++q) // 열에 대한 반복문
			cout << *q << ' ';  // 마찬가지로 각 요소에 대해 출력
		cout << endl;
	}

	// 4. using을 이용한 타입 별칭을 사용
#ifdef TYPE_ALIAS_DECLS // 타입 별칭을 사용하는 경우
	using int_array = int[4]; // int_array를 int[4]의 별칭으로 부여 
#else
	typedef int int_array[4]; // using을 지원하지 않는 경우 다음과 같이 사용
#endif

	for (int_array* p = ia; p != ia + 3; p++)
	{
		for (int* q = *p; q != *p + 4; q++)
			cout << *q << ' ';
		cout << endl;
	}

	// 배열을 초기화하고 요소에 값을 대입하는 또 다른 방법
	int alt_ia[rowCnt][colCnt]; // 초기화 되지 않은 3행 4열의 2차원 배열 
	size_t cnt = 0;
	// 범위 for문을 이용
	for (auto& row : alt_ia) // 각 행에 대한 반복문
		for (auto& col : row) // 각 열에 대한 반복문
		{
			col = cnt; // 배열 요소에 값을 대입
			cnt++; // cnt 값을 증가시키며 0부터 11까지 대입하게 된다.
		}
	// 배열에 값이 제대로 들어갔는지 확인
	for (const auto& row : alt_ia) // 행에 대한 반복문
		for (auto col : row)     // 열에 대한 반복
			cout << col << endl;

	return 0;
}