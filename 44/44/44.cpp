#include <iostream>
using namespace std;

int main()
{
	int a;
	char out[100];
	cin >> a;

	
	_asm {
		MOV EAX,a
		
		XOR ECX,ECX
		NEXT:
		XOR EDX,EDX
		MOV EBX,16
		DIV EBX
		INC ECX
		PUSH DX
		CMP EAX,0
		JNZ NEXT

		LEA ESI,out

		TRANS:
		POP AX
		DEC ECX
		CMP AL,9
		JBE NEXT1
		SUB AL,10
		ADD AL,'A'
		JMP NEXT2

		NEXT1:
		ADD AL,'0'

		NEXT2:
		MOV [ESI],AL
		INC ESI
		CMP ECX,0
		JNZ TRANS

		MOV [ESI],0
	}

	cout << out << endl;


	return  0;
}
