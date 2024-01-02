/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: arrayScores.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-02
* 이전 버전 작성 일자:
* 버전 내용: 배열(Array) 사용 예제(1) - vecScores 배열 버전
* 이전 버전 내용:
*/

#include <cstddef>
using std::size_t;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	// 입력한 점수들을 저장할 vector 객체
	vector<unsigned> grades;

	// 10 단위로 나눠서 그룹화할 배열
	// 0--9, 10--19, . ..  90--99, 100
	unsigned scores[11] = { 0, }; // 11개의 인덱스를 가지는 배열, 전부 0으로 초기화
	unsigned grade; // 입력받을 점수를 저장할 변수
	while (cin >> grade) // 표준 입력을 통해서 점수를 입력. EOF를 입력받기 전까지 받는다.
	{
		if (grade <= 100)
			scores[grade / 10]++; // 점수를 10으로 나눈 값을 인덱스로 사용하여 배열 요소를 증가 시킴

		grades.push_back(grade); // 입력한 점수를 vector의 뒤에서부터 채워넣는다.
	}

	cout << "grades.size = " << grades.size() << endl; // vector의 전체 요소의 개수 반환 

	for (auto g : grades) // 범위 for문을 이용하여 입력받은 점수들을 출력.
		cout << g << " ";

	cout << endl;

	for (auto i : scores) // 범위 for문을 이용하여 배열에 저장된 요소들을 출력
		cout << i << " ";

	cout << endl;
	return 0;
}