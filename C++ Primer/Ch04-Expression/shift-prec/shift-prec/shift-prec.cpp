/*
* C++ Primer - Expression (표현식)
* 파일명: shift-prec.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: 출력 표현식에서 조건 연산자(3항 연산자) 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int grade = 75;
	// 조건 연산자 (3항 연산자 (조건식?:표현식1:표현식2) 사용)
	cout << ((grade < 60) ? "fail" : "pass");
	cout << endl;
	// 마찬가지로 조건 연산자(3항 연산자) 사용, 그러나 결과는 위와 다르다
	// 3항 연산자의 우선순위는 낮기 때문에 위와 달리 출력으로는 grade < 60에 대한 bool값을 출력하는 것
	cout << (grade < 60) ? "fail" : "pass";
	cout << endl;

	// 위의 과정을 풀어나가면 아래와 같이 된다.
	cout << (grade < 60); // 여기서 bool값을 출력하고
	// cout이 조건식이 되어버린 상황.
	// cout이 true인지 false인지에 따라 둘 중 하나를 반환한다 -> 사실상 의미없는 문장이 되어버린 것
	cout ? "fail" : "pass"; 
	cout << endl;

	// 이번에는 두 수를 가지고 든 예시
	int i = 15, j = 20;
	// 문제가 없다면 i가 출력된다.
	cout << (i < j ? i : j);
	cout << endl;

	// 앞서 괄호를 씌우지 않아 결과가 0과 1중 하나가 출력된다.
	cout << (i < j) ? i : j;
	cout << endl;

	// 위의 과정을 풀어나간 것.
	// 동일하므로 별도 주석은 필요 없다고 본다.
	cout << (i < j);
	cout ? i : j;
	cout << endl;

	return 0;
}