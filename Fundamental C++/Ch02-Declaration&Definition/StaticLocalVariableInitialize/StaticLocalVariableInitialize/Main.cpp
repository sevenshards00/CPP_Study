/*
* Fundamental C++ - Ch02-Declaration&Definition
* 파일명: Main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-21
* 이전 버전 작성 일자:
* 버전 내용: 정적 지역 변수 초기화 과정
* 이전 버전 내용:
*/

int GetOne()
{
	return 1;
}

// 상수로 정적 지역 변수 초기화한 경우 - data 영역
void Func1()
{
	/*
		Assembly 내에서의 함수 프롤로그
		push        ebp
		mov         ebp,esp
	*/
	
	static int s_Val1 = 1;	// 정적 변수에 대한 Assembly가 확인되지 않음 -> 프로세스를 시작하면서 생성되고 초기화되었기 때문.
	
	/*
		Assembly 내에서의 함수 에필로그
		pop         ebp
		ret
	*/
}

// 함수를 통해 정적 지역 변수를 초기화한 경우 - bss 영역
void Func2()
{
	/*
		Assembly 내에서의 함수 프롤로그
		push        ebp
		mov         ebp,esp
	*/
	static int s_Val2 = GetOne();
	/*
		VS2022 기준 VC++ 컴파일러에서 나오는 Assembly
		mov         eax,dword ptr fs:[0000002Ch]  
		mov         ecx,dword ptr [eax]  
		mov         edx,dword ptr [$TSS0 (034340Ch)]
		cmp         edx,dword ptr [ecx+4]
		jle         Func2+73h (0341093h)
		push        offset $TSS0 (034340Ch)  
		call        _Init_thread_header (034114Bh)  
		add         esp,4  
		cmp         dword ptr [$TSS0 (034340Ch)],0FFFFFFFFh  
		jne         Func2+73h (0341093h)  
		mov         dword ptr [ebp-4],0  
		call        GetOne (0341000h)  
		mov         dword ptr [s_Val2 (0343410h)],eax  
		mov         dword ptr [ebp-4],0FFFFFFFFh  
		push        offset $TSS0 (034340Ch)  
		call        _Init_thread_footer (03410FAh)  
		add         esp,4 
	*/

	/*
		Assembly 내에서의 함수 에필로그
		pop         ebp
		ret
	*/
}

int main()
{	
	/*
		Assembly 내에서의 함수 프롤로그
		push        ebp
		mov         ebp,esp
	*/

	Func1();	// call Func1()
	
	Func2();	// call Func2()
	
	return 0; // return 0은 eax를 xor해서 0으로 만들고 eax 값을 return한다.
	/*
		Assembly 내에서의 함수 에필로그
		xor         eax,eax		-> 이 부분이 return 0;
		pop         ebp			-> 함수의 유효범위(중괄호)를 벗어난 이후
		ret
	*/
}