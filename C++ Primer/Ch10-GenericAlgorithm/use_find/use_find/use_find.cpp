/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: use_find.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: 순차 컨테이너 타입에 find 사용 예제
* 이전 버전 내용:
*/

#include <algorithm>
using std::find;

#include <iterator>
using std::begin;
using std::end;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#define LIST_INIT

int main(int argc, const char* argv[])
{
	// 기본 배열에 대한 find 연산
	int ia[] = { 27, 210, 12, 47, 109, 83 };
	int val = 83;

	// 포인터 역시 반복자처럼 연산하므로 다음과 같이 find를 사용 가능
	int* result = find(begin(ia), end(ia), val);
	// result == end(ia)라는 것은 배열의 끝까지 가서도 일치하는 데이터를 찾지 못했다는 것
	cout << "The value " << val << (result == end(ia) ? " is not present" : " is present") << endl;

	// ia[1]부터 ia[3]까지의 범위 내에서 값을 찾는 경우
	// 단 ia[4]는 포함범위가 아님을 주의
	result = find(ia + 1, ia + 4, val);

	// vector<int>에 대한 find 연산
#ifdef LIST_INIT // C++11 표준 이후 목록 초기화 사용 시
	vector<int> vec = { 27, 210, 12, 47, 109, 83 };
#else // 목록 초기화 사용하지 않을 경우
	int temp[] = { 27, 210, 12, 47, 109, 83 };
	vector<int> vec(begin(temp), end(temp));
#endif
	val = 42; // 찾을 값

	// 반복자를 이용하여 값을 찾는다.
	auto result2 = find(vec.cbegin(), vec.cend(), val);
	// 값을 찾지 못했다면 위의 배열과 마찬가지로 end까지 도달한 것.
	cout << "The value " << val << (result2 == vec.cend() ? " is not present" : "is present") << endl;

	// list<string>에 대한 find 연산
#ifdef LIST_INIT
	list<string> lst = { "val1", "val2", "val3" };
#else
	string temp2[] = { "val1", "val2", "val3" };
	list<string> lst(begin(temp2), end(temp2));
#endif

	string sval = "a value";  // 찾을 값
	// 목록의 문자열 요소를 탐색
	auto result3 = find(lst.cbegin(), lst.cend(), sval);
	// 값을 찾지 못했다면 위와 마찬가지로 end까지 도달한 것.
	cout << "The value " << sval << (result3 == lst.cend() ? " is not present" : " is present") << endl;

	return 0;
}