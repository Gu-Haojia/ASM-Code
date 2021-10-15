#include <iostream>
using namespace std;

int main()
{
	char in1[100];
	char in2[100];
	char out1[100];
	char out2[100];


	cin >> in1;
	cin >> in2;


	_asm {


		LEA EAX, out2
		PUSH EAX
		LEA EAX, out1
		PUSH EAX
		LEA EAX, in2
		PUSH EAX
		LEA EAX, in1
		PUSH EAX

		CALL PROCESS   //call function

		POP EAX
		POP EAX
		POP EAX
		POP EAX


	}
	cout << "add:" << out1 << endl;
	cout << "sub:" << out2 << endl;



	return  0;
	_asm {
	PROCESS:
			PUSH EBP
			MOV EBP, ESP
			SUB ESP, 8
			PUSH EDI

			MOV EBX, [EBP + 8]   
			XOR EAX, EAX

			JUDGE1:
			CMP[EBX],' '
			JNZ TOINT1
			INC EBX
			JMP JUDGE1



			TOINT1 :
			CMP[EBX], 0
			JZ END1
			MOV ECX, 16
			MUL ECX
			XOR EDX, EDX
			MOV DL, [EBX]

			CMP DL,'9'
			JA DEC1

			SUB DL, '0'
			JMP F1

			DEC1:
			SUB DL,'A'
			ADD DL,10

			F1:
			ADD EAX, EDX
			INC EBX
			JMP TOINT1
			END1 :
			MOV[EBP - 4], EAX



			MOV EBX, [EBP + 12]     //toint
			XOR EAX, EAX

			JUDGE2:
			CMP[EBX], ' '
			JNZ TOINT2
			INC EBX
			JMP JUDGE2

			TOINT2 :
			CMP[EBX], 0
			JZ END2
			MOV ECX, 16
			MUL ECX
			XOR EDX, EDX
			MOV DL, [EBX]

			CMP DL, '9'
			JA DEC2

			SUB DL, '0'
			JMP F2

			DEC2 :
			SUB DL, 'A'
			ADD DL, 10

			F2:
			ADD EAX, EDX
			INC EBX
			JMP TOINT2
			END2 :
			MOV[EBP - 8], EAX



			MOV EAX, [EBP - 4]         
			MOV EDX, [EBP - 8]
			ADD EAX, EDX
			MOV EDI, [EBP + 16]
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

			CMP AL,10
			JAE S1
			ADD AL, '0'
			JMP SS1

			S1:
			SUB AL,10
			ADD AL,'A'

			SS1:
			MOV[EDI], AL
			INC EDI
			CMP ECX, 0
			JNZ TRANS
			MOV BYTE PTR[EDI], 0



			MOV EAX, [EBP - 4]     //����
			MOV EDX, [EBP - 8]
			SUB EAX, EDX
			MOV EDI, [EBP + 20]
			CMP EAX, 0
			JGE PASS
			MOV[EDI], '-'
			INC EDI
			NEG EAX
			PASS :
			XOR ECX, ECX
			NEXT2 :
			XOR EDX, EDX
			MOV EBX, 16
			DIV EBX
			INC ECX
			PUSH DX
			CMP EAX, 0
			JNZ NEXT2
			TRANS2 :
			POP AX
			DEC ECX
			CMP AL,10
			JAE S2
			ADD AL, '0'
			JMP SS2

			S2:
			SUB AL,10
			ADD AL,'A'

			SS2:
			MOV[EDI], AL
			INC EDI
			CMP ECX, 0
			JNZ TRANS2
			MOV BYTE PTR[EDI], 0



			POP EDI
			MOV ESP, EBP
			POP EBP
			RET
	}
}
