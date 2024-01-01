/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: add_using.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: namespace using 선언 사용 예시
* 이전 버전 내용:
*/

#include <iostream>

// 표준 라이브러리에 있는 이름을 사용하기 위해 using 선언
// 매번 std::cin, std::cout, std::endl이라고 쓸 필요가 없어짐
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	cout << "Enter two numbers:" << endl;

	int v1, v2;
	cin >> v1 >> v2;

	cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;

	return 0;
}