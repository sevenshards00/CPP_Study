/*
* C++ Primer - I/O Library (I/O 라이브러리)
* 파일명: sstream.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-06
* 이전 버전 작성 일자:
* 버전 내용: string 스트림 사용 예제
* 이전 버전 내용:
*/

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::istream;
using std::ostream;
using std::endl;

#include <sstream>
using std::ostringstream;
using std::istringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

// struct -> 모든 멤버가 기본적으로 public
struct PersonInfo
{
	string name;
	vector<string> phones;
};

// 굉장히 뒤에서 다룰 내용이지만 string의 포맷을 다시 정하는 것은 17챕터에서
// 여기서는 입력받은 string을 다시 반환하는 것으로.
string format(const string& s)
{
	return s;
}

// 마찬가지로 굉장히 뒤에서 다룰 내용
// 입력받은 전화번호의 유효성 검사는 17챕터에서
// 여기서는 true를 반환하는 것으로.
bool valid(const string& s)
{
	return true;
}

vector<PersonInfo> getData(istream& is)
{
	// 입력 받은 문자열을 각각 한 줄과 단어로 저장하기 위한 변수
	string line, word;
	// 입력에서 읽어들인 전체 레코드를 담을 변수
	vector<PersonInfo> people;

	while (getline(is, line))
	{
		PersonInfo info; // 현재 레코드의 데이터를 담을 객체
		istringstream record(line); // 방금 읽어들인 line을 istringstream에 결합(bind)
		record >> info.name; // record에서 첫 문자열을 읽어들인다 -> 이름
		while (record >> word) // 이름 다음의 전화번호를 차례대로 읽어들인다.
			info.phones.push_back(word); // 읽어들인 전화번호를 저장한다.
		people.push_back(info); // 다 읽어들인 내용을 people vector에 저장한다.
	}

	return people;
}

ostream& process(ostream& os, vector<PersonInfo> people)
{
	for (const auto& entry : people) // 범위 for문을 이용하여 vector의 요소에 접근
	{
		ostringstream formatted, badNums; // 반복문 내에서 생성할 ostringstream 객체
		for (const auto& nums : entry.phones) // 전화번호 또한 vector이므로 범위 for문을 사용하여 vector의 요소에 접근
		{
			if (!valid(nums)) // 현재 유효성 검사는 의미가 없으나, 유효성 검사를 수행
				badNums << " " << nums; // 출력 버퍼 badNums에 유효하지 않은 번호를 넣는다.
			else // 유효성 검사에서 문제가 없다면
				formatted << " " << format(nums); // format함수를 통해 전화번호 포맷에 맞춰서 출력 버퍼 formatted에 넣는다.
		}
		if (badNums.str().empty()) // 잘못된 번호가 하나도 없다면
			os << entry.name << " " << formatted.str() << endl; // 콘솔에 출력한다.
		else // 잘못된 번호가 하나라도 있다면
			// 그 사람의 이름과 잘못된 번호를 출력
			cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
	}

	return os;
}

int main(int argc, const char* argv[])
{
	process(cout, getData(cin));

	return 0;
}