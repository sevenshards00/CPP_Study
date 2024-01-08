/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: inserters.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-08
* 이전 버전 작성 일자:
* 버전 내용: list 기반 삽입 반복자(Insert iterator), copy 사용 예제
* 이전 버전 내용:
*/

#include <algorithm>
using std::copy;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::inserter;
using std::front_inserter;

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

#ifndef LIST_INIT // 목록 초기화를 사용하지 않는 경우 (C++11 미만)
using std::begin;
using std::end;
#endif

void print(const string &label, const list<int> &lst)
{
	cout << label << endl;
	for (auto iter : lst)
		cout << iter << " ";
	cout << endl;
}

int main(int argc, const char *argv[])
{
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	list<int> lst = { 1, 2, 3, 4 };
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	int temp[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> lst(temp, temp + 4);
#endif
	print("lst", lst);

	// 비어있는 list lst2, lst3
	list<int> lst2;
	list<int> lst3;

	// copy를 통해 lst의 처음부터 끝까지 lst2에 복사, 앞에서부터 요소를 복사하므로 1-2-3-4순으로 리스트에 입력.
	// front_inserter는 삽입할 때마다 첫 요소 앞에 요소를 삽입. (push_front)
	// 그래서 lst2의 begin()이 계속 바뀌게 된다.
	// 그래서 실제 리스트에는 4-3-2-1 순으로 저장된다.
	copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	// copy를 통해 lst의 처음부터 끝까지 lst3에 복사, lst3의 처음부터 채워넣는다.
	// inserter는 지정한 반복자로 나타내는 요소 앞에 삽입. (insert)
	// 그래서 1-2-3-4 순으로 저장된다.
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));

	print("lst2", lst2);
	print("lst3", lst3);

#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
	vector<int> v = { 1, 2, 3, 4, 5 };
	list<int> new_lst = { 6, 7, 8, 9 };
#else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
	vector<int> v(temp, temp + 5);
	list<int> new_lst(temp + 5, end(temp));
#endif
	auto it = new_lst.begin(); // new_lst의 맨 처음 위치를 가리키는 반복자
	copy(v.begin(), v.end(), inserter(new_lst, it)); // vector의 처음부터 끝까지 inserter의 시작 앞에 복사하게 된다. 
	print("new_lst", new_lst);
	return 0;
}