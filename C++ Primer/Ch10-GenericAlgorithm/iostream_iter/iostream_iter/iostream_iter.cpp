/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: iostream_iter.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: 입출력 스트림 반복자 사용 예제 (콘솔, 파일)
* 이전 버전 내용:
*/

#include <algorithm>
using std::copy;
using std::sort;
using std::unique_copy;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	// 표준 입력을 통해 int를 읽어들여 vector를 초기화.
	istream_iterator<int> int_it(cin);
	istream_iterator<int> int_eof;
	vector<int> v(int_it, int_eof);

	sort(v.begin(), v.end()); // vector내 데이터를 정렬한다.
	ostream_iterator<int> out(cout, " "); // 표준 출력 스트림에 " "를 추가하여 출력하는 반복자
	unique_copy(v.begin(), v.end(), out); // vector 내의 요소 중 중복되지 않은 요소만 출력 스트림의 반복자로 복사한다.
	cout << endl;

	// 파일을 통한 출력
	ofstream out_file("data/outFile2");
	ostream_iterator<int> out_iter(out_file, " "); // 파일 스트림을 대상으로 " " 를 추가하여 출력하는 반복자
	copy(v.begin(), v.end(), out_iter); // vector의 내용을 파일로 출력한다.
	out_file << endl;

	return 0;
}