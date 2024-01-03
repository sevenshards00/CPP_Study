/*
* C++ Primer - Statement (문장)
* 파일명: ifgrades.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 간단한 if문 예제
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

#define LIST_INIT

#ifndef LIST_INIT
#include <iterator>
using std::begin;
using std::end;
#endif

#ifdef LIST_INIT
const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
#else
const string scores[] = { "F", "D", "C", "B", "A", "A++" };
#endif

vector<unsigned> grades;

// 조건문 Case1: 잘 짠 경우
string goodVers(string lettergrade, unsigned grade)
{
	if (grade % 10 > 7)
		lettergrade += '+';
	else if (grade % 10 < 3)
		lettergrade += '-';
	return lettergrade;
}

// 조건문 Case2: 잘못 짠 경우
string badVers(string lettergrade, unsigned grade)
{
	if (grade % 10 >= 3)
		if (grade % 10 > 7)
			lettergrade += '+';
		else
			lettergrade += '-';
	return lettergrade;
}

// 조건문 Case3: 맞게 짠 경우, 하지만 Case1이 가장 잘 짠 경우.
string rightVers(string lettergrade, unsigned grade)
{
	if (grade % 10 >= 3)
	{
		if (grade % 10 > 7)
			lettergrade += '+';
	}
	else
		lettergrade += '-';

	return lettergrade;
}

int main(int argc, const char* argv[])
{
	unsigned grade;
	while (cin >> grade)
		grades.push_back(grade);

	for (auto it : grades)
	{
		cout << it << " ";
		string lettergrade;

		if (it < 60)
			lettergrade = scores[0];
		else
		{
			lettergrade = scores[(it - 50) / 10];
			if (it != 100)
				if (it % 10 > 7)
					lettergrade += '+';
				else if (it % 10 < 3)
					lettergrade += '-';
		}
		cout << lettergrade << endl;

		if (it > 59 && it != 100)
		{
			cout << "alternative versions: " << it << " ";
			lettergrade = scores[(it - 50) / 10];
			cout << goodVers(lettergrade, it) << " ";
			cout << badVers(lettergrade, it) << " ";
			cout << rightVers(lettergrade, it) << " ";
			cout << endl;
		}
	}
	return 0;
}