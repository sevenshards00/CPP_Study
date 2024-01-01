/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: hexify.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(11) - string class를 인덱스로 접근([])하는 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

int main()
{
	const string hexdigits = "0123456789ABCDEF";  // 16진수의 범위 (0~F)

	cout << "Enter a series of numbers between 0 and 15"
		<< " separated by spaces.  Hit ENTER when finished: "
		<< endl;
	string result;        // 16진수 값으로 바꿀 결과를 저장할 string 클래스

	string::size_type n;  // 입력받은 값을 16진수로 바꿔 저장할 변수
	while (cin >> n) // EOF를 받기 전까지 입력을 받는다.
		if (n < hexdigits.size())    // 0~F 범위의 값만 받기 위한 조건문
			result += hexdigits[n];  // 입력 받은 값을 인덱스로 사용하여 hexdigits의 문자를 result로 더한다.

	cout << "Your hex number is: " << result << endl;

	return 0;
}