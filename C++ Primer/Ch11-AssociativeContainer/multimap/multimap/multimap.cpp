/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: multimap.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: multimap(또는 multiset)에서 요소를 찾는 예제
* 이전 버전 내용:
*/

#include <map>
using std::multimap;

#include <string>
using std::string;

#include <utility>
using std::pair;
using std::make_pair;

#include <iostream>
using std::cout;
using std::endl;

#define LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)

int main(int argc, const char *argv[])
{
    // 작가 이름과 제목을 key-value로 가지는 map
    // 작가 하나에 여러 작품들이 있을 수 있다.
    multimap<string, string> authors;
    // map authors에 데이터를 추가한다.
#ifdef LIST_INIT // 목록 초기화를 사용하는 경우 (C++11 표준 이상)
    authors.insert({ "Alain de Botton", "On Love" });
    authors.insert({ "Alain de Botton", "Status Anxiety" });
    authors.insert({ "Alain de Botton", "Art of Travel" });
    authors.insert({ "Alain de Botton", "Architecture of Happiness" });
    
    

 #else // 목록 초기화를 사용하지 않는 경우 (C++11 표준 미만)
    authors.insert(pair<string, string>("Alain de Botton", "On Love"));
    authors.insert(pair<string, string>("Alain de Botton", "Status Anxiety"));
    authors.insert(pair<string, string>("Alain de Botton", "Art of Travel"));
    authors.insert(pair<string, string>("Alain de Botton", "Architecture of Happiness"));
#endif

    // 또는 make_pair를 이용하여 데이터 추가를 할 수도 있다.
    authors.insert(make_pair("Molain de Special", "On Love"));
    authors.insert(make_pair("Molain de Special", "Status Anxiety"));
    authors.insert(make_pair("Molain de Special", "Art of Travel"));
    authors.insert(make_pair("Molain de Special", "Architecture of Happiness"));

    authors.insert({ "Blain de Cotton", "On Love" });
    authors.insert({ "Blain de Cotton", "Status Anxiety" });
    authors.insert({ "Blain de Cotton", "Art of Travel" });
    authors.insert({ "Blain de Cotton", "Architecture of Happiness" });

    string search_item1("Alain de Botton"); // 찾고자 하는 대상 Key "Alain de Botton"
    string search_item2("Molain de Special"); // 찾고자 하는 대상 Key "Molain de Special"
    string search_item3("Blain de Cotton"); // 찾고자 하는 대상 Key "Blain de Cotton"
    
    // multimap(또는 multiset)에서 요소를 찾는 방법 1 - 요소의 개수를 이용
    auto entries = authors.count(search_item1); // 요소의 개수
    auto iter = authors.find(search_item1); // 해당 저자를 key로 하는 첫 번째 요소를 가리키는 반복자

    // 대상 Key에 대한 요소의 개수만큼 반복을 수행 (for문을 써도 된다)
    while (entries)
    {
        cout << iter->first << " " << iter->second << endl; // 대상 key가 가지고 있는 value를 출력
        ++iter;     // 반복자를 다음 위치로 이동
        --entries;  // 요소keep track of how many we've printed
    }

    // multimap(또는 multiset)에서 요소를 찾는 방법 2 -  lower_bound & upper_bound
    // 컨테이너에 key가 있다면 lower_bound는 해당 key의 첫 인스턴스를 참조하는 반복자를 반환
    // 마찬가지로 컨테이너에 key가 있다면 upper_bound는 해당 key를 가리키는 마지막 인스턴스 다음을 참조하는 반복자를 반환
    // 이를 반복자를 이용한 begin, end처럼 사용할 수 있다.
    // 추가적으로 lower_bound와 upper_bound는 key가 없을 경우 지정 key의 요소가 아닌 것을 참조할 수도 있다.
    // 이 경우에는 컨테이너 내의 요소 순서를 유지하면서 해당 key를 삽입할 수 있는 첫 위치를 참조하게 된다.
    // lower_bound == upper.bound일 경우에는 해당 key에 대한 요소가 없음을 뜻한다.
    // 만약 찾고자 하는 요소의 key가 컨테이너 내에서 가장 크다면 upper_bound는 끝 지난 반복자(end)를 가리킨다.
    // 마찬가지로 컨테이너 내에 찾는 key가 없으면서 컨테이너 내에서 가장 크다면 lower_bound도 끝 지난 반복자(end)를 가리킨다.
    for (auto beg = authors.lower_bound(search_item2), end = authors.upper_bound(search_item2); beg != end; ++beg)
        cout << beg->first << " " << beg->second << endl;

    // multimap(또는 multiset)에서 요소를 찾는 방법 3 - equal_range
    // equal_range는 key를 인자로 취하며, 반복자 pair를 반환한다.
    // 컨테이너 내에 key가 존재한다면 pair의 첫 번째 반복자에는 해당 key의 첫 인스턴스를 참조하는 반복자를
    // pair의 두 번째 반복자는 해당 key의 마지막 인스턴스 바로 다음을 참조한다.
    // 함수를 두 번 호출할 필요 없이 한 번에 해결하는 방법.
    for (auto pos = authors.equal_range(search_item3); pos.first != pos.second; ++pos.first)
        cout << pos.first->first << " " << pos.first->second << endl;

    return 0;
}