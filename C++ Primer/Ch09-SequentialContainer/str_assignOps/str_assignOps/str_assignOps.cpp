/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: str_assignOps.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: string 컨테이너의 문자열 삽입 삭제 및 교체 연산 예제
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	string s = "some string", s2 = "some other string";
	// 아래의 예시는 모두 s의 앞에 s2를 삽입하는 예제
	// insert의 다양한 사용 방식을 이해하기 위해 제공
	// Case1: 반복자를 이용
	s.insert(s.begin(), s2.begin(), s2.end()); // s의 문자열 시작점 앞으로 s2의 처음부터 끝까지 삽입
	cout << "insert iterators version:        " << s << endl;

	// Case2: 위치를 이용.
	s = "some string";
	s.insert(0, s2); // s의 문자열 시작점 앞으로 s2의 끝까지 삽입
	cout << "insert string at given position: " << s << endl;

	// Case3: 위치와 크기를 이용
	s = "some string";
	s.insert(0, s2, 0, s2.size()); // s의 문자열 시작점 앞으로 s2를 삽입하는데 범위를 지정. 범위는 처음부터 s2의 크기만큼 삽입.
	cout << "insert positional version:       " << s << endl;


	s = "";  // string을 빈 문자열로 만듬
	vector<char> c_vec(1, 'a');
	// vector를 이용한 문자열 추가
	s.insert(s.begin(), c_vec.begin(), c_vec.end());
	s.insert(s.size(), 5, '!'); // 5개의 문자를 추가. s.size() 위치이므로 s의 끝을 의미
	cout << s << endl;

	s.erase(s.size() - 5, 5);   // 문자열에서 5개의 문자를 삭제.
	cout << s << endl;

	s = "";  // 다시 빈 문자열로
	const char* cp = "Stately, plump Buck"; // C형식 문자열
	s.assign(cp, 7); // assign을 사용하여 문자열을 복사. 7개의 문자만 가지고 온다. s == "Stately"
	cout << s << endl;
	s.insert(s.size(), cp + 7); //s의 끝에 C형식 문자열의 cp + 7 위치부터 끝까지 삽입 s == "Stately, plump Buck"
	cout << s << endl;

	s = "C++ Primer";  // 문자열을 "C++ Primer"로 변경
	s2 = s;            // s2에 복사
	s.insert(s.size(), " 4th Ed."); // s의 끝에 문자열을 삽입. s == "C++ Primer 4th Ed."
	s2.append(" 4th Ed."); // 위와 동일. append는 자동으로 끝에서부터 삽입 
	cout << s << " " << s2 << endl;

	// "4th"를 "5th"로 바꾸는 두 가지 방법
	// 1. insert와 erase를 사용 (번거로운 방법, 지우고 삽입하므로)
	s.erase(11, 3);                 // 해당 부분만큼 3글자만 지우고
	s.insert(11, "5th");            // 그 자리에 삽입한다.

	// 2. replace 사용
	// 위와 동일하지만 하나의 함수로 해결 가능.
	// 11번째 위치부터 3개의 문자를 지우고 5th를 삽입하게 된다.
	s2.replace(11, 3, "5th");

	cout << s << " " << s2 << endl;

	// "5th"를 "Fifth"로 바꾸는 두 가지 방법
	// 1. replace를 사용 (바꿔야 할 위치(인덱스)를 알고 있다면)
	s.replace(11, 3, "Fifth");

	// 2. find를 사용해서 해당 문자열이 나타나는 처음 위치를 찾고 replace를 사용
	// 위치(인덱스)를 모르는 상황에서는 이렇게 인덱스를 찾아서 교체할 수 있다.
	auto pos = s2.find("5th");
	if (pos != string::npos)
		s2.replace(pos, 3, "Fifth");
	else
		cout << "something's wrong, s2 is: " << s2 << endl;
	cout << s << " " << s2 << endl;

	return 0;
}