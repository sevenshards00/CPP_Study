/*
* C++ Primer - Associative Container (연관 컨테이너)
* 파일명: word_transform.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-10
* 이전 버전 작성 일자:
* 버전 내용: 간단한 단어 변환 프로그램
* 이전 버전 내용:
*/

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;
using std::getline;

#include <stdexcept>
using std::runtime_error;

// 파일을 통한 단어 변환 map 생성 함수
map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map; // 변환 규칙을 저장할 map
	string key;
	string value;

	while (map_file >> key && getline(map_file, value)) // 파일에서 단어를 하나 읽고, 나머지 내용을 한 줄로 읽어들인다.
		if (value.size() > 1) // value가 없으면 규칙을 잘못 정의한 것
			trans_map[key] = value.substr(1); // value 부분에는 한 칸 앞이 공백이므로 해당 부분을 지우고 value로 기록한다.
		else
			throw runtime_error("no rule for " + key); // 변환 규칙에 대한 문제가 있을 경우에 에러 발생
	return trans_map;
}

// 단어 변환을 수행하는 함수
const string &transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s); // 실질적으로 map을 사용하여 단어를 변환하는 부분
	if (map_it != m.cend()) // map에서 변환할 단어를 찾았는지 확인
		return map_it->second; // 찾았다면 단어를 해당 value로 변경
	else // 변환할 단어가 없다면
		return s; // 원래 단어를 그대로 출력한다.
}

// 단어 변환 처리 과정 전반을 수행하는 함수
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file); // 첫 번째 인자로 받은 파일로 단어 변환 map을 생성

	// 디버깅 목적으로 삽입한 코드, 실제로 파일을 받아서 단어 변환 map이 잘 생성되었는지 확인
	// 이 부분은 문제가 없다면 없어도 무방하다.
	cout << "Here is our transformation map: \n\n";
	for (auto entry : trans_map)
		cout << "key: " << entry.first << "\tvalue: " << entry.second << endl;
	cout << "\n\n";

	string text;
	while (getline(input, text)) // 파일에서 한 줄씩 읽어들인다.
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		// 띄어쓰기 처리를 위한 반복문
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";

			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, const char *argv[])
{
	if (argc != 3) // 전달 받은 인자가 3개가 아니라면
		throw runtime_error("wrong number of arguments");

	ifstream map_file(argv[1]); // 단어 변환 규칙 파일을 개방하는 스트림 
	if (!map_file) // 파일 개방 성공 여부를 확인
		throw runtime_error("no transformation file");

	ifstream input(argv[2]); // 변환할 내용을 가진 파일을 개방하는 스트림
	if (!input) // 파일 개방 성공 여부를 확인
		throw runtime_error("no input file");

	// 단어 변환 수행
	word_transform(map_file, input);

	return 0;
}