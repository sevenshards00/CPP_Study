/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: bind2.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: bind를 이용한 스트림 활용 예제 (+ 람다 표현식)
* 이전 버전 내용:
*/

#include <algorithm>
using std::for_each;

#include <functional>
using std::bind;
using namespace std::placeholders;
using std::ref;

#include <iterator>
using std::istream_iterator;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

ostream &print(ostream &os, const string &s, char c)
{
	return os << s << c;
}

int main(int argc, const char *argv[])
{
	string s;
	vector<string> words;
	// 표준 입력을 통해서 vector에 string 요소를 추가
	while (cin >> s)
		words.push_back(s);

	// 입력받은 값의 확인을 위해 vector의 각 요소를 출력
	// 표준 출력을 통해서 콘솔 화면에 출력
	// 여기서 bind를 통해 전달되는 인자는 '복사'를 하게 된다.
	// 그런데 입출력 스트림은 복사를 할 수 없다.
	// 그래서 ref 라이브러리를 사용하여 참조자로 접근한다.
	for_each(words.begin(), words.end(), bind(print, ref(cout), _1, ' '));
	cout << endl;
	

	// 람다 표현식을 쓰면 아래와 같이 쓸 수 있다.
	for_each(words.begin(), words.end(), [](const string &s) {cout << s << ' '; });
	cout << endl;
	

	// 파일로 출력하는 부분
	ofstream os1("data/outFile1");
	ofstream os2("data/outFile2");
	for_each(words.begin(), words.end(), bind(print, ref(os1), _1, '\n'));
	os1 << endl;
	
	
	// 람다 표현식을 쓰면 아래와 같이 쓸 수 있다.
	for_each(words.begin(), words.end(), [&os2](const string &s) {os2 << s << '\n'; });
	os2 << endl;
	

	// 파일을 읽어오는 부분
	ifstream is1("data/outFile1");
	ifstream is2("data/outFile1");
	istream_iterator<string> in1(is1);
	istream_iterator<string> in2(is2);
	istream_iterator<string> eof;
	
	for_each(in1, eof, bind(print, ref(cout), _1, '\n'));
	cout << endl;
	
	
	// 람다 표현식을 쓰면 아래와 같이 쓸 수 있다.
	for_each(in2, eof, [](const string &s) {cout << s << '\n'; });
	cout << endl;
	
}