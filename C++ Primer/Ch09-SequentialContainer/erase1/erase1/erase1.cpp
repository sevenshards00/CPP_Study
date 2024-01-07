/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: erase1.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: 컨테이너의 다양한 erase 사용법 예제
* 이전 버전 내용:
*/

#include <algorithm>
using std::find;

#include <string>
using std::string;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	list<string> slist;
	string s;
	while (cin >> s)
		slist.push_back(s);

	// find는 일반화 알고리즘(10장)에서 배운다.
	// 일단 list 내에서 "Quasimodo"라는 문자열을 찾는다는 것으로 이해하자.
	auto iter = find(slist.begin(), slist.end(), "Quasimodo");
	if (iter != slist.end()) // 못찾았을 경우에는 반복자가 컨테이너의 끝까지 가서도 못찾은 것이다.
		slist.erase(iter); // 찾았다면 삭제

	auto orig = slist;
	slist.clear(); // 컨테이너에서 요소를 모두 삭제하는 방법 1
	cout << "after clear, size is: " << slist.size() << endl;

	slist = orig;
	slist.erase(slist.begin(), slist.end()); // 컨테이너에서 요소를 모두 삭제하는 방법 2
	cout << "after erase begin to end, size is: " << slist.size() << endl;

	slist = orig;
	// 컨테이너에서 요소를 모두 삭제하는 방법 3
	auto elem1 = slist.begin(), elem2 = slist.end();
	elem1 = slist.erase(elem1, elem2);
	cout << "after erase emem1 to elem2 size is: " << slist.size() << endl;

	// 마지막으로 요소가 모두 삭제가 잘 되었는지 확인
	// begin == end 여야 컨테이너가 비었다는 것.
	if (elem1 != elem2)
		cout << "Somethings wrong" << endl;
	else
		cout << "Well done, they're equal" << endl;
}