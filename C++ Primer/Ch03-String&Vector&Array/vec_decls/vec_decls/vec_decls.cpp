/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: vec_decls.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-01
* 이전 버전 작성 일자:
* 버전 내용: vector 템플릿 사용 예제(1) - vector class의 다양한 초기화 방법
* 이전 버전 내용:
*/

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Sales_item.h"

#define LIST_INIT // 목록 초기화를 사용할 것이라면 주석처리 하지말고, 사용하지 않는다면 주석처리.

#ifndef LIST_INIT // 목록 초기화 방식({ ... })을 사용하지 않을 경우
#include <iterator> // 반복자를 사용
using std::begin; using std::end;
#endif

int main(int argc, const char* argv[])
{
#ifdef LIST_INIT // 목록 초기화 방식({ ... })을 사용할 경우
	// 목록 초기화, 3개의 요소를 포함한다.
	vector<string> articles = { "a", "an", "the" };
#else
	string temp[] = { "a", "an", "the" };
	vector<string> articles(begin(temp), end(temp));
#endif

	// vector 객체 생성
	// vector 최초 생성 시에는 아무런 요소도 없는 비어있는 vector다.
	vector<string> svec; // string 클래스 타입을 요소로 갖는 vector 클래스 객체를 생성
	vector<int> ivec; // int형 요소를 갖는 vecotr 클랫 객체를 생성.
	vector<Sales_item> Sales_vec; // Sales_item형 요소를 갖는 vector 클래스 객체를 생성

	vector<vector<string>> file;  // vector<string>형을 요소로 갖는 vector 클래스 객체를 생성
	vector<vector<int>> vecOfvec; // vector<int>형을 요소로 갖는 vector 클래스 객체를 생성

	// 5개의 vector는 모두 비어있는 vector이므로 size는 0이다.
	cout << svec.size() << " " << ivec.size() << " " << Sales_vec.size() << " " << file.size() << " " << vecOfvec.size() << endl;

	// vector 초기화 과정
	vector<int> ivec2(10);     // 10개의 요소를 가지며, 각 요소는 0으로 초기화
	vector<int> ivec3(10, -1); // 10개의 요소, 각 요소는 -1로 초기화
	vector<string> svec2(10);  // 10개의 string 객체 요소, 모두 비어있는 string 객체.
	vector<string> svec3(10, "hi!"); // 10개의 string 객체 요소, 모두 "hi!"라는 값으로 초기화
	cout << ivec2.size() << " " << ivec3.size() << " " << svec2.size() << " " << svec3.size() << endl;

	// string 클래스로 벡터를 구성하는 경우
	// 정수 10은 문자열이 아니므로 목록 초기화가 불가능하다.
	vector<string> v1(10); // 값이 0인 요소가 10개인 vector로 초기화
#ifdef LIST_INIT
	vector<string> v2{ 10 }; // 10개의 string 객체를 기본 초기화한 vector (목록 초기화 방식)
#else
	vector<string> v2(10);
#endif
	vector<string> v3(10, "hi");  // 10개의 string 객체를 "hi"로 초기화
#ifdef LIST_INIT
	// again list initialization is not viable, so ordinary construction
	vector<string> v4{ 10, "hi" };  // 10개의 string 객체를 "hi"로 초기화 (목록 초기화 방식)
#else
	vector<string> v4(10, "hi");  // 10개의 string 객체를 "hi"로 초기화
#endif

	// 위에서 초기화한 벡터는 모두 size가 10
	cout << v1.size() << " " << v2.size() << " " << v3.size() << " " << v4.size() << endl;

#ifdef LIST_INIT // 목록 초기화를 하는 경우
	vector<string> vs1{ "hi" }; // "hi"라는 요소 1개만 갖는 vector 
	vector<string> vs2{ 10 };   // 10개의 string 객체를 기본 초기화한 값을 가지는 vector
	vector<string> vs3{ 10, "hi" }; // 10개의 string 객체를 "hi"로 초기화
#else // 목록 초기화를 하지 않는 경우 (지원하지 않는 컴파일러의 경우)
	vector<string> vs1;
	vs1.push_back("hi"); // push_back을 통해 vector의 가장 마지막(end)에 요소를 추가. 
	vector<string> vs2(10); // 10개의 string 객체를 기본 초기화한 값을 가지는 vector
	vector<string> vs3(10, "hi"); // 10개의 string 객체를 "hi"로 초기화
#endif
	cout << vs1.size() << " " << vs2.size() << " " << vs3.size() << endl;

	vector<int> v5(10, 1);  // 10개의 요소를 1로 초기화
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우
	vector<int> v6{ 10, 1 };  // 10과 1 두 개의 요소를 갖는 vector
#else // 목록 초기화를 사용하지 않는 경우
	vector<int> v6;
	v6.push_back(10);
	v6.push_back(1);
#endif
	cout << v5.size() << " " << v6.size() << endl;

#ifdef LIST_INIT // 목록 초기화를 사용하는 경우
	// string때와 달리 확실하게 구분할 수 있다.
	vector<int> alt_v3 = { 10 };    // 10을 요소로 갖는 vector
	vector<int> alt_v4 = { 10, 1 }; // 10과 1을 요소로 갖는 vector
#else // 목록 초기화를 사용하지 않는 경우
	vector<int> alt_v3;
	alt_v3.push_back(10);    // 10을 요소로 갖는 vector

	vector<int> alt_v4;
	alt_v4.push_back(10);
	alt_v4.push_back(1); // 10과 1을 요소로 갖는 vector
#endif
	cout << alt_v3.size() << " " << alt_v4.size() << endl;

	return 0;
}