/*
* C++ Primer - Function (함수)
* 파일명: refparms.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-04
* 이전 버전 작성 일자:
* 버전 내용: 함수의 매개변수(Parameter)로 참조자를 전달하는 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

#define LIST_INIT

// 특정 문자를 찾는 함수
// 문자열을 첫 번째 인자로 받고, 두 번째 인자는 대상 문자를 받는다.
// 그리고 세 번째 인자로 참조자를 받는데, 이를 통해서 추가적인 정보로 해당 문자가 몇 번 나왔는지 알 수 있다.
string::size_type find_char(const string& s, char c, string::size_type& occurs)
{
	auto ret = s.size(); // 첫 번째로 문자열 내에서 문자가 발생하는 위치를 기록하기 위한 변수, string의 size()이므로 문자열의 길이로 초기화.
	occurs = 0; // 문자열 내에서 발견된 문자 갯수를 카운트하기 위한 변수

	for (decltype(ret) i = 0; i != s.size(); ++i) // 문자열의 끝까지 반복문을 수행
	{
		if (s[i] == c) // 해당하는 문자를 찾았다면
		{
			if (ret == s.size()) // 만약 ret 초기화된 상태 그대로라면
				ret = i; // 찾는 문자 c가 처음으로 발생한 위치를 기록한다.
			
			++occurs; // 그리고 문자가 발생한 카운트 수를 증가.
		}
	}
	return ret;
}

// vector를 사용한 경우
// 첫 번째 인자로는 vector의 맨 처음, 그리고 두 번째 인자로는 vector의 끝을 받는다.
// 세 번째 인자는 찾고자 하는 대상 값을 인자로, 네 번째 인자로는 해당 숫자가 발생한 빈도를 기록하기 위한 변수를 참조자로 받는다.
vector<int>::const_iterator find_val(
	vector<int>::const_iterator beg, vector<int>::const_iterator end, int value, vector<int>::size_type& occurs)
{
	auto res_iter = end; // 첫 번째로 해당 숫자가 발견된 위치를 기록하기 위한 변수
	occurs = 0; // 발생 빈도를 기록하기 위한 변수

	for (; beg != end; ++beg) // 반복문 수행, 인자로 초기값과 끝이 모두 정해져있으므로 초기값은 생략.
	{
		if (*beg == value) // 만약 찾는 값과 같다면
		{
			if (res_iter == end) // 초기화된 값과 같다고 하면
				res_iter = beg; // 최초로 해당 숫자가 발견된 위치를 복사한다.

			++occurs; // 발생 빈도 카운트 증가.
		}
	}

	return res_iter;
}

int main(int argc, const char* argv[])
{

	string s;
	getline(cin, s);
	size_t cnt = 0;
	auto index = find_char(s, 'o', cnt); // 'o'라는 문자가 발생한 최초 위치와 발생 빈도를 찾기 위해 함수 호출.
	cout << index << " " << cnt << endl; // 참조자를 사용하여 cnt의 값으로 추가적인 정보를 받아오는 것이 가능하다. (포인터 사용과 유사)

	vector<int> ivec;
	int i;

	while (cin >> i) // vector에 값을 입력 받는다.
		ivec.push_back(i);

	// 찾고자 하는 대상값을 대상으로 for문 수행
#ifdef LIST_INIT // 목록 초기화를 사용할 경우
	for (auto i : { 42, 33, 92 })
	{
#else // 목록 초기화를 사용하지 않는 경우
	int arr[] = { 42, 33, 92 }; // 배열을 사용한다.
	for (auto i : arr)
	{
#endif
		auto it = find_val(ivec.begin(), ivec.end(), i, cnt); // find_val 함수를 호출.
		if (it == ivec.end()) // 반환된 값이 vector의 마지막 요소 다음 값이라면 -> 값을 찾지 못한 것.
			cout << i << " is not in the input data" << endl;
		else // 찾았다면 결과를 출력.
			cout << i << " was at position " << it - ivec.begin() << endl;
	}

	return 0;
}