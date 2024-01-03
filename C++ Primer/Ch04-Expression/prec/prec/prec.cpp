/*
* C++ Primer - Expression (표현식)
* 파일명: prec.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 연산자 우선순위(Operator Precedence) 및 결합법칙(또는 연관성, operator assciativity) 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	cout << 6 + 3 * 4 / 2 + 2 << endl;

	// 위의 표현식을 괄호로 표현하면 우선순위와 결합법칙이 동일
	cout << ((6 + ((3 * 4) / 2)) + 2) << endl;

	// 과정을 하나하나 일일이 풀어가는 과정
	int temp = 3 * 4;
	int temp2 = temp / 2;
	int temp3 = temp2 + 6;
	int result = temp3 + 2;

	cout << result << endl;

	// 괄호를 이용해서 우선순위와 결합법칙을 다시 정의한 경우
	cout << (6 + 3) * (4 / 2 + 2) << endl;
	cout << ((6 + 3) * 4) / 2 + 2 << endl;
	cout << 6 + 3 * 4 / (2 + 2) << endl;

	return 0;
}