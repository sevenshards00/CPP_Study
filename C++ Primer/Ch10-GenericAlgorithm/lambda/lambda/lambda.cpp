/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: lambda.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 람다 표현식에서의 갈무리 목록(캡처 목록)과 반환 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

void fcn1()
{
	size_t v1 = 42; // 지역 변수
	auto f = [v1] {return v1; }; // 람다 표현식, 갈무리 목록(또는 캡처 목록)에 지역 변수 v1
	
	v1 = 0;
	auto j = f(); // j = 42, 람다 표현식을 생성할 때, 함수 호출성 객체 f에 v1을 복사하여 저장
	cout << j << endl;
}

void fcn2()
{
	size_t v1 = 42; // 지역 변수
	auto f2 = [&v1] {return v1; }; // 람다 표현식, 갈무리 목록에 지역 변수 v1에 대한 참조자

	v1 = 0;
	auto j = f2(); // j = 0, v1에 대한 참조를 하고 있으므로 값을 저장한 것이 아님.
	cout << j << endl;
}

void fcn3()
{
	size_t v1 = 42; // 지역 변수
	auto f = [v1]()mutable {return ++v1; }; // 람다 표현식, 갈무리 목록에 지역 변수 v1에 대한 참조자, mutable 키워드 사용 -> v1의 값을 전위 증가
	v1 = 0;
	auto j = f(); // j = 43, 기본적으로 람다는 값으로 복사한 변수의 값을 변경할 수 없음. mutable 키워드를 사용하면 변수 값의 변경이 가능.
	cout << j << endl;
}

void fcn4()
{
	size_t v1 = 42; // 지역 변수
	auto f2 = [&v1] {return ++v1; }; // 람다 표현식, 갈무리 목록에 지역 변수 v1에 대한 참조자
	v1 = 0;
	auto j = f2(); // j = 1, 지역 변수 v1에 대한 참조자이므로 값의 변경이 가능. 
	cout << j << endl;
}

void fcn5()
{
	size_t v1 = 42; // 지역 변수
	size_t *const p = &v1; // 지역 변수 v1에 대한 const 포인터

	auto f = [p]() {return ++(*p); }; // 람다 표현식, 갈무리 목록에는 지역 변수 v1에 대한 포인터를 지정, 역참조를 통해 값 변경 가능 
	auto j = f(); // v1 = 43, j = 43
	cout << v1 << " " << j << endl;
	v1 = 0;
	j = f(); // v1 = 1, j = 1 
	cout << v1 << " " << j << endl;
}

int main(int argc, const char *argv[])
{
	fcn1();
	fcn2();
	fcn3();
	fcn4();
	fcn5();

	return 0;
}