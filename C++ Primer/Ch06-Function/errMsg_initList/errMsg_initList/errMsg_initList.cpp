/*
* C++ Primer - Function (함수)
* 파일명: errmsg_initList.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-05
* 이전 버전 작성 일자:
* 버전 내용: initializer_list를 이용한 가변인자 사용 예제
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#define INITIALIZER_LIST

#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
#include <initializer_list>
using std::initializer_list; // C언어에서 사용하던 가변인자를 설정 가능, 타입은 동일해야 함
#endif;

#include <sstream>
using std::ostringstream;

// ErrCode 클래스
// 다음 챕터에서 더 자세히 다룰 내용
struct ErrCode
{
	ErrCode(int i) : num(i) {}; // 생성자
	string msg() // 멤버 함수
	{
		ostringstream s;
		s << "ErrCode " << num; return s.str();
	}
	int num; // 멤버 변수
};

#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
void error_msg(ErrCode e, initializer_list<string> il) // ErrCode e와 string 타입의 가변 인자를 받는다.
{
	cout << e.msg() << ": ";
	for (const auto& elem : il)
		cout << elem << " ";
	cout << endl;
}
#else // initializer_list를 사용하지 않는 경우
void error_msg(ErrCode e, const string* beg, const string* end) // 함수 오버로딩, ErrCocde를 인자로 받는 경우
{
	cout << e.msg() << ": ";
	while (beg != end)
		cout << *beg++ << " ";
	cout << endl;
}
#endif

#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
void error_msg(initializer_list<string> il) // 함수 오버로딩, 인자를 하나만 받는 경우
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
}
#else // initializer_list를 사용하지 않는 경우
void error_msg(const string* beg, const string* end) // 함수 오버로딩, ErrCode를 인자로 받지 않는 경우
{
	while (beg != end)
		cout << *beg++ << " ";
	cout << endl;
}
#endif

vector<string> functionX() // 반환형이 vector<string>인 functionX
{
	string expected = "description", actual = "some other case";
#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
	if (expected.empty()) // expected가 비었다면
		return {};  // 빈 vector 반환
	else if (expected == actual)
		return { "functionX", "okay" }; // 목록 초기화된 vector를 반환
	else
		return { "functionX", expected, actual }; //
#else // initializer_list를 사용하지 않는 경우
	vector<string> retVals; // 반환하기 위해 사용할 지역변수 vector<string> 객체
	if (expected.empty())
		return retVals;  // 만약 비었다면 빈 벡터를 반환
	else if (expected == actual)
	{
		retVals.push_back("functionX"); // vector의 뒤쪽부터 문자열을 추가 
		retVals.push_back("okay");
		return retVals;                 // 값을 반환한다.
	}
	else
	{
		retVals.push_back("functionX");
		retVals.push_back(expected);
		retVals.push_back(actual);
		return retVals;
	}
#endif
}

int main(int argc, const char* argv[])
{
	string expected = "description", actual = "some other case";
#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
	initializer_list<int> li = { 0,1,2,3 };
#else // initializer_list를 사용하지 않는 경우
	vector<int> li; // vector<int> 객체를 생성해서
	for (int i = 0; i < 4; ++i) // 반복문을 통해 삽입
		li.push_back(i);
#endif

	// expected, actual은 모두 문자열이다. 
	if (expected != actual) // 두 문자열이 같지 않다면
#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
		error_msg({ "functionX", expected, actual }); // 목록을 인자로 전달
#else
	{
		const string arr[] = { "functionX", expected, actual }; // string 객체의 배열을 정의하고
		error_msg(begin(arr), end(arr)); // string 객체의 배열의 시작, 끝 다음 포인터를 인자로 전달한다.
	}
#endif
	else
#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
		error_msg({ "functionX", "okay" }); // 두 문자열이 같을 경우
#else
	{
		const string arr[] = { "functionX", "okay" }; // string 객체의 배열을 정의하고
		error_msg(begin(arr), end(arr)); // string 객체의 배열의 시작, 끝 다음 포인터를 인자로 전달한다.
	} // string 객체의 배열을 인자로 전달한다.
#endif

	// expected, actual은 모두 문자열이다. 
	if (expected != actual) // 두 문자열이 같지 않다면
#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
		error_msg(ErrCode(42), { "functionX", expected, actual });
#else
	{
		const string arr[] = { "functionX", expected, actual }; // string 객체의 배열을 정의하고
		error_msg(ErrCode(42), begin(arr), end(arr)); // ErrCode와 string 객체의 배열의 시작, 끝 다음 포인터를 인자로 전달한다.
	}
#endif
	else // 두 문자열이 같은 경우
#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
		error_msg(ErrCode(0), { "functionX", "okay" });
#else
	{
		const string arr[] = { "functionX", "okay" }; // string 객체의 배열을 정의하고
		error_msg(ErrCode(0), begin(arr), end(arr)); // ErrCode와 string 객체의 배열의 시작, 끝 다음 포인터를 인자로 전달한다.
	}
#endif

	// 목록을 비워서 보낼 수도 있음. 이럴 경우 오버로딩한 두 번째 함수 형태를 호출
#ifdef INITIALIZER_LIST // initializer_list를 사용하는 경우
	error_msg({}); // 빈 줄을 출력하게 된다.
#else
	error_msg(nullptr, nullptr);   // 널 포인터를 인자로 전달.
#endif

	// 함수 호출을 통해 목록 초기화된 값을 받는 경우
	// 반환형은 vector<string>
	auto results = functionX();
	for (auto i : results)
		cout << i << " ";
	cout << endl;

	return 0;
}