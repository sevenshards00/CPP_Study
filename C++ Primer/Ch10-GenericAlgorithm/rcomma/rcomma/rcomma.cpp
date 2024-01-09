/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: rcomma.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 역방향 반복자 - base() 사용 예제 
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <algorithm>
using std::find;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	string line;
	getline(cin, line);

	// string의 앞에서부터 최초로 ','가 나타난 위치의 반복자를 반환
	auto comma = find(line.cbegin(), line.cend(), ',');
	cout << string(line.cbegin(), comma) << endl;

	// string의 뒤에서부터 최초로 ','가 나타난 위치의 반복자를 반환
	auto rcomma = find(line.crbegin(), line.crend(), ',');
	// 그런데 이렇게 출력하면 문자열도 역방향 순으로 나온다.
	cout << string(line.crbegin(), rcomma) << endl;
	// 여기서는 rcomma를 기준으로 다시 순방향으로 출력해야 함
	// 그래서 base() 멤버 함수를 호출하여 순방향 반복자를 얻어 출력한다.
	cout << string(rcomma.base(), line.cend()) << endl;

	return 0;
}