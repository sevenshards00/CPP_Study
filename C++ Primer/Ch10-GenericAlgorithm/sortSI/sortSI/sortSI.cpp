/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: sortSI.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: sort 사용 예제 - 인자로 함수를 전달하는 경우
* 이전 버전 내용:
*/

#include <algorithm>
using std::sort;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Sales_item.h"

int main(int argc, const char *argv[])
{
	Sales_item trans;
	vector<Sales_item> file;

	while (cin >> trans) // EOF가 입력될 때까지 입력 받아서
		file.push_back(trans); // vector에 저장

	for (auto i : file) // vector의 내용을 저장
		cout << i << endl;
	cout << "\n\n";

	sort(file.begin(), file.end(), compareIsbn); // sort에 인자로 함수를 전달, 해당 함수를 기준으로 정렬.
	for (auto i : file) // 결과 출력
		cout << i << endl;

	return 0;
}