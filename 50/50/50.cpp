#include <iostream>
using namespace std;

int main()
{
	char in1[100];
	char in2[100];
	char out1[100];
	char out2[100];
	char out3[100];

	cin >> in1;
	cin >> in2;


	_asm {

		LEA EAX, out3
		PUSH EAX
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
		POP EAX

	}
	cout <<"add:"<< out1 << endl;
	cout <<"sub:"<< out2 << endl;
	cout << "mul:"<<out3 << endl;


	return  0;
	_asm {
	PROCESS:
		PUSH EBP
		MOV EBP, ESP
		SUB ESP,8
		PUSH EDI

		MOV EBX, [EBP + 8]   //处理第一个int
		XOR EAX, EAX
		TOINT1 :
		CMP[EBX], 0
		JZ END1
		MOV ECX, 10
		MUL ECX
		XOR EDX, EDX
		MOV DL, [EBX]
		SUB DL, '0'
		ADD EAX, EDX
		INC EBX
		JMP TOINT1
		END1 :
		MOV [EBP-4],EAX
		


		MOV EBX, [EBP + 12]     //处理第二个int
		XOR EAX, EAX
		TOINT2 :
		CMP[EBX], 0
		JZ END2
		MOV ECX, 10
		MUL ECX
		XOR EDX, EDX
		MOV DL, [EBX]
		SUB DL, '0'
		ADD EAX, EDX
		INC EBX
		JMP TOINT2
		END2 :
		MOV [EBP-8],EAX
		


		MOV EAX,[EBP-4]         //加法
		MOV EDX,[EBP-8]
		ADD EAX,EDX 	
		MOV EDI,[EBP+16]
		XOR ECX, ECX
		NEXT :
		XOR EDX, EDX
		MOV EBX, 10
		DIV EBX
		INC ECX
		PUSH DX
		CMP EAX, 0
		JNZ NEXT
		TRANS :
		POP AX
		DEC ECX
		ADD AL, '0'
		MOV [EDI], AL
		INC EDI
		CMP ECX, 0
		JNZ TRANS
		MOV BYTE PTR[EDI], 0



		MOV EAX,[EBP - 4]     //减法
		MOV EDX,[EBP - 8]
		SUB EAX, EDX          
		MOV EDI, [EBP + 20]
		CMP EAX,0
		JGE PASS
		MOV [EDI],'-'
		INC EDI
		NEG EAX
		PASS:
		XOR ECX, ECX
		NEXT2 :
		XOR EDX, EDX
		MOV EBX, 10
		DIV EBX
		INC ECX
		PUSH DX
		CMP EAX, 0
		JNZ NEXT2
		TRANS2 :
		POP AX
		DEC ECX
		ADD AL, '0'
		MOV [EDI], AL
		INC EDI
		CMP ECX, 0
		JNZ TRANS2
		MOV BYTE PTR[EDI], 0



		MOV EAX, [EBP - 4]    //乘法
		MOV EDX, [EBP - 8]
		MUL EDX          
		MOV EDI, [EBP + 24]
		XOR ECX, ECX
		NEXT3 :
		XOR EDX, EDX
		MOV EBX, 10
		DIV EBX
		INC ECX
		PUSH DX
		CMP EAX, 0
		JNZ NEXT3
		TRANS3 :
		POP AX
		DEC ECX
		ADD AL, '0'
		MOV[EDI], AL
		INC EDI
		CMP ECX, 0
		JNZ TRANS3
		MOV BYTE PTR[EDI], 0



	    POP EDI
		MOV ESP,EBP
		POP EBP
		RET
	}
}
