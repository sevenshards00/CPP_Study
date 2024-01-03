/*
* C++ Primer - Expression (표현식)
* 파일명: cond.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 조건 연산자 (3항 연산자) 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

vector<unsigned> grades;

int main(int argc, const char* argv[])
{
	unsigned i;

	while (cin >> i)
		grades.push_back(i);

	for (auto grade : grades)
	{
		// 이처럼 단순하게 사용할 수도 있고
		string finalgrade = (grade < 60) ? "fail" : "pass";

		// 중첩해서 사용하는 것도 가능하다
		finalgrade = (grade > 90) ? "high pass" : ((grade < 60) ? "fail" : "pass");

		cout << grade << " " + finalgrade << endl;
	}

	return 0;
}