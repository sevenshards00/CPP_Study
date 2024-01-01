/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: cctype.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(9) - string 내 문자 다루기, C++11 표준 범위 for문 사용
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <cctype>
using std::isupper;
using std::toupper;
using std::islower;
using std::tolower;
using std::isalpha;
using std::isspace;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	string s("Hello World!!!");
	// decltype을 사용하여 데이터 형을 정한다.
	// decltype은 표현식(expression)을 통해 형을 결정한다.
	// 그래서 punct_cnt는 s.size()가 반환하는 형과 동일한 형을 지니게 된다.
	decltype(s.size()) punct_cnt = 0;

	// 범위 for문을 사용하는 부분 (C++11 표준)
	// 문자열 s에 있는 구두점의 갯수를 센다.
	// auto를 사용하여 c의 데이터 형을 정하는데, C에서 문자열을 char형 배열에 저장했던것을 생각하면 된다.
	// 그렇기 때문에 c의 데이터 형은 char가 된다.
	// 문자열의 문자를 하나씩 반복하여 접근한다.
	for (auto c : s)         
		if (ispunct(c))      // 만약 구두점이라면
			punct_cnt++;     // 카운트를 증가시킨다.

	cout << punct_cnt << " punctuation characters in " << s << endl; // 구두점의 갯수 출력

	// 대문자로 변경하는 경우
	string orig = s; // s의 원본을 놔두기 위해 따로 orig에 복사
	for (auto& c : s)   // string 내에 있는 문자열의 문자를 변경하기 위해서 참조자로 정의한다.
		// 참조자로 하지 않을 경우 문자열 내의 문자를 변경할 수 없음.
		// c는 참조자이므로 문자열 s 내에 있는 문자 char를 참조하게 된다.
		c = toupper(c);
	cout << s << endl;

	// 첫번째 문자열 부분만 대문자로 바꾸는 경우
	s = orig;  // 이전에 따로 원본을 놔뒀던 string 객체인 orig를 다시 s에 복사한다.
	decltype(s.size()) index = 0; // 배열처럼 맨 첫 번째 문자를 가리키기 위한 인덱스

	// 문자열의 끝까지 도달하거나 공백 문자를 만날 경우 반복문을 종료
	// 공백 문자를 만날 경우에 반복문이 종료되므로 앞의 Hello 부분만 대문자로 바꾼다.
	while (index != s.size() && !isspace(s[index])) {

		// 배열과 같이 접근하는 것도 가능하다. ([] 연산자)
		s[index] = toupper(s[index]);

		// 인덱스를 증가시켜 다음 문자로 이동.
		index++;
	}
	cout << s << endl;

	return 0;
}
