/*
* C++ Primer - Class (클래스)
* 파일명: Account.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자: 2024-01-06
* 버전 내용: using 선언 제거
* 이전 버전 내용: static 클래스 멤버 예제 - 헤더 파일
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#define IN_CLASS_INITS // 클래스 내 초기화를 사용
#define CONSTEXPR_VARS // C++11 이후 표준 상수 표현식(constexpr) 사용
#define DEFAULT_FCNS // C++11 이후 표준 기본 생성자 (=default) 사용 여부

#include <string>

class Account
{
private:
    std::string owner;
#ifdef IN_CLASS_INITS // 클래스 내 초기화를 사용할 경우
    double amount = 0.0;
#else
    double amount;
#endif
    static double interestRate;
    static double initRate() { return .0225; }
    static const std::string accountType;
#ifdef CONSTEXPR_VARS // C++11 이후 표준 상수 표현식(constexpr) 사용
    static constexpr int period = 30;// period는 상수 표현식
#else
    static const int period = 30;// period는 상수 표현식
#endif
    double daily_tbl[period];

public:
#if defined(DEFAULT_FCNS) && defined(IN_CLASS_INITS) // C++11 표준 적용
    Account() = default; // 기본 생성자
#else // C++11 표준 미적용
    Account() : amount(0.0) { } // 기본 생성자
#endif
    Account(const std::string& s, double amt) :
        owner(s), amount(amt) { }

    // 멤버 함수
    void calculate() { amount += amount * interestRate; }
    double balance() { return amount; }

    static double rate() { return interestRate; }
    static void rate(double);

};
#endif
