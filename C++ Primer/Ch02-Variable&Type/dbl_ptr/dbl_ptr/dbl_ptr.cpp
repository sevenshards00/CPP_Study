/*
* C++ Primer - Variable & Types (변수와 기본 타입)
* 파일명: dbl_ptr.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-12-31
* 이전 버전 작성 일자:
* 버전 내용: 포인터의 포인터에 대한 예제(이중 포인터)
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int ival = 1024;
    int* pi = &ival;   // pi -> ival
    int** ppi = &pi;   // ppi -> pi -> ival
    cout << "The value of ival\n"
        << "direct value: " << ival << "\n" // 직접 접근한 경우
        << "indirect value: " << *pi << "\n" // 포인터를 통해 역참조하여 접근한 경우
        << "doubly indirect value: " << **ppi // 포인터의 포인터(이중 포인터)를 통해 역참조하여 접근한 경우
        << endl;

    int i = 2;
    int* p1 = &i;     // p1 -> i
    *p1 = *p1 * *p1;  // 해당 연산은 i = i * i를 한 것과 같다.
    cout << "i  = " << i << endl;

    *p1 *= *p1;       // 해당 연산은 i *= i를 한 것과 같다.
    cout << "i  = " << i << endl;

    return 0;
}