/*
* C++ Primer - Overloaded Operations & Conversions (다중 정의 연산과 변환)
* 파일명: absInt.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-18
* 이전 버전 작성 일자:
* 버전 내용: 함수 호출 연산자를 사용한 함수 객체 및 람다 사용 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <iterator>
using std::inserter;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::transform;

// 절대값을 반환하는 함수 객체(Functor)
struct absInt
{
	// 함수 호출 연산자 오버로딩
	int operator()(int val) const
	{
		return val < 0 ? -val : val;
	}
};

int main()
{
	int i = -42;
	absInt absObj;
	unsigned ui = absObj(i);
	cout << i << " " << ui << endl;

	vector<int> vi;
	while (cin >> i)
		vi.push_back(i);

	vector<unsigned> vu;
	// 함수 객체를 네 번째 인자로 전달
	transform(vi.begin(), vi.end(), back_inserter(vu), absInt());

	// for_each의 세 번째 인자로 함수 호출성 객체를 전달 -> 함수 객체인 람다를 이용하여 출력
	for_each(vu.begin(), vu.end(), [](unsigned i) { cout << i << " "; });
	cout << endl;

	// 이번에는 람다를 네 번째 인자로 전달
	vector<unsigned> vu2;
	transform(vi.begin(), vi.end(), back_inserter(vu2),
		[](int i) {return i < 0 ? -i : i; });

	// 똑같이 수행되었는지 확인
	if (vu == vu2)
		cout << "as expected" << endl;
	else // 실행될 리는 없지만 실행되면 vector 내의 값을 확인
	{
		cout << "something's wrong, vectors differ" << endl;
		for_each(vu.begin(), vu.end(), [](unsigned i) { cout << i << " "; });
	}
	cout << endl;

	return 0;
}