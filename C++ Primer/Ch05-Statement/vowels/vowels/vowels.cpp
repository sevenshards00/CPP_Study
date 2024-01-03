/*
* C++ Primer - Statement (문장)
* 파일명: vowels.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-03
* 이전 버전 작성 일자:
* 버전 내용: switch-case 예제(1) - 모음 갯수 구하기
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
    // 각 모음 갯수를 카운팅할 변수 초기화
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    char ch;
    while (cin >> ch) {
        // 입력받은 문자가 모음이라면 카운트를 증가시킨다.
        switch (ch) {
        case 'a':
            ++aCnt;
            break;
        case 'e':
            ++eCnt;
            break;
        case 'i':
            ++iCnt;
            break;
        case 'o':
            ++oCnt;
            break;
        case 'u':
            ++uCnt;
            break;
        }
    }
    // 결과 출력
    cout << "Number of vowel a: \t" << aCnt << '\n'
        << "Number of vowel e: \t" << eCnt << '\n'
        << "Number of vowel i: \t" << iCnt << '\n'
        << "Number of vowel o: \t" << oCnt << '\n'
        << "Number of vowel u: \t" << uCnt << endl;

    return 0;
}