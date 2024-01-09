/*
* C++ Primer - Generic Algorithm (일반화 알고리즘)
* 파일명: use_istream_iter.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-09
* 이전 버전 작성 일자:
* 버전 내용: istream, ostream 반복자 사용 예제
* 이전 버전 내용:
*/

#include <algorithm>
using std::copy;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	vector<int> vec;
	istream_iterator<int> in_iter(cin); // 표준 입력에서 정수를 입력받는 istream 반복자
	istream_iterator<int> eof; // istream 반복자의 끝

	while (in_iter != eof) // eof가 입력될 때까지 입력을 받는다.
		// 후위 증가 연산을 사용한다
		// 전위 증가를 할 경우 최초에 입력받은 값은 입력되지 않으므로
		// vector의 요소로 추가된 이후에 그 다음 스트림을 읽는 것.
		vec.push_back(*in_iter++);

	// ostream 반복자
	ostream_iterator<int> out_iter(cout, " "); // 두 번째 인자를 취할 경우 타입이 int인 값에 두 번째 인자를 붙여서 출력 스트림에 기록한다.
	copy(vec.begin(), vec.end(), out_iter); // vector의 요소 값을 out_iter에 복사(copy) -> 출력
	cout << endl;

	// ostream 반복자를 이용한 또 다른 출력 방법
	for (auto e : vec)
		*out_iter++ = e; // 반복자 연산을 이용하여 출력 가능
	cout << endl;

	return 0;
}