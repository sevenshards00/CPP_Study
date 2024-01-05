/*
* C++ Primer - Function (함수)
* 파일명: usefcnptr.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-04
* 이전 버전 작성 일자:
* 버전 내용: 함수 포인터 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// vector 내에서 가장 작은 요소를 반환하는 함수를 선언
int min_element(vector<int>::iterator, vector<int>::iterator);

// 함수 포인터 pf, min_element 함수를 가리킨다.
int(*pf)(vector<int>::iterator, vector<int>::iterator) = min_element;

int main(int argc, const char* argv[])
{
	vector<int> ivec = { 0, 2, 5, 6, 7, 8, 500, 1000, -1000, -750 };

	cout << "Direct call: "
		<< min_element(ivec.begin(), ivec.end()) << endl;
	cout << "Indirect call: "
		<< pf(ivec.begin(), ivec.end()) << endl;
	cout << "equivalnet indirect call: "
		<< (*pf)(ivec.begin(), ivec.end()) << endl;

	return 0;
}

int min_element(vector<int>::iterator beg, vector<int>::iterator end)
{
	int minVal = 0;
	while (beg != end)
	{
		if (minVal > *beg)
			minVal = *beg;
		++beg;
	}
		
	return minVal;
}