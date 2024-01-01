/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: vecStrings2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: vector 템플릿 사용 예제(4) - vector<string> 객체를 통한 반복자 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main(int argc, const char* argv[])
{
	vector<string> text;     // 입력 받은 문자열을 저장하기 위한 vector

	string s;
	
	while (getline(cin, s))  // 표준입력을 통해 문자열을 한 줄 씩 읽어들인다.
		text.push_back(s);   // vector에 입력한 문자열을 순서대로 저장(뒤에서부터 저장)
	
	cout << "text.size: " << text.size() << endl; // 전체 입력한 문자열의 갯수 출력

	// 비어있는 줄 이전까지의 입력받은 문자열을 출력
	for (auto it = text.cbegin(); it != text.cend() && !(*it).empty(); it++)
		cout << *it << endl;

	// 구조체와 같이 -> 연산자를 이용한 경우 (it->empty())
	for (auto it = text.cbegin(); it != text.cend() && !it->empty(); it++)
		cout << *it << endl;

	return 0;
}