/*
* C++ Primer - String, Vector & Array (문자열, 벡터 그리고 배열)
* 파일명: cstring_hdr.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-02
* 이전 버전 작성 일자:
* 버전 내용: 배열(Array) 사용 예제(2) - C언어 형식 문자열 다루기
* 이전 버전 내용:
*/

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <cstring>

#include <cstddef>
using std::size_t;

int main(int argc, const char* argv[])
{
	// C++의 string 클래스 문자열
	string s1 = "A string example";
	string s2 = "A different string";

	// string을 비교
	// 사전 편찬 순서로 비교하게 되면 s > d가 되므로 s2가 작음
	if (s1 < s2)
		cout << s1 << endl;
	else
		cout << s2 << endl;

	// C 형식 문자열 -> 마지막에 '\0'을 포함
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";

	// ca1 < ca2와 같은 비교는 의미가 없음 -> 포인터 비교 연산이 되어버림
	// C에서 strcmp를 사용했던 것을 생각하면 됨.
	// 마찬가지로 사전 편찬 순서로 비교. cp1이 사전 편찬 순서상 더 큼
	if (strcmp(ca1, ca2) < 0)
		cout << ca1 << endl;
	else
		cout << ca2 << endl;

	// 문자열 배열은 다음과 같이 포인터로 접근할 수도 있음. -> C에서 이미 알고 있던 개념 
	const char* cp1 = ca1;
	const char* cp2 = ca2;

	// 비교 대상에 대해서 첫번째 인자가 크면 양수를, 두 번째 인자가 더 크면 음수를 반환
	// 그리고 완벽히 동일한 문자열이면 0을 반환
	cout << strcmp(cp1, cp2) << endl; // 양수 반환
	cout << strcmp(cp2, cp1) << endl; // 음수 반환
	cout << strcmp(cp1, cp1) << endl; // 0 반환

	cout << strlen(cp1) << endl; // 문자열의 길이 반환, (널 문자는 제외)

	const unsigned sz = 16 + 18 + 2; // ca1이 16, ca2는 18, 마지막으로는 2를 더 추가한 것은 문자열만큼 '\0'을 고려한 것으로 보임
	char largeStr[sz]; // 모든 문자열을 합치기 위한 char형 배열

	// VS 컴파일러가 좀 까다롭게 구는데, 버퍼 오버플로우 방지 차원에서 사용하게 된다.
	// 버퍼에 문자열을 복사하거나 이어붙일 때 대상 문자열보다 버퍼가 작으면 버퍼 오버플로우가 발생.
	// 해당 오류를 방지하는 차원에서 _s를 붙인 함수를 사용하기를 권장한다.
	// 맨 처음에는 strcpy를 통해 문자열을 복사.
	strcpy_s(largeStr, ca1);
	// 그 이후에는 이전의 문자열에 연결한다. (concatenate -> strcat)
	strcat_s(largeStr, " "); 
	strcat_s(largeStr, ca2);

	cout << largeStr << endl; // 합쳐진 문자열을 출력.

	// strncpy와 strncat을 사용하는 경우
	// 문자열에 대한 계산을 해야하므로 훨씬 까다로워진다.
	// 그래서 C++에서는 문자열 처리를 string 클래스를 사용하라고 적극 권장한다.
	strncpy_s(largeStr, ca1, sz); // 세 번째 인자 크기만큼 문자열을 복사
	
	// 해당 if문을 수행하는 이유는 strncpy는 strcpy와 달리 문자열의 마지막에 '\0'(널 문자)에 대한 처리를 하지 않는다.
	// 그래서 굉장히 주의해야 한다.
	// 여기서는 ca1의 문자열 길이가 sz보다 클 경우를 확인한다.
	// 크게 될 경우에는 마지막에 '\0' 처리를 하지 못하게 되므로 문자열이 안끝나는 경우가 생긴다.
	// 그래서 위와 같은 경우일 때에 복사 대상의 버퍼의 마지막 인덱스에 '널 문자'\0' 처리를 한다.
	if (strlen(ca1) > sz)
		largeStr[sz - 1] = '\0';


	strncat_s(largeStr, " ", 2); // 빈 문자열을 하나만 붙이는 것이지만, 저자는 이것이 좋은 습관이라고 한다.
	// 마지막으로 남은 문자열을 연결한다.
	// 버퍼 크기에서 현재까지 입력된 문자열의 길이만큼 뺀 부분만 넣으면 딱 맞는다.
	strncat_s(largeStr, ca2, sz - strlen(largeStr)); 
	cout << largeStr << endl;

	// 좀 웃기는 부분인데, string 클래스를 이용하면 이 단 한줄로 위의 지랄맞은 과정이 모두 정리된다.
	string large_string = s1 + " " + s2;
	cout << large_string << endl;

	return 0;
}