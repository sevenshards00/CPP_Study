/*
* C++ Primer - Introduction (서론)
* 파일명: mysum.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-30
* 이전 버전 작성 일자:
* 버전 내용: C++ 맛보기 - EOF를 받기 전까지 입력받은 숫자 더하기
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	int sum = 0, value = 0;
	
	while (cin >> value) // EOF(Ctrl+C)를 입력받기 전까지 계속 입력을 받는다.
		sum += value;
	cout << "Sum is " << sum << endl;
	

	/*
	// EOF 개념을 모른다면 아래의 코드로 작성하는 것이 더 나을 수 있음
	// 음수를 입력받을 경우 반복을 종료.
	cin >> value;
	while (value > 0)
	{
		sum += value;
		cin >> value;
	}
	cout << "Sum is " << sum << endl;
	*/
	return 0;
}