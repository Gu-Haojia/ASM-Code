#include <iostream>
using namespace std;
int main() {
	int add;
	char str1[100], str2[100];
	cin >> str1 >> str2;
	_asm {
		LEA EBX,str1
		LEA EDI,str2
		XOR ECX,ECX
		MOV ESI,EBX
		JMP START
		
		NEXT:
		INC EBX
		MOV ESI,EBX
		INC ECX
		
		START:
		MOV AL,[EBX]
		CMP AL,0
		JZ ENDN

		NEXT1:
		MOV AL,[ESI]
		MOV DL,[EDI]
		CMP DL,0
		JZ ENDF
		CMP AL,DL
		JNZ NEXT
		INC ESI
		INC EDI
		JMP NEXT1

		ENDN:
		MOV ECX,-1
		MOV add,ECX

		ENDF:
		MOV add,ECX

	}

	cout << add << endl;






	return 0;

}