/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: char_repl.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: string 클래스 사용 예제(10) - 반복문(for, 범위 for)과 반복자 사용 예시
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	string str("some string"), orig = str;
	if (!str.empty()) // string 클래스의 멤버함수 empty()를 통해 문자열이 없는지 확인
		cout << str[0] << endl; // 문자열의 첫 번째 문자를 출력.

	if (!str.empty()) // string 클래스의 멤버함수 empty()를 통해 문자열이 없는지 확인
		// 맨 첫 번째 문자를 대문자로 바꾼다.
		str[0] = toupper(str[0]);
	cout << str << endl;

	str = orig;

	// 배열과 같이 []를 사용하지 않고 반복자(Iterator)를 사용한 예시
	if (str.begin() != str.end()) { // begin과 end가 같다면 문자열이 비어있음. empty()와 동일.
		auto it = str.begin();  // auto를 사용하여 데이터형을 정한다. 여기서 it는 반복자가 된다.
		*it = toupper(*it);     // 반복자를 통한 값의 접근은 포인터와 매우 유사하다.
	}
	cout << str << endl;

	str = orig;

	// 첫 단어를 대문자로 바꾸는 4가지 예시
	// 1. for문 + 문자열 배열에 접근하는 방식 ([] 사용)
	for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); index++)
		str[index] = toupper(str[index]); // 현재 문자를 대문자로 변경
	
	cout << str << endl;

	str = orig;

	// 2. for문 + 반복자 사용
	// 반복자를 사용했다는 것이 포인트.
	for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
		*it = toupper(*it); // 현재 문자를 대문자로 변경
	
	cout << str << endl;

	str = orig;

	// 3. while문 + 문자열 배열에 접근하는 방식 ([] 사용)
	decltype(str.size()) index = 0; // 문자열의 첫 번째 인덱스
	
	while (index != str.size() && !isspace(str[index]))
	{
		str[index] = toupper(str[index]);  // 현재 문자를 대문자로 바꾼다.
		index++;        // 다음 문자를 가리키기 위해 인덱스를 증가
	}
	cout << str << endl;

	// 4. while문 + 반복자 사용
	auto beg = str.begin();
	
	while (beg != str.end() && !isspace(*beg))
	{
		*beg = toupper(*beg);
		beg++;
	}
	cout << str << endl;

	str = orig;

	// 범위 for문을 이용한 모든 문자를 처리하는 과정
	// 원래 문자열을 범위 for문을 이용해 출력한다.
	for (auto c : str)      // 문자열 내에 있는 모든 문자(char)형에 대해 반복을 수행
		cout << c << endl;  // 현재 문자를 하나씩 출력하고 개행

	// 문자열을 하나씩 변경
	for (auto& c : str)  // 참조자를 통해서 접근해야 하는 것이 포인트 
		c = '*';         // 문자열에 있는 문자를 '*'로 변경한다.
	cout << str << endl;

	str = orig;

	// 범위 for문은 기존의 for를 사용하면 다음과 같다.
	for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
		cout << str[ix] << endl;

	for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
		str[ix] = '*';
	
	cout << str << endl;

	str = orig;

	// 범위 for문을 기존의 for 반복문과 반복자를 사용한 예시
	for (auto beg = str.begin(); beg != str.end(); ++beg)
		cout << *beg << endl;

	for (auto beg = str.begin(); beg != str.end(); ++beg)
		*beg = '*';
	
	cout << str << endl;
	return 0;
}