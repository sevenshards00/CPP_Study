/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: useConvs.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: string 컨테이너 - 수치 변환 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;
using std::to_string;
using std::stod;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int i = 42;
	string s = to_string(i); // int형 정수를 문자열로 변환
	double d = stod(s);   // 문자열 s를 double형으로 변환
	cout << "i = " << i << "\ns = " << s << "\nd is: " << d << endl;

	// s2에서 숫자로 시작하는 부분의 문자열만 추출하여 double형으로 변환
	string s2 = "pi = 3.14";
	d = stod(s2.substr(s2.find_first_of("+-.0123456789")));

	cout << "d = " << d << "\ns = " << s << "\ns2 is: " << s2 << endl;

	return 0;
}