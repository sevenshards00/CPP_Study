/*
* C++ Primer - Introduction (서론)
* 파일명: Sales_item.h
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2024-01-12
* 이전 버전 작성 일자: 2024-01-09
* 버전 내용: using 선언 제거
* 이전 버전 내용: sort에 사용하기 위한 compareIsbn 함수 수정
*/

// 헤더파일에 대한 개념이 없다면 이 파일은 일단 있어야 컴파일이 가능하다는 것만 알아두면 됩.
// 클래스에 대한 자세한 개념은 추후에 설명.
#ifndef __SALES_ITEM_H__
#define __SALES_ITEM_H__

// 헤더 파일에서 사용될 함수들을 사용할 헤더파일 include
#include <iostream>
#include <cstring>

// 개인적인 생각으로는 멤버 함수들에 대해서도 별도로 소스코드로 따로 떼어서 놓고 싶음.
// 분할 파일 컴파일에 대한 개념이 있다면 어렵지 않으므로 일단은 헤더 파일을 그대로 쓰는 것으로.
class Sales_item
{
    // 현재는 이 헤더파일을 봐도 이해가 안되는 것들이 산더미 같을 것.
    // 클래스와 연산자 오버로딩과 관련이 있는 부분
    friend std::istream &operator>>(std::istream &, Sales_item &);
    friend std::ostream &operator<<(std::ostream &, const Sales_item &);
    friend bool operator<(const Sales_item &, const Sales_item &);
    friend bool operator==(const Sales_item &, const Sales_item &);
public:
    // 기본 생성자와 소멸자 관련된 부분.
    // 클래스와 관련해서 다룰 부분이다.
    // 조건부 컴파일을 통해서 별도로 처리
#if defined(IN_CLASS_INITS) && defined(DEFAULT_FCNS)
    Sales_item() = default;
#else
    Sales_item() : units_sold(0), revenue(0.0) { }
#endif
    Sales_item(const std::string &book) :
        bookNo(book), units_sold(0), revenue(0.0) { } // 멤버 이니셜라이저를 이용한 생성자 초기화
    Sales_item(std::istream &is) { is >> *this; }
public:
    // 마찬가지로 연산자 오버로딩
    Sales_item &operator+=(const Sales_item &);

    // 엑세스 함수들 (Getter, Setter)
    std::string isbn() const { return bookNo; }
    double avg_price() const;

    // private, public은 클래스에서 다룰 개념. (캡슐화)
private:
    std::string bookNo;      // 암묵적으로 빈 string으로 초기화
#ifdef IN_CLASS_INITS
    unsigned units_sold = 0; // 명시적으로 초기화 할 경우
    double revenue = 0.0;
#else
    unsigned units_sold;
    double revenue;
#endif
};

// 인라인 함수
inline bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
    // return lhs.isbn() == rhs.isbn(); // 원래는 isbn이 같은가를 확인하기 위해 사용했던 함수
    return lhs.isbn() < rhs.isbn(); // 오름차순
    // return lhs.isbn() > rhs.isbn(); // 내림차순
}

// 단항 연산자 +의 경우
Sales_item operator+(const Sales_item &, const Sales_item &);

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    // friend 선언을 통해서 오버로딩해야 하는 경우가 있는데, 추후에 복습하면서 확인할 부분
    return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue && lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    return !(lhs == rhs); // 위에서 == 연산자에 대한 오버로딩한 것을 그대로 이용함
}

// += 연산자에 대한 오버로딩
// 같은 ISBN을 가진 객체끼리 해당 연산을 한다고 가정
Sales_item &Sales_item::operator+=(const Sales_item &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// + 연산자에 대한 오버로딩
// 같은 ISBN을 가진 객체끼리 해당 연산을 한다고 가정
Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs)
{
    Sales_item ret(lhs);  // copy (|lhs|) into a local object that we'll return
    ret += rhs;           // add in the contents of (|rhs|) 
    return ret;           // return (|ret|) by value
}

// >> 연산자 오버로딩
std::istream &operator>>(std::istream &in, Sales_item &s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // 입력 값에 대해 검사
    if (in)
        s.revenue = s.units_sold * price; // 입력 값이 맞게 들어왔다면
    else
        s = Sales_item();  // 입력 값이 맞게 들어오지 않았다면 디폴트 생성자를 통해 생성
    return in;
}

// << 연산자 오버로딩
std::ostream &operator<<(std::ostream &out, const Sales_item &s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

#endif