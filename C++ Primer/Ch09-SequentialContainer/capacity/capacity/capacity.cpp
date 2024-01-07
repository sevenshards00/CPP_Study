/*
* C++ Primer - Sequential Container (순차 컨테이너)
* 파일명: capacity.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-07
* 이전 버전 작성 일자:
* 버전 내용: size와 capacity의 차이 확인
* 이전 버전 내용:
*/

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
	vector<int> ivec; // 빈 vector

	// 기본적으로 capacity >= size라는 개념을 알고 있어야 한다.
	// size는 실제 vector에 들어가 있는 요소의 개수
	// capacity는 vector가 추가로 공간을 할당하기 전까지 담을 수 있는 요수의 개수를 말한다.
	// 쉽게 생각하면 500ML 물병이 capacity면, 물이 300ML가 차 있을때 이게 size다.
	
	// 빈 vector이므로 size와 capacity 모두 0
	cout << "ivec의 size: " << ivec.size() << " ivec의 capacity: " << ivec.capacity() << endl;

	// vector에 요소 24개를 추가.
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);

	// vecotr의 size는 24. capacity는 개인차가 있을 수 있으나 size보다는 크거나 같을 수 있다.
	cout << "ivec의 size: " << ivec.size() << " ivec의 capacity: " << ivec.capacity() << endl;

	ivec.reserve(50); // capacity를 50으로 변경
	// size는 그대로 24, capacity는 50으로 출력된다.
	cout << "ivec의 size: " << ivec.size() << " ivec의 capacity: " << ivec.capacity() << endl;

	// capacity만큼 vector에 요소를 채운다.
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);

	// size와 capacity 모두 50
	cout << "ivec의 size: " << ivec.size() << " ivec의 capacity: " << ivec.capacity() << endl;
	ivec.push_back(42); // 이 상태에서 42를 vector에 추가

	// size는 51, capacity는 넉넉하게 추가 된 수치가 나옴.
	cout << "ivec의 size: " << ivec.size() << " ivec의 capacity: " << ivec.capacity() << endl;

	// 메모리 관리 차원에서 쓰는 vector의 멤버 함수
	// 현재 size에 맞게 capacity도 딱 맞춘다.
	// 다만, 이것은 요청일 뿐이므로 size에 딱 맞추지 않을 수도 있다.
	ivec.shrink_to_fit();

	// 결과를 확인
	cout << "ivec의 size: " << ivec.size() << " ivec의 capacity: " << ivec.capacity() << endl;

	return 0;
}