/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: vecScores.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: vector 템플릿 사용 예제(2) - 배열처럼 접근하기 ([] 사용), 반복자 사용
* 이전 버전 내용:
*/

#include <string>
using std::string;

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

	// 10 단위로 나눠서 그룹화할 vector 객체
	// 0--9, 10--19, . ..  90--99, 100
	vector<unsigned> scores(11, 0); // 총 11개 그룹이 생기므로 11개의 요소를 전부 0으로 초기화
	unsigned grade;
	
	while (cin >> grade) // 점수를 입력받는다
	{
		if (grade <= 100)       // 0~100 사이의 유효한 점수만 입력 받는다.
			grades.push_back(grade); // vector의 가장 마지막 요소로 추가
		scores[grade / 10] += 1; // 점수를 10으로 나눈 값을 인덱스로 사용, 카운트를 추가한다.
	}

	cout << "grades.size = " << grades.size() << endl; // 입력받은 전체 성적 갯수
	for (auto it : grades) // 범위 for문을 사용하여 입력한 성적 전체를 출력
		cout << it << " ";
	
	cout << endl;

	cout << "scores.size = " << scores.size() << endl; // 10점대별로 나눈 그룹의 카운트 수 출력
	for (auto it : scores)
		cout << it << " ";
	
	cout << endl;

	// 첨자([]) 대신 반복자를 사용할 경우 다음과 같은 코드로 쓸 수 있다.
	vector<unsigned> alt_scores(11, 0);  // 마찬가지로 11개의 요소를 갖는 vector, 0으로 전체 초기화
	// 각 성적을 입력 받는다.
	// 반복자를 사용하므로 begin, end가 사용.
	for (auto it = grades.begin(); it != grades.end(); it++) {
		unsigned i = *it;
		// 해당하는 그룹의 카운트 수를 증가
		(*(alt_scores.begin() + i / 10))++;
	}

	// 반복자를 이용한 출력.
	cout << "alt_scores.size = " << alt_scores.size() << endl;
	for (auto it = alt_scores.begin(); it != alt_scores.end(); it++)
		cout << *it << " ";
	
	cout << endl;

	return 0;
}