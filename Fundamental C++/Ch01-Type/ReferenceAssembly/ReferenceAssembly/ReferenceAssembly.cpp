/*
* Fundamental C++ - Ch01-Type
* 파일명: ReferenceAssembly.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-19
* 이전 버전 작성 일자:
* 버전 내용: C++의 참조 타입 객체가 동작하는 과정을 어셈블리로 확인하는 예제
* 이전 버전 내용:
*/

int main()
{
	/*
	00931000  push        ebp  
	00931001  mov         ebp,esp  
	00931003  sub         esp,14h  
	00931006  mov         eax,dword ptr [__security_cookie (0933000h)]  
	0093100B  xor         eax,ebp  
	0093100D  mov         dword ptr [ebp-4],eax 
	*/
	
	int a = 1;
	int &ra = a;
	/*
	00931010  mov         dword ptr [a],1
	00931017  lea         eax,[a]  
	0093101A  mov         dword ptr [ra],eax
	*/
	const int &cra = 2;
	/*
	0093101D  mov         dword ptr [ebp-0Ch],2  
	00931024  lea         ecx,[ebp-0Ch]  
	00931027  mov         dword ptr [cra],ecx
	*/

	return 0;
	/*
	0093102A  xor         eax,eax   
	*/
}
/*
0093102C  mov         ecx,dword ptr [ebp-4]
0093102F  xor         ecx,ebp
00931031  call        __security_check_cookie (093103Ah)
00931036  mov         esp,ebp
00931038  pop         ebp
00931039  ret
*/