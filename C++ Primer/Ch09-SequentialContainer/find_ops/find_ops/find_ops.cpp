/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: find_ops.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: string 컨테이너의 검색 연산 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	string numbers("0123456789"), name("r2d2");

	auto pos = name.find_first_of(numbers);
	if (pos != string::npos)
		cout << "found number at index: " << pos << " elements is " << name[pos] << endl;
	else
		cout << "no number in: " << name << endl;

	pos = 0;

	while ((pos = name.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "found number at index: " << pos << " elements is " << name[pos] << endl;

		++pos;
	}

	string river("Mississippi");

	auto first_pos = river.find("is");
	auto last_pos = river.rfind("is");
	cout << "find returned: " << first_pos << " rfind returned: " << last_pos << endl;

	string dept("03714p3");
	pos = dept.find_first_not_of(numbers);
	cout << "first_no returned: " << pos << endl;

	return 0;
}