#include <iostream>
using namespace std;

int main()
{
	char in[100];
	char out[100];

	cin >> in;


	_asm {
		LEA EAX,in
		LEA EDX,out
		CALL PROCESS
	}
	cout << out << endl;


	return  0;
	_asm {
	PROCESS:

			PUSH EDX
			MOV EBX,EAX
			XOR EAX,EAX

			TOINT:
			CMP [EBX], 0
			JZ END

			MOV ECX,10
			MUL ECX
			XOR EDX, EDX
			MOV DL, [EBX]
			SUB DL,'0'
			ADD EAX,EDX
			INC EBX
			JMP TOINT

			END:
			POP ESI

			XOR ECX, ECX
			NEXT :
			XOR EDX, EDX
			MOV EBX, 16
			DIV EBX
			INC ECX
			PUSH DX
			CMP EAX, 0
			JNZ NEXT


			TRANS :
			POP AX
			DEC ECX
			CMP AL, 9
			JBE NEXT1
			SUB AL, 10
			ADD AL, 'A'
			JMP NEXT2

			NEXT1 :
			ADD AL, '0'

			NEXT2 :
			MOV[ESI], AL
			INC ESI
			CMP ECX, 0
			JNZ TRANS

			MOV[ESI], 0


		RET

	}
}
