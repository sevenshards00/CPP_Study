/*
* C++ Primer - Copy Control (복사 제어)
* 파일명: useStrVec.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-15
* 이전 버전 작성 일자:
* 버전 내용: 복사 제어 예제 - Vector<string> 흉내내기 - StrVec을 사용하는 main 프로그램
* 이전 버전 내용:
*/

#include "StrVec.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;
using std::istream;

#include <fstream>
using std::ifstream;

#ifndef INIT_LIST
#include <iterator>
using std::begin;
using std::end;
#endif;

void print(const StrVec &svec)
{
	for (auto it : svec)
		cout << it << " ";
	cout << endl;
}

StrVec getVec(istream &is)
{
	StrVec svec;
	string s;
	while (is >> s)
		svec.push_back(s);
	return svec;
}

int main(int argc, const char *argv[])
{
#ifdef INIT_LIST
	StrVec sv = { "one", "two", "three" };
#else
	string temp[] = { "one", "two", "three" };
	StrVec sv(begin(temp), end(temp));
#endif
	/*
	* 연산자 오버로딩까지 다루고 난 이후에 확인할 부분
	* 첨자 연산자([]) 오버로딩을 하면 가능
	if (!sv[0].empty())
		sv[0] = "None"; // assign a new value to the first string 
	*/

	// 파일을 읽어서 StrVec에 단어를 추가하고 출력됨을 확인
	ifstream in("data/storyDataFile");
	StrVec svec = getVec(in);
	print(svec);
	in.close();

	// 복사 초기화가 이뤄지는지 확인
	cout << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	// 대입 연산을 확인
	cout << "assign" << endl;
	StrVec svec3;
	svec3 = svec2;
	print(svec3);

	StrVec v1, v2;
	v1 = v2;                   // v2 는 lvalue -> 복사 대입

	in.open("data/storyDataFile");
	v2 = getVec(in);          // getVec(in)은 rvalue -> 이동 대입
	in.close();

	StrVec vec;  // 비어있는 StrVec
	string s = "some string or another";
	vec.push_back(s);      // push_back(const string&)

	return 0;
}