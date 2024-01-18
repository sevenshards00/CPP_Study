/*
* C++ Primer - Overloaded Operations & Conversions (다중 정의 연산과 변환)
* 파일명: readStr.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-18
* 이전 버전 작성 일자:
* 버전 내용: 문자열을 읽고 화면에 출력하는 함수 객체 사용 예제
* 이전 버전 내용:
*/

#include <algorithm>
using std::for_each;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::istream;
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#define DELETED_FCNS

// 문자열을 출력하는 함수 객체(Functor)
class PrintString
{
public:
	// 생성자
	PrintString(ostream &o = cout, char c = ' ')
		:os(o), sep(c) {}
	// 함수 호출 연산자 오버로딩
	void operator()(const string &s) const
	{
		os << s << sep;
	}

private:
	ostream &os;
	char sep;
};

// 문자열을 하나씩 읽어들이는 함수 객체(Functor)
class ReadLine
{
public:
#ifdef DELETED_FCNS
	ReadLine() = delete; // 기본 생성자를 삭제 -> 명시적으로 기본 생성자를 쓰지 않겠다는 것
#endif
	// 생성자
	ReadLine(istream &i) : is(i) { }
	// 함수 호출 연산자 오버로딩
	// bool operator()(string &s) const { return getline(is, s); }
	// 예제를 그대로 돌리면 안된다. bool로 변환이 안된다.
	istream &operator()(string &s) const { return getline(is, s); }
private:
	istream &is;
};

int main()
{
	vector<string> vs;
	ReadLine rl(cin);    // object that read lines from cin
	string s;
	while (rl(s))        // store what rl reads into s
		vs.push_back(s);

	cout << "read : " << vs.size() << " elements" << endl;
	PrintString printer;   // uses the defaults; prints to cout 
	printer(s);            // prints s followed by a space on cout

	PrintString errors(cerr, '\n');
	errors(s);             // prints s followed by a newline on cerr

	cerr << "for_each printing to cerr" << endl;
	for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));

	return 0;
}